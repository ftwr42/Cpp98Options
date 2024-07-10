#include "include/cpp98opts/option.h"


Option::Option(const std::string& name): name(name){}

void Option::addValue(const std::string &value) {
    values.push_back(value);
}
