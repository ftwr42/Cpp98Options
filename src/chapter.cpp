#include "include/cpp98opts/chapter.h"


Chapter::Chapter(const std::string &name) : _name(name), _options(NULL) {

}


void Chapter::addHeader(const std::string & header) {
    _headers.push_back(header);
}

void Chapter::setOptions(std::vector<Option *> *options) {
    _options = options;
}

void Chapter::addFooter(const std::string & footer) {
    _footers.push_back(footer);
}

std::string Chapter::toString() {

    std::string buffer;

    buffer += _name+"\n";
    for (VectorString::const_iterator it = _headers.begin(); _headers.end() != it; ++it) {
        buffer += *it.base() + ((std::next(it) == _headers.end())? "":", ");
    }
    buffer += "\n";

    for (VectorOption::const_iterator it = _options->begin(); _options->end() != it; ++it) {
//        buffer += (*it)->toString();
//        const_cast<Option>( it.base())
//        buffer += it.base().toString();
    }
    buffer += "\n";

    for (VectorString::const_iterator it = _footers.begin(); _footers.end() != it; ++it) {
//        buffer += *it.base() + ((std::next(it) == _footers.end())? "":", ");
    }
    buffer += "\n";

    return buffer;
}
