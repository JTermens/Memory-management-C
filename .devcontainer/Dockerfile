# =============================================================================
# Dokerfile for C-devenv: a lightweight environment to compile 
# & test C scripts
#
# C-devenv is designed as an interactive environment for development and
# exploration using C. It conceptually separates the build and run stages with 
# different build.sh, run.sh and test.sh scripts, while it also include 
# debugging and diagnose tools.
# 
# This image is intended as a development container, not a production runtime.
# It intentionally includes both build and runtime tooling to maximize
# transparency and reduce cognitive overhead during exploration.
#
# Author: Joan Térmens (https://github.com/JTermens
# Last update: 30 Jan 2026
# =============================================================================

# Lightweight base image with
glibc FROM debian:bookworm-slim

# Set project root inside the container
WORKDIR /workspace 

# Create an out-of-tree build directory (ephemeral)
RUN mkdir build

# Install a minimal toolchain for building C programs
RUN apt-get update && apt-get install -y \
    gcc \
    # make \
    binutils \
    libc6-dev \
    git \
    gdb \
    strace \
    valgrind \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* 

# Note:
# The builder only assumes that the following paths exist at runtime:
# - /workspace/src -> bind-mounted from host
# - /workspace/scripts -> bind-mounted from host
# - /workspace/munit -> bind-mounted (read-only) from host

# Bash shell at the container 
CMD ["bash"]
