#!/bin/bash

# Ensure the directory exists
if [ ! -d "$HOME/.scrivener" ]; then
    mkdir -p $HOME/.scrivener
    echo "Created $HOME/.scrivener directory"
else
    echo "$HOME/.scrivener already exists"
fi

# Ensure the build and src directories exist within .scrivener
if [ ! -d "$HOME/.scrivener/build" ]; then
    mkdir -p $HOME/.scrivener/build
    echo "Created $HOME/.scrivener/build directory"
else
    echo "$HOME/.scrivener/build already exists"
fi

if [ ! -d "$HOME/.scrivener/src" ]; then
    mkdir -p $HOME/.scrivener/src
    echo "Created $HOME/.scrivener/src directory"
else
    echo "$HOME/.scrivener/src already exists"
fi

# Ensure tasks.bin exists
if [ ! -f "$HOME/.scrivener/tasks.bin" ]; then
    touch $HOME/.scrivener/tasks.bin
    echo "Created $HOME/.scrivener/tasks.bin file"
else
    echo "$HOME/.scrivener/tasks.bin already exists"
fi

# Get Python version and config paths
PYTHON_VERSION=$(python3 -c "import sys; print(f'{sys.version_info.major}.{sys.version_info.minor}')")
PYTHON_INCLUDES=$(python3-config --includes)
PYTHON_LIBS=$(python3-config --libs)

# Compile the project
gcc -o $HOME/.scrivener/build/scrivener src/main.c src/menu.c src/task_operations.c $PYTHON_INCLUDES $PYTHON_LIBS -lpython${PYTHON_VERSION}

# Check if the build succeeded
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

# Copy the binary to /usr/bin with sudo
sudo cp $HOME/.scrivener/build/scrivener /usr/bin/scrivener

# Verify installation
if [ $? -eq 0 ]; then
    echo "Scrivener installed successfully and is now accessible via 'scrivener'."
else
    echo "Failed to copy scrivener to /usr/bin."
    exit 1
fi
