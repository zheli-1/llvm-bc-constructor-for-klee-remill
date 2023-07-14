Make sure you have the LLVM development libraries installed and compile the program with the appropriate flags to link against the LLVM libraries:
g++ main.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -o main
d
