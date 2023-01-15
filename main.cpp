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
    event_loop();
    return 0;
}
