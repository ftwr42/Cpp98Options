#include "include/cpp98opts/cpp98opts.h"

#include <csignal>
#include <stdexcept>
#include <boost/concept/detail/has_constraints.hpp>

std::string Cpp98Opts::toString() const {
    std::string buffer;
    for (std::vector<const Chapter*>::const_iterator it = _chapters.begin(); it != _chapters.end(); ++it) {
        buffer += (*it)->toString();
    }
    return buffer;
}

void Cpp98Opts::addChapter(const Chapter &chapter) {
    _chapters.push_back(&chapter);
}

boost::optional<Option*> Cpp98Opts::findOption(const std::string &find) const {

    for (std::vector<boost::optional<boost::shared_ptr<Option>>>::const_iterator it = _options2.begin();
    it != _options2.end(); ++it) {

        for (std::vector<std::string>::const_iterator it2 = it.base()->get().get()->getParameters().begin();
            it2 != it.base()->get().get()->getParameters().end(); ++it2) {

                if (*it2 == find) {
                    return it->get().get();
                }
            }
    }

    return boost::none;
}

boost::optional<Chapter *> Cpp98Opts::findChapter(const std::string &find) const {
    for (std::vector<boost::shared_ptr<Chapter>>::const_iterator it = _chapters2.begin(); it != _chapters2.end(); ++it) {
        if (it->get()->getName() == find) {
            return it->get();
        }
    }
    return boost::none;
}

// void Cpp98Opts::addOption(Option &option) {
//
//     // boost::optional<Option> find = findParameter(option.getParameters()[0]);
//     //
//     // if (find == boost::none) {
//     //     _options.push_back(boost::make_optional(boost::make_shared<Option>(option)));
//     // }
//
//     for (std::vector<std::string>::const_iterator it = option.getParameters().begin();
//          it != option.getParameters().end(); ++it) {
//
//         if (_options.find(*it) != _options.end()) {
//             throw std::runtime_error("Option " + *it + " already exists");
//         }
//
//         _options[*it] = &option;
//         // _options[*it] = boost::make_optional(boost::make_shared<Option>(option));
//     }
// }

std::vector<OptsType> Cpp98Opts::getInput(const std::string &parameter_name) const { //todo make const
    std::vector<OptsType> input; //todo make smart ptr

    boost::optional<Option *> find_option = findOption(parameter_name);
    // std::map<std::string, boost::optional<Option*>>::const_iterator it_option = _options.find(parameter_name);

    if (!find_option.is_initialized()) {
        throw std::runtime_error("Option " + parameter_name + " does not exists");
    }

    std::vector<boost::optional<OptsType>> values = find_option.get()->getValues();

    // std::vector<boost::optional<OptsType>> v = it_option->second.get()->getValues();
    for (std::vector<boost::optional<OptsType>>::const_iterator it = values.begin(); it != values.end(); ++it) {
        input.push_back(it->get());
    }

    return input;
}

void Cpp98Opts::readParameters(const std::vector<std::string> &signs) {
    Option *current_option;
    std::vector<std::string>::const_iterator iter = signs.begin();
    for (std::vector<std::string>::const_iterator it = ++iter; it != signs.end(); ++it) {
        if((it->substr(0, 2) == "--") || (it->substr(0, 1) == "-")) {
            // std::map<std::string, boost::optional<Option*>>::iterator it_option = _options.find(*it);
            boost::optional<Option*> it_opt = findOption(*it);
            if (it_opt.is_initialized()) {
                it_opt.get()->addValue("true");
                it_opt.get()->setIsParameter(true);
            } else {
                throw std::runtime_error("Option " + *it + " does not exists");
            }

            current_option = it_opt.get();
        } else {
            current_option->addValue(*it);
        }
    }

    // for (std::map<std::string, boost::optional<Option*>>::const_iterator it_options =
    //     _options.begin(); it_options != _options.end(); ++it_options) {
    //
    //     if (it_options->second.get()->isParameter() == true) {
    //         bool all_dependencies_set = true;
    //         for (std::vector<Option*>::const_iterator it_depends = it_options->second.get()->getDependsOn().begin();
    //             it_depends != it_options->second.get()->getDependsOn().end(); ++it_depends) {
    //
    //             all_dependencies_set = (*it_depends)->isParameter();
    //         }
    //
    //         if (all_dependencies_set == false) {
    //             throw std::runtime_error("Option " + it_options->first + " depends on another option that was not set");
    //         }
    //     }
    // }

    for (std::vector<boost::optional<boost::shared_ptr<Option>>>::const_iterator it_options =
    _options2.begin(); it_options != _options2.end(); ++it_options) {

        if (it_options->get()->isParameter() == true) {
            bool all_dependencies_set = true;

            for (std::vector<Option*>::const_iterator it_depends = it_options->get()->getDependsOn().begin();
                it_depends != it_options->get()->getDependsOn().end(); ++it_depends) {

                all_dependencies_set = (*it_depends)->isParameter();
            }

            if (all_dependencies_set == false) {
                throw std::runtime_error("Option " + it_options->get()->getParameters().front() +
                    " depends on another option that was not set");
            }
        }
    }
}

std::vector<std::string> Cpp98Opts::convertArgvToStrings(int argc, char **argv) {
    //todo
}

Option & Cpp98Opts::createOrGetOption(const std::string &parameter1, const std::string &parameter2) {

    boost::optional<Option*> opt1 = findOption(parameter1);
    boost::optional<Option*> opt2 = findOption(parameter2);

    if (opt1.is_initialized()) {
        return *opt1.get();
    } else if (opt2.is_initialized()) {
        return *opt2.get();
    }

    boost::shared_ptr<Option> new_option = boost::make_shared<Option>(parameter1);
    new_option->addParameter(parameter2);
    _options2.push_back(boost::make_optional(new_option));
    return *new_option;
}

Option & Cpp98Opts::createOrGetOption(const std::string &parameter) {

    boost::optional<Option*> opt = findOption(parameter);

    if (opt.is_initialized()) {
        return *opt.get();
    }

    boost::shared_ptr<Option> new_option = boost::make_shared<Option>(parameter);
    _options2.push_back(boost::make_optional(new_option));
    return *new_option;
}

Chapter & Cpp98Opts::createOrGetChapter(const std::string &header) {

    boost::optional<Chapter*> opt = findChapter(header);
    if (opt.is_initialized()) {
        return *opt.get();
    }

    boost::shared_ptr<Chapter> new_chapter = boost::make_shared<Chapter>(header);
    _chapters2.push_back(new_chapter);
    return *new_chapter;
}
