#include "include/cpp98opts/cpp98opts.h"

#include <vector>
#include <string>


Cpp98Opts::Cpp98Opts(const std::vector<std::string> & signs) {

    std::string current_option;
    StringVector::const_iterator it = signs.begin();
    for (StringVector::const_iterator option_or_parameter = ++it;
         option_or_parameter != signs.end();
         ++option_or_parameter) {

        bool is_option = (option_or_parameter->substr(0, 2) == "--");
        
//        if(is_option) {
//            if (!optionExist(option_or_parameter) && descriptionExist(option_or_parameter)) {
//                std::cout<<"get"<<"\n";
//                Option *pOption = new Option(option_or_parameter);
//                options[option_or_parameter] = pOption;
//            }
//            current_option = option_or_parameter;
//        } else {
//            if (current_option.empty() && !optionExist(current_option)) {
//                //todo raise error
//            }
//            Option &option = getOption(current_option);
//            option.addValue(option_or_parameter);
//        }
    }
}

bool Cpp98Opts::optionExist(const std::string& key) {
    //todo add boost optional
    OptionsMap::const_iterator iterator = options.find(key);
    if(iterator != options.end()) {
        return true;
    }
    return false;
}

//bool Cpp98Opts::descriptionExist(std::string key) {
//    //todo add boost optional
//    for (DescriptionVektor::const_iterator it = descriptions.begin(); it != descriptions.end(); ++it) {
//        std::string &headerToString = (*it)->headerToString();
//        std::cout<<""<<headerToString<<"\n";
//    }
//
//    descriptions.
//    return false;
//}

Chapter& Cpp98Opts::getOption(const std::string& key) const {
    //todo do it with optional in order to return NULL properly

    OptionsMap::const_iterator iterator = options.find(key);
    if(iterator != options.end()) {
        return *iterator->second;
    }
    return *iterator->second;
}

void Cpp98Opts::addDescription(Option &description) {
    descriptions.push_back(&description);
}

std::string Cpp98Opts::printDescriptions() const {
    std::string buffer;

    for (DescriptionVector::const_iterator it = descriptions.begin();
         it != descriptions.end();
         ++it) {

        Option *pDescription = *it.base();
        std::vector<std::string> parameters = pDescription->getParameters();
        
        for (std::vector<std::string>::const_iterator itd = parameters.begin();
             parameters.end() != itd;
             ++itd) {

            buffer += *itd.base() + ((std::next(itd) == parameters.end())? "":", ");
        }

        return buffer;
    }
}


std::vector<std::string> Cpp98Opts::convertArgvToStrings(int argc, char** argv) {
    std::vector<std::string> args;
    for (int i = 0; i < argc; ++i) {
        args.push_back(std::string(argv[i]));
    }
    return args;
}

const std::string & Cpp98Opts::descriptionsToString() const {
    std::string buffer;
    for (DescriptionVector::const_iterator it = descriptions.begin(); it != descriptions.end(); ++it) {
        Option *base = static_cast<Option*>(*it);
        std::cout<<""<<"\n";

    }

    return buffer;
}
