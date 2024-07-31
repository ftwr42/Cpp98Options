#include "include/cpp98opts/optsType.h"
#include <algorithm>
#include <climits>
#include <boost/smart_ptr.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <utility>

OptsType::OptsType(std::string value) : _value(std::move(value)) {}

std::string OptsType::asString() const {
    return _value;
}

int OptsType::asInt() const {
    return boost::lexical_cast<int>(_value);
}

bool OptsType::asBool() const {
    if(_value == "true") {
        return true;
    }
    return false;
}

unsigned int OptsType::asHexUInt() const {

    char* end;
    const long hex = strtol(_value.c_str(), &end, 16);

    if (errno == ERANGE || hex > UINT_MAX || hex < 0) {
        throw std::invalid_argument("Hex value out of range");
    }

    if (end != _value.data() + _value.length()) {
        throw std::invalid_argument("Invalid end of string");
    }

    return hex;
}

std::vector<boost::shared_ptr<OptsType>> OptsType::asVector() const {

    std::vector<boost::shared_ptr<OptsType>> result;
    std::vector<std::string> tokens;
    boost::split(tokens, _value, boost::is_any_of(","));

    for(std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        // result.push_back(boost::shared_ptr<OptsType>(new OptsType(*it)));
        result.push_back(boost::make_shared<OptsType>(OptsType(*it)));
    }
    return result;
}
