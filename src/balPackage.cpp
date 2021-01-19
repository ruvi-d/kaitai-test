#include "balPackage.h"

namespace ballerina {
balPackage::balPackage(std::string orgName, std::string pkgName,
                       std::string verName, std::string srcFileName)
    : org{orgName}, name{pkgName}, version{verName}, sourceFileName{
                                                         srcFileName} {}
} // namespace ballerina