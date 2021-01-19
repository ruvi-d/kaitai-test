#include "gtest/gtest.h"

#ifdef __clang__
#define COMPILER "clang"
#define COMPILER_VERSION __clang_major__
#elif defined(__GNUC__) || defined(__GNUG__)
#define COMPILER "gcc"
#define COMPILER_VERSION 0
#elif defined(_MSC_VER)
#define COMPILER "msc"
#define COMPILER_VERSION 0
#endif

TEST(buildEnvironmentTest, checkCompilerType){
    ASSERT_EQ(COMPILER,"clang");
}

TEST(buildEnvironmentTest, checkCompilerVersion){
    ASSERT_TRUE(COMPILER_VERSION >= 11);
}
