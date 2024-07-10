#pragma once

#include "option.h"
#include "description.h"
#include <vector>
#include <map>

class Cpp98Opts {

public:
    Cpp98Opts(int argc, char **argv);


private:

    bool optionExist(const std::string& key);
//    std::map<std::string, boost::optional<std::string > > values;

    typedef std::map<std::string, Option*> MapStrOptions;
    MapStrOptions  options;
    typedef std::map<std::string, Description*> MapStrDescription;
    MapStrDescription descriptions;

    Option &getOption(const std::string &key) const;

    bool descriptionExist(std::string key);
};
