#pragma once

#include <string>
#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>

class OptsType {

    std::string _value;

public:
    OptsType(std::string value);

    std::string asString() const;
    int asInt() const;
    bool asBool() const;
    unsigned int asHexUInt() const;
    std::vector<boost::shared_ptr<OptsType>> asVector() const;

};
