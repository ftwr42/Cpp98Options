#include "include/cpp98opts/description.h"

void Description::pushBackParameter(const std::string & parameter) {
    _parameters.push_back(parameter);
}

void Description::setHeader(const std::string & header) {
    _header = header;
}

void Description::pushBackDescription(const std::string & description) {
    _description_line.push_back(description);
}

void Description::pushBackExample(const std::string & example) {
    _examples.push_back(example);
}

std::string &Description::parametersToString() const {
    std::string buffer;
    for (VectorString::const_iterator it = _parameters.begin(); it != _parameters.end(); ++it) {
        buffer += *it;
    }
    return buffer; //todo check the may escape error
}

std::string & Description::headerToString() const {
    std::string buffer;
    buffer += _header;
    return buffer;
}

std::string &Description::descriptionsToString() const {
    std::string buffer;
    for (VectorString::const_iterator it = _description_line.begin(); it != _description_line.end(); ++it) {
        buffer += *it;
    }
    return buffer;
}

std::string &Description::examplesToString() const {
    std::string buffer;
    for (VectorString::const_iterator it = _examples.begin(); it != _examples.end(); ++it) {
        buffer += *it;
    }
    return buffer;
}
