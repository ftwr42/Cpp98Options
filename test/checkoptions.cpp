#include <gtest/gtest.h>
#include "../src/include/cpp98opts/cpp98opts.h"


//class CheckOptions: public testing::Test {
//
//};

TEST(Main, ReadParameters) {

    const char* strings[] = {"/workdir/myProg.exe", "Hello", "World", "Test"};

    int argc = 4;
    char **argv = const_cast<char**>(strings);

    Cpp98Opts opts = Cpp98Opts(argc, argv);
    opts.doSome();

    ASSERT_TRUE(true);
}