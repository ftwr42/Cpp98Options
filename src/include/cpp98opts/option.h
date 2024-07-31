#pragma once

#include "optsType.h"
#include <boost/optional.hpp>

class OptsType;

class Option {

    std::vector<std::string> _parameters;
    std::vector<std::string> _descriptions;
    std::vector<std::string> _examples;
    std::vector<boost::optional<OptsType>> _values;
    std::vector<Option*> _this_options_depends_on; //todo shared ptr
    bool _is_parameter = false;

public:
    Option(const std::string &parameter);

    void addParameter(const std::string & parameter);
    const std::vector<std::string> & getParameters();

    void addDescription(const std::string & description);
    void addExample(const std::string & example);

    void addValue(std::string value);
    const std::vector<boost::optional<OptsType>> &getValues();

    void addDependsOn(Option &option);
    std::vector<Option*> & getDependsOn();

    void setIsParameter(bool parameter_was_set);
    bool isParameter() const;

    bool asBool();
    std::string toString();

};
