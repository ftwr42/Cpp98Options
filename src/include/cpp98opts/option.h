#pragma once

#include <string>
#include <vector>

class Option {

public:
    void addParameter(const std::string & parameter);
    void addDescription(const std::string & description);
    void addExample(const std::string & example);

    const std::vector<std::string> & getParameters();

    std::string toString();

private:
    typedef std::vector<std::string> VectorString;
    VectorString _parameters;
    VectorString _descriptions;
    VectorString _examples;

};
