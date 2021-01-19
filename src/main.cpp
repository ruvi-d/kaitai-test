#include "balPackage.h"
#include "bir.h"
#include "constructBal.h"
#include <fstream>
#include <iostream>
#include <kaitai/kaitaistream.h>

void printBIRInfo(const ballerina::bir_t &bir) {

  auto constPool = bir.constant_pool();
  std::cout << "Num of elements: " << constPool->constant_pool_count()
            << std::endl;

  auto module = bir.module();
  std::cout << "Num of functions: " << module->function_count() << std::endl;
  std::cout << "\n" << std::endl;
}

int main() {
  std::ifstream ifs("../test/test-bir-dump", std::ifstream::binary);
  kaitai::kstream ks(&ifs);
  ballerina::bir_t bir(&ks);

  printBIRInfo(bir);

  // std::unique_ptr<ballerina::balPackage>
  // package(ballerina::constructBal::construct(bir)); std::cout << "Pkg Name :
  // " << package->name << std::endl;

  return 0;
}