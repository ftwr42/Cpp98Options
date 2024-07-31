#include "include/cpp98opts/option.h"

Option::Option() {
}

Option::Option(const std::string &parameter) {
    _parameters.push_back(parameter);
}

void Option::addParameter(const std::string & parameter) {
    _parameters.push_back(parameter);
}

const std::vector<std::string> &Option::getParameters() {
    return this->_parameters;
}

void Option::addDescription(const std::string & description) {
    _descriptions.push_back(description);
}

void Option::addExample(const std::string & example) {
    _examples.push_back(example);
}

void Option::addValue(std::string value) {
    _values.push_back(boost::optional<OptsType>(OptsType(value)));
}

const std::vector<boost::optional<OptsType>> &Option::getValues() {
    return _values;
}

void Option::addDependsOn(Option &option) {
    _this_options_depends_on.push_back(&option);
}

std::vector<Option*> & Option::getDependsOn() {
    return _this_options_depends_on;
}

void Option::setIsParameter(bool parameter_was_set) {
    _is_parameter = parameter_was_set;
}

bool Option::isParameter() const {
    return _is_parameter;
}

bool Option::asBool() {
    return _is_parameter;
}

std::string Option::toString() {

    std::string buffer;

    for (std::vector<std::string>::const_iterator it = _parameters.begin(); _parameters.end() != it; ++it) {
        buffer += *it.base() + ((std::next(it) == _parameters.end())? "":", ");
    }

    for (std::vector<std::string>::const_iterator it = _descriptions.begin(); _descriptions.end() != it; ++it) {
        buffer += (_descriptions.size() > 1? "\t\t- ":"\t\t") + *it.base() + "\n";//+ ((std::next(it) == _descriptions.end())? "":"\n");
    }

    for (std::vector<std::string>::const_iterator it = _examples.begin(); _examples.end() != it; ++it) {
        buffer += "\t\to " + *it.base() + "\n";//+ ((std::next(it) == _examples.end())? "":"\n"); //todo always false
    }
    buffer += (!_parameters.empty() && _descriptions.empty() && _examples.empty())? "\n":"";

    return buffer;
}
