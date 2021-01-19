#ifndef __CONSTRUCTBAL__H__
#define __CONSTRUCTBAL__H__

#include "balPackage.h"
#include "bir.h"
#include <memory>

namespace ballerina {
class constructBal {
private:
  /* data */
  void genFunction(bir_t::function_t *func);
  void genBasicBlock(bir_t::basic_block_t *bBlock);
  void genInstruction(bir_t::instruction_t *inst);

public:
  constructBal(/* args */) = default;
  ~constructBal() = default;
  std::unique_ptr<balPackage> construct(const bir_t &bir);
};
} // namespace ballerina
#endif //!__CONSTRUCTBAL__H__