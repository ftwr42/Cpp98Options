#pragma once

#include <map>
#include "chapter.h"
#include "option.h"
#include <boost/smart_ptr.hpp>

class Cpp98Opts {

    std::vector<const Chapter*> _chapters; //todo make optional
    std::vector<boost::shared_ptr<Chapter>> _chapters2; //todo make optional
    // std::map<std::string, boost::optional<Option*>> _options;
    // std::map<std::string, boost::optional<boost::shared_ptr<Option>>> _options; //todo
    std::vector<boost::optional<boost::shared_ptr<Option>>> _options2;

    boost::optional<Option*> findOption(const std::string &find) const;
    boost::optional<Chapter*> findChapter(const std::string &find) const;

public:
    std::string toString() const;
    void addChapter(const Chapter &chapter);
    // void addOption(Option & option);
    std::vector<OptsType> getInput(const std::string &parameter_name) const;
    void readParameters(const std::vector<std::string> & signs);
    static std::vector<std::string> convertArgvToStrings(int argc, char** argv);
    Option & createOrGetOption(const std::string &parameter);
    Option & createOrGetOption(const std::string &parameter1, const std::string &parameter2);
    Chapter & createOrGetChapter(const std::string &header);

};
