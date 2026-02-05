#!/bin/bash

# =============================================================================
# build.sh - A small and simple API for small C projects using gcc 
#
# Author: Joan Térmens (https://github.com/JTermens)
# Last update: 05 Feb 2026
# =============================================================================

HELP=$(cat <<-EOF
build.sh — C build helper for small projects using gcc

USAGE
  build.sh <mode> <target> [options]

DESCRIPTION
  build.sh is a lightweight build interface for compiling C code using gcc.
  It defines a small set of build modes, each mapping to a predefined group
  of compiler flags, and produces a single executable per target.

  The script is intended for small, structured C projects and enforces
  explicit build conventions.

MODES
  debug
    Compile with debug symbols and strict diagnostics.
    Flags:
      -ggdb
      -pedantic
      -Werror
      -Wno-error=pedantic

  release
    Compile with optimizations enabled.
    Flags:
      -O2
      -DNDEBUG

  Common flags applied to all modes:
    -std=c23
    -Wall
    -Wextra
    -Wconversion
    -Wsign-conversion

TARGETS
  Targets must be paths relative to /workspace/src.

  A target may be either:

  1) A single C source file:
       path/file.c
     Output:
       /workspace/build/<mode>/path/file

  2) A directory:
       path/folder
     All .c files inside the directory are compiled into a single executable.
     Output:
       /workspace/build/<mode>/path/folder/folder

OPTIONS
  -m, --munit
      Include /workspace/munit/munit.c in the compilation.
      This enables writing and running tests using the munit framework.

  -h, --help
      Display this help message and exit.

ERRORS
  Invalid modes, targets, or options result in an error message followed by
  this help text.
EOF
)

HELP_MESSAGE = "See build.sh --help for the documentation" 

COMMON_CFLAGS=(-std=c23 -Wall -Wextra -Wconversion -Wsign-conversion)
RELEASE_CFLAGS=(-O2 -DNDEBUG)
DEBUG_CFLAGS=(-ggdb -pedantic -Werror -Wno-error=pedantic)

set -eou pipefail

MUNIT=0
POSITIONAL=()

# Parse args
while [[ $#  -gt 0 ]]; do
    case "$1" in
        -h|--help)
            echo "$HELP"
            exit 0
            ;;
        -m|--munit)
            MUNIT=1
            shift
            ;;
        --)
            shift
            break
            ;;
        -*)
            echo "Unknown option: '$1'" >&2
            echo "Known options: --help, -h, --munit, -m" >&2
            echo "$HELP_MESSAGE" >&2
            exit 2
            ;;
        *)
            POSITIONAL+=("$1")
            shift
            ;;
    esac
done

set -- "${POSITIONAL[@]}"

# Warn if more than two positional arguments
if [[ $# -gt 2 ]]; then
    echo "More arguments than a mode and a target" >&2
    echo "Only the first two will be used" >&2
# Abort if less than two.
elif [[ $# -lt 2 ]]; then
    echo "There must be two arguments, a mode and a target"
    echo "$HELP_MESSAGE" >&2
    exit 2
fi


# Validate mode
MODE="${1:-}"

case "$MODE" in
    debug)
        MODE_CFLAGS="$DEBUG_CFLAGS"
        ;;
    release)
        MODE_CFLAGS="$RELEASE_CFLAGS"
        ;;
    *)
        echo "Invalid mode:'$MODE'" >&2
        echo "Allowed modes: debug, release" >&2
        echo "$HELP_MESSAGE" >&2
        exit 2
        ;;
esac


# Resolve target
TARGET="${2:-}"

SRC_ROOT="/workspace/src"
TARGET_PATH="$SRC_ROOT/$TARGET"

OUT_ROOT="/workdir/build"
OUTPUT="$OUT_ROOT/$MODE"

if [[ ! -e "$TARGET_PATH" ]]; then
    echo "Target not found: $TARGET" >&2
    echo "$HELP_MESSAGE" >&2
    exit 2
fi

# Determine the target type (file or directory)
# Find the .c files & create the output structure
if [[ -f "$TARGET_PATH" ]]; then
    
    #Target type: file
    [[ "$TARGET_PATH" == *.c ]] || {
        echo "Target file must be a .c file" >&2
        echo "$HELP_MESSAGE" >&2
        exit 2
    }
    SOURCES=("$TARGET_PATH")

    OUTPUT+="/${TARGET%.c}"

elif [[ -d "$TARGET_PATH" ]]; then
    
    #Target type: dir
    mapfile -t SOURCES < <(fins "$TARGET_PATH" -maxdepth=1 -name '*.c' | sort)

    if [[ ${#SOURCES[@]} -eq 0 ]]; then
        echo "No .c files found in the target directory" >&2
        echo "$HELP_MESSAGE" >&2
        exit 2
    fi

    OUTPUT+="/$TARGET/$(basename $TARGET)"
else
    echo "Target is neither file nor directory" >&2
    echo "$HELP_MESSAGE" >&2
    exit 2
fi


# Add munit.c if needed
if [[ "$MUNIT" -eq 1 ]]; then
    SOURCES+=("/workspace/munit/munit.c")
fi


# Create the output dir
OUTPUT_DIR="$(dirname $OUTPUT)"

mkdir -p "$OUTPUT_DIR"


# Call gcc
CFLAGS=($COMMON_CFLAGS $MODE_CFLAGS)

gcc "${CFLAGS[@]}" "${SOURCES[@]}" -o "$OUTPUT" || {
    echo "Compilation failed"
    exit 1
}

# Report output
echo "Mode:     $MODE"
echo "Target:   $TARGET"
echo "Sources:"
printf "    - %s\n" "${SOURCES[@]}"
echo "Output:   $OUTPUT"

exit 0
