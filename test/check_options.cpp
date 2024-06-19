#include "check_options.h"
#include <gtest/gtest.h>
#include <cpp98opts/cpp98opts.h>
#include <cpp98opts/option.h>


class CheckOptions: public testing::Test {

};

TEST(Main, ReadParameters) {

    const char* strings[] = {"/workdir/myProg.exe", "Hello", "World", "Test"};

    int argc = 4;
    char **argv = const_cast<char**>(strings);

    Cpp98Opts opts = Cpp98Opts(argc, argv);

    ASSERT_TRUE(true);
}