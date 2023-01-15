//
// Created by Rufelle on 13/01/2023.
//

#ifndef CINDER_EVENT_H
#define CINDER_EVENT_H
#include <string>
#include <iostream>
#include <vector>
#include "../DiveDB-/CLI/src/divefile.h"

namespace cinder {
    std::string init_s = "#include <iostream>\n#include <cstdio>\n #include <memory>\n"
                         "#include <cmath>\n #include <functional>\n #define function(x, y, ...) std::function<y(__VA_ARGS__)> x = [&]\n"
                         "#define __ver__ 0.2\n"
                         "#include <cstdlib>\n #include <vector>\n #include <array>\n"
                         "#include <string>\n";

    std::string main_function = "\nusing namespace std;\nint main (){\n";
    std::string user_args;
    std::string init_e = "\n}\n";
    void event_loop (){
        user_args = "";
        auto * fw = new dive::FileWriter("out.cpp");
        delete fw;
        bool empty = false;
        std::string buffer;
        int counter = 0;
        while (true){
            std::cout << "> ";
            std::getline(std::cin, buffer);
            if (buffer == "-q"){
                exit(1);
            }
            if (buffer.empty()){
                counter++;
            } else {
                counter = 0;
            }
            if (counter >= 1){
                break;
            }
            buffer.append("\n");
            user_args.append(buffer);
        }
        fw = new dive::FileWriter("out.cpp");
        fw->writeLine(" ");
        fw->flush();
        fw->writeLine(init_s + main_function + user_args + init_e);
        fw->flush();
        delete fw;
        if (!user_args.empty()){
            auto i = system("g++ out.cpp -o out.exe");
            if (!i){
                system("out.exe");
            }
            std::cout << "\n";
        }
        event_loop();
    }
}


#endif //CINDER_EVENT_H
