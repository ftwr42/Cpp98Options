#pragma once

#include "chapter.h"
#include "option.h"
#include <boost/smart_ptr.hpp>

class Cpp98Opts {

    std::vector<boost::shared_ptr<Chapter>> _chapters;
    std::vector<boost::optional<boost::shared_ptr<Option>>> _options;

    boost::optional<Option*> findOption(const std::string &find) const;
    boost::optional<Chapter*> findChapter(const std::string &find) const;

public:
    std::string toString() const;
    void addChapter(const Chapter &chapter);
    std::vector<OptsType> getInput(const std::string &parameter_name) const;
    void readParameters(const std::vector<std::string> & signs);
    static std::vector<std::string> convertArgvToStrings(int argc, char** argv);
    Option & createOrGetOption(const std::string &parameter);
    Option & createOrGetOption(const std::string &parameter1, const std::string &parameter2);
    Chapter & createOrGetChapter(const std::string &header);

};
