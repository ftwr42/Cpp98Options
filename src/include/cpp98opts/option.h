#pragma once

#include "../../common.h"

class Option {

public:
    explicit Option(const std::string& name);
    void addValue(const std::string& value);


private:
    String name;
    std::vector<std::vector<std::string> > values();


};
