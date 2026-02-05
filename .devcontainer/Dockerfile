# =============================================================================
# Dokerfile for C-devenv: a lightweight environment to compile 
# & test C scripts
#
# C-devenv is designed as an interactive environment for development and
# exploration using C. It separates the minimal build toolchain from the 
# runtime tools into two layers: builder & analyzer, respectively. It also does
# not define a working diretcory as it is designed to work as a base image for
# devcontainers.
# 
# This image is intended as a development container, not a production runtime.
# It intentionally includes both build and runtime tooling to maximize
# transparency and reduce cognitive overhead during exploration.
#
# Author: Joan Térmens (https://github.com/JTermens
# Last update:5 Feb 2026
# =============================================================================

# Lightweight base image with glibc 
FROM debian:bookworm-slim AS builder

# Install a minimal toolchain for building C programs
RUN apt-get update && apt-get install -y \
    gcc \
    # make \
    # binutils \
    libc6-dev \
    git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* 

# Bash shell at the container 
CMD ["bash"]

FROM builder AS analyzer

RUN apt-get update && apt-get install -y \
    gdb \
    strace \
    valgrind \
    && apt-get-clean \
    && rm -rf /var/lib/apt/lists/*

CMD ["bash"]
