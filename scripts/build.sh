#!/bin/bash

echo "Building all CyberAI components..."

# Build Rust components
echo "Building Rust components..."
cd rust_components
cargo build --release
cd ..

# Build Python components (optional compilation if using C extensions)
echo "Preparing Python components..."
cd python_components
# Example: python setup.py build
cd ..

# Build C++ components
echo "Building C++ components..."
cd cpp_components
mkdir -p build
cd build
cmake ..
make
cd ../../

echo "Build process completed."
