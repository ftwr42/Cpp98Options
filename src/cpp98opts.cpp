#include "include/cpp98opts/cpp98opts.h"

#include <vector>
#include <string>


Cpp98Opts::Cpp98Opts(int argc, char **argv) {

    std::string current_option;
    
    for (int i = 1; i < argc; ++i) {
        
        std::string option_or_parameter = argv[i];

        bool is_option = (option_or_parameter.substr(0, 2) == "--");
        
        if(is_option) {
            if (!optionExist(option_or_parameter) && descriptionExist(option_or_parameter)) {
                std::cout<<"get"<<"\n";
                Option *pOption = new Option(option_or_parameter);
                options[option_or_parameter] = pOption;
            }
            current_option = option_or_parameter;
        } else {
            if (current_option.empty() && !optionExist(current_option)) {
                //todo raise error
            }
            Option &option = getOption(current_option);
            option.addValue(option_or_parameter);
        }
    }
}

bool Cpp98Opts::optionExist(const std::string& key) {
    //todo add boost optional
    MapStrOptions::const_iterator iterator = options.find(key);
    if(iterator != options.end()) {
        return true;
    }
    return false;
}

bool Cpp98Opts::descriptionExist(std::string key) {
    //todo add boost optional
    MapStrDescription::const_iterator iterator = descriptions.find(key);
    if(iterator != descriptions.end()) {
        return true;
    }
    return false;
}

Option& Cpp98Opts::getOption(const std::string& key) const {
    //todo do it with optional in order to return NULL properly

    MapStrOptions::const_iterator iterator = options.find(key);
    if(iterator != options.end()) {
        return *iterator->second;
    }
    return *iterator->second;
}


