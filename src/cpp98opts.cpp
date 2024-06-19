#include "include/cpp98opts/cpp98opts.h"
#include <iostream>

Cpp98Opts::Cpp98Opts(int argc, char **argv) {
    
    for (int i = 1; i < argc; ++i) {

        char *string = argv[i];
        std::cout<<i<<". "<<string<<"\n";


        
    }
}
