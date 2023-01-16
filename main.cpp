#include <iostream>

#include "cinder_hash.h"
#include "vectorize.h"
#include "args_handler.h"
#include "event.h"
int main(int argc, char ** argv) {
    using namespace cinder;
    if (argc >= 2){
        auto args = vectorize(argc, argv);
        ArgsHandler handle = ArgsHandler(args);
        return 0;
    }
    std::cout << "Welcome to the Cinder CPP Interpreter.\n"
                 "Type -q to quit. For help, type the following in the command line upon the next boot: cinder -h\n"
                 "(c) Rufelle Emmanuel Pactol, 2022.\n";
    event_loop();
    return 0;
}
