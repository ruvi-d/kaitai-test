#ifndef __BALMODULE__H__ballerina
#define __BALMODULE__H__

#include <string>

namespace ballerina {
class balModule {
private:
  /* data */
public:
  std::string org;
  std::string name;
  std::string version;
  std::string sourceFileName;
//   std::vector<BIRFunction *> functions;
//   std::vector<VarDecl *> globalVars;
//   std::map<string, LLVMValueRef> globalVarRefs;
//   std::map<string, BIRFunction *> functionLookUp;
//   std::StructType *structType;
//   std::StringTableBuilder *strBuilder;
//   std::map<string, vector<LLVMValueRef>> structElementStoreInst;
  balModule(/* args */);
  ~balModule();
};

balModule::balModule(/* args */) {}

balModule::~balModule() {}

} // namespace ballerina

#endif //!__BALMODULE__H__