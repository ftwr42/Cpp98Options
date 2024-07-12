#include "include/cpp98opts/option.h"

void Option::addParameter(const std::string & parameter) {
    _parameters.push_back(parameter);
}

void Option::addDescription(const std::string & description) {
    _descriptions.push_back(description);
}

void Option::addExample(const std::string & example) {
    _examples.push_back(example);
}

const std::vector<std::string> &Option::getParameters() {
    return this->_parameters;
}

std::string Option::toString() {

    std::string buffer;

    buffer += "\tPARAMETERS\n\t\t";
    for (VectorString::const_iterator it = _parameters.begin(); _parameters.end() != it; ++it) {
        buffer += *it.base() + ((std::next(it) == _parameters.end())? "":", ");
    }
    buffer += "\n";

    buffer += (_descriptions.size() > 0)? "\t\t\tDESCRIPTIONS\n": "";
    for (VectorString::const_iterator it = _descriptions.begin(); _descriptions.end() != it; ++it) {
        buffer += "\t\t\to " + *it.base() + ((std::next(it) == _descriptions.end())? "":"\n");
    }
    buffer += (_descriptions.size() == 0)? "":"\n";

    buffer += (_examples.size() > 0)? "\t\t\tEXAMPLES\n": "";
    for (VectorString::const_iterator it = _examples.begin(); _examples.end() != it; ++it) {
        buffer += "\t\t\to " + *it.base() + ((std::next(it) == _examples.end())? "":"\n");
    }
    buffer += (_examples.size() == 0)? "":"\n";

    return buffer;
}
