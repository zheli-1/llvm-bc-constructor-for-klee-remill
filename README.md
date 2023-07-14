An example of how to construct `main` function using llvm api 
Make sure you have the LLVM development libraries installed and compile the program with the appropriate flags to link against the LLVM libraries:
g++ main.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -o main

This will produce an executable named main. When you run it, it will print the LLVM bitcode representing the created module to the standard output. You can redirect the output to a file if you want to save the bitcode.
