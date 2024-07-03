#include "include/cpp98opts/cpp98opts.h"

#include <vector>
#include <string>


Cpp98Opts::Cpp98Opts(int argc, char **argv) {
    
    for (int i = 1; i < argc; ++i) {

        char *string = argv[i];
        std::cout<<i<<". "<<string<<"\n";

        if(optionExist(string)) {
            std::cout<<"new"<<"\n";
        } else {
            std::cout<<"get"<<"\n";
        }
    }
}

bool Cpp98Opts::optionExist(char *string) {

    std::vector<std::vector<std::string> >::iterator iter;

//    for (iter = _values().begin(); iter != _values().end() ; iter++) {
//        if ()
//    }

    return false;
}

void Cpp98Opts::doSome() {
    std::cout<<"hi some"<<"\n";
}

Option &Cpp98Opts::getOption(const std::string name) const {

    std::map()

    return <#initializer#>;
}

//Option &Cpp98Opts::getOption(const std::string name) const {
//
//    std::vector<std::vector<std::string> >::iterator iter;
//
//
//}
