#pragma once

#include "option.h"

class Chapter {

    const std::string _name;
    std::vector<std::string> _headers;
    std::vector<Option*> _options;
    std::vector<std::string> _footers;

public:
    Chapter(std::string name);
    void addHeader(const std::string &header);
    void addOption(Option &option);
    void addFooter(const std::string &footer);
    const std::string &getName() const;

    std::string toString() const;

};
