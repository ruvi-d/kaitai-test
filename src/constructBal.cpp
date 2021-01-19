#include "constructBal.h"
#include <iostream>
#include <vector>

namespace ballerina {
std::unique_ptr<balPackage> constructBal::construct(const bir_t &bir) {
  // bir_t::constant_pool_set_t *
  auto constPool = bir.constant_pool();
  // std::vector<bir_t::constant_pool_entry_t *> *
  auto constPoolEntries = constPool->constant_pool_entries();
  // bir_t::module_t *
  auto module = bir.module();

  auto package = std::make_unique<balPackage>("1", "2", "3", "4");

// Codegen Imports (Function declarations)
  // Codegen Constants
  // Codegen Type Definitions
  // Codegen Global Vars
  // Codegen Type Definitions Bodies
  // Codegen Functions Defs
  auto funcs = module->functions();
  for (auto func : *funcs) {
    genFunction(func);
  }
  // Codegen Annotations

  return package;
}

void constructBal::genBasicBlock(bir_t::basic_block_t *bBlock) {
  auto blockNameCPIndex = bBlock->name_cp_index();
  // temp
  std::vector<bir_t::constant_pool_entry_t *> *mConstPoolEntries;
  auto blockNameConsts = mConstPoolEntries->at(blockNameCPIndex);
  std::string blockName{};
  if (blockNameConsts->tag() ==
      bir_t::constant_pool_entry_t::tag_enum_t::TAG_ENUM_CP_ENTRY_STRING) {
    auto cpStringInfo =
        static_cast<bir_t::string_cp_info_t *>(blockNameConsts->cp_info());
    blockName = cpStringInfo->value();
  } else {
    throw std::runtime_error{"Found function without entry string"};
  }
  std::cout << "\t\t\t Block name: " << blockName
            << " | # instructions: " << bBlock->instructions_count()
            << std::endl;
  //      Instructions
  auto instructions = bBlock->instructions();
  for (auto instruction : *instructions) {
    genInstruction(instruction);
  }
  return;
}

void constructBal::genInstruction(bir_t::instruction_t *inst) {
  auto instPosition = inst->position();
  std::cout << "\t\t\t\t instructions at " << instPosition->s_line()
            << std::endl;
  // Process instruction structure
}

void constructBal::genFunction(bir_t::function_t *func) {

  auto funcPosition = func->position();
  auto funcCPIndex = func->name_cp_index();
  // temp
  std::vector<bir_t::constant_pool_entry_t *> *mConstPoolEntries;
  auto funcConsts = mConstPoolEntries->at(funcCPIndex);
  std::string funcName{};
  if (funcConsts->tag() ==
      bir_t::constant_pool_entry_t::tag_enum_t::TAG_ENUM_CP_ENTRY_STRING) {
    auto cpStringInfo =
        static_cast<bir_t::string_cp_info_t *>(funcConsts->cp_info());
    funcName = cpStringInfo->value();
    std::cout << "\t" << funcName << " at line: " << funcPosition->s_line()
              << std::endl;
  } else {
    throw std::runtime_error{"Found function without entry string"};
  }

  // Function body
  auto funcBody = func->function_body();
  //  Return Var
  //  Local variable

  auto funcBBlocks = funcBody->function_basic_blocks_info()->basic_blocks();
  std::cout << "\t\t Num of basic blocks: "
            << funcBody->function_basic_blocks_info()->basic_blocks_count()
            << std::endl;
  for (auto bBlock : *funcBBlocks) {
    genBasicBlock(bBlock);
  }

  return;
}

} // namespace ballerina