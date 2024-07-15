#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "option.h"
#include <optional>

class Chapter {

public:
    explicit Chapter(const std::string & name);
    void addHeader(const std::string & header);
    void setOptions(std::vector<Option*> *options);
    void addFooter(const std::string & footer);

    std::string toString();

private:
    typedef std::vector<std::string> VectorString;
    typedef std::vector<Option*> VectorOption; //todo make with optional

    const std::string _name;
    VectorString _headers;
    VectorOption *_options; //todo make with optional
    VectorString _footers;
};
