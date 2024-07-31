#include "include/cpp98opts/chapter.h"

#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <iostream>

Chapter::Chapter(const std::string &name): _name(name) {}

void Chapter::addHeader(const std::string & header) {
    _headers.push_back(header);
}

void Chapter::addOption(Option &option) {
    _options2.push_back(&option);
}

// void Chapter::addOption2(const boost::shared_ptr<Option> &option) {
//     _options2.push_back(option);
// }

void Chapter::addFooter(const std::string & footer) {
    _footers.push_back(footer);
}

const std::string & Chapter::getName() const {
    return _name;
}

std::string Chapter::toString() const {

    std::string buffer = _name;
    std::transform(_name.begin(), _name.end(), buffer.begin(), ::toupper);
    buffer += "\n";

    for (std::vector<std::string>::const_iterator it = _headers.begin(); _headers.end() != it; ++it) {
        buffer += *it.base() + "\n";
    }

    for (std::vector<Option*>::const_iterator it = _options2.begin(); _options2.end() != it; ++it) {
        Option *opt = *it.base();
        buffer += opt->toString();
    }

    for (std::vector<std::string>::const_iterator it = _footers.begin(); _footers.end() != it; ++it) {
        buffer += *it.base() + "\n";
    }

    return buffer;
}
