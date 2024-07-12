#pragma once

#include "chapter.h"
#include "option.h"
#include <vector>
#include <map>

class Cpp98Opts {

public:
    explicit Cpp98Opts(const std::vector<std::string> & signs);

    void addDescription(Option &description);

    std::string printDescriptions() const;

    static std::vector<std::string> convertArgvToStrings(int argc, char** argv);

    const std::string & descriptionsToString() const;

private:

    bool optionExist(const std::string& key);
//    std::map<std::string, boost::optional<std::string > > values;

    typedef std::map<std::string, Chapter*> OptionsMap;
    OptionsMap options;

    typedef std::vector<Option*> DescriptionVector;
    DescriptionVector descriptions;

    typedef std::vector<std::string> StringVector;


    Chapter &getOption(const std::string &key) const;

    bool descriptionExist(std::string key);
};
