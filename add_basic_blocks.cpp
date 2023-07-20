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
  
  // Create the basic blocks
  llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry", mainFunc);
  llvm::BasicBlock *block1 = llvm::BasicBlock::Create(context, "block1", mainFunc);
  llvm::BasicBlock *block2 = llvm::BasicBlock::Create(context, "block2", mainFunc);
  
  // Create an IR builder and set it to the entry block
  llvm::IRBuilder<> builder(entryBlock);
  
  // Branch from entry block to block1
  builder.CreateBr(block1);
  
  // Set the IR builder to block1
  builder.SetInsertPoint(block1);
  
  // Do some computations in block1
  llvm::Value *result = builder.CreateAdd(
    llvm::ConstantInt::get(context, llvm::APInt(32, 10)),
    llvm::ConstantInt::get(context, llvm::APInt(32, 20))
  );
  
  // Branch from block1 to block2
  builder.CreateBr(block2);
  
  // Set the IR builder to block2
  builder.SetInsertPoint(block2);
  
  // Create the return instruction in block2
  builder.CreateRet(result);
  
  // Verify the module for correctness
  llvm::verifyModule(module);
  
  // Print the LLVM bitcode to standard output
  llvm::outs() << module;

  return 0;
}
