#pragma once

#include <iostream>
#include <string>

class Option {

public:
    explicit Option(const std::string& name);
    void addValue(const std::string& value);


private:
    std::string name;
    std::vector<std::string> _vals


};
