#pragma once

#include <iostream>
#include <vector>

class Description {

public:
    void pushBackParameter(const std::string & parameter);
    void setHeader(const std::string & header);
    void pushBackDescription(const std::string & description);
    void pushBackExample(const std::string & example);

    std::string &parametersToString() const;
    std::string & headerToString() const;
    std::string &descriptionsToString() const;
    std::string &examplesToString() const;

private:
    typedef std::vector<std::string> VectorString;
    VectorString _parameters;
    std::string _header;
    VectorString _description_line;
    VectorString _examples;

};

