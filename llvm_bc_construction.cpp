#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Type.h>

int main() {
  // Create a new LLVM module and set up the function
  llvm::LLVMContext context;
  llvm::Module module("my_module", context);
  
  // Create the main function
  llvm::FunctionType *funcType = llvm::FunctionType::get(
    llvm::Type::getInt32Ty(context), // Return type
    false                           // Variadic argument
  );
  
  llvm::Function *mainFunc = llvm::Function::Create(
    funcType,
    llvm::Function::ExternalLinkage,
    "main",
    module
  );
  
  // Create the basic block and set it as the entry block
  llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry", mainFunc);
  
  // Create an IR builder and set it to the entry block
  llvm::IRBuilder<> builder(entryBlock);
  
  // Create the return instruction
  builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(32, 0)));
  
  // Verify the module for correctness
  llvm::verifyModule(module);
  
  // Print the LLVM bitcode to standard output
  llvm::outs() << module;

  return 0;
}

