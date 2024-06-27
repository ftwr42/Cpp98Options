#pragma once

#include "../../common.h"
#include "option.h"

class Cpp98Opts {

public:
    Cpp98Opts(int argc, char **argv);

    Option& getOption(const String name) const;
    void doSome();

private:

    VVectorString values();

    bool optionExist(char *string);

    VVectorString _values();
};
