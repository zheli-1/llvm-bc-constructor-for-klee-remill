#include <iostream>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>

int main() {
    // Initialize the LLVM context and create a SourceMgr.
    llvm::LLVMContext context;
    llvm::SMDiagnostic err;

    // Parse the .ll file and create the LLVM module.
    std::unique_ptr<llvm::Module> module = llvm::parseIRFile("example.ll", err, context);

    if (!module) {
        // Error handling in case the file could not be parsed.
        std::cerr << "Error parsing the .ll file: ";
        err.print("example", llvm::errs());
        return 1;
    }

    // Perform operations on the loaded module, if needed.
    // For example, inspect functions, create new ones, optimize, etc.

    return 0;
}
