#pragma once

#include "option.h"

class Cpp98Opts {

public:
    Cpp98Opts(int argc, char **argv);

    Option& getOption(const std::string name) const;
    void doSome();

private:

    bool optionExist(char *string);

};
