#ifndef __BALPACKAGE__H__
#define __BALPACKAGE__H__

#include <string>

namespace ballerina {
class balPackage {
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
  balPackage()=delete;
  balPackage(std::string orgName, std::string pkgName, std::string verName,
             std::string srcFileName);
  ~balPackage()=default;
};

} // namespace ballerina

#endif //!__BALPACKAGE__H__