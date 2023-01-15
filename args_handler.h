//
// Created by Rufelle on 13/01/2023.
//

#ifndef CINDER_ARGS_HANDLER_H
#define CINDER_ARGS_HANDLER_H
#include <vector>
#include <string>
#include <iostream>
namespace cinder {
    class ArgsHandler {
        std::vector<std::string> args;
    public:
        ArgsHandler(const std::vector<std::string> & args){
            this->args = args;
            handle();
        }
    private:

        void handle(){
            if (args.at(1)=="-h"){
                helpkit();
            } else if (args.at(1)=="-v"){
                verdisplay();
            }
        }


        void helpkit(){
            std::cout << "Welcome to the CINDER help kit. Please select an option:\n"
                         "1: Get Started\n"
                         "2: Main Function Location\n"
                         "3: Creating Functions\n"
                         "4: using namespace std\n"
                         "5: #include and #define \n"
                         "0: Exit Help Kit.\n"
                         "choice: ";

            char choice;
            std::cin >> choice;
            switch (choice){
                case '1':
                    std::cout << "Let us get started with the CINDER CPP interpreter.\n"
                                 "You can print your first hello world by using inputting:\n"
                                 "cout << \"Hello World!\";\n"
                                 "Press the enter button two times. This will then execute the code.\n"
                                 "Virtually, you can do almost anything you can do in CPP in the CINDER interpreter.\n"
                                 "Happy Coding!\n";
                    break;
                case '2':
                    std::cout << "You do not need to declare the main function. Type away!\n";
                    break;
                case '3':
                    std::cout << "Creating functions using CINDER can be quite challenging as it uses a different syntax.\n"
                                 "To get started, familiarize the function declaration syntax:\n"
                                 "function(<function name>, <return type>, <parameter types>)(parameter names){function body};\n"
                                 "Do not forget the comma at the end!\n"
                                 "The special feature of the CINDER function is that it can use all the variables in the global scope.\n"
                                 "\n\nLet us see an example. Let us create a function called print which prints the string in the output:\n"
                                 "function(print, void, const char *)(const char * params){cout << params;};\n"
                                 "You can also use the variables in the global scope. Given the following example:\n"
                                 "int a = 5;\n"
                                 "function(test, void, void)(){cout << a;};\n"
                                 "The function above is also valid!\n";
                                 break;
                case '4':
                    std::cout << "There is no need to use using namespace std in CINDER.\n"
                                 "By default, this is already enabled. Because CINDER is to be used for quick scripting and\n"
                                 "educational purposes, we have determined that by defining namespace std, we are able to make the\n"
                                 "the coding experience less verbose.\n";
                    break;
                case '5':
                    std::cout << "You can use the preprocessor directives #include and #define in the same manner as you would use in regular CPP.\n";
                    break;
                case '0':
                    return;
                default:
                    std::cout << "Invalid command!\n";
                    helpkit();
                    return;
            }
        }

        void verdisplay(){
            std::cout << "Cinder CPP Interpreter.\n(c) 2023, Rufelle Emmanuel Pactol\nVer: " << __ver__;
        }


    };
}

#endif //CINDER_ARGS_HANDLER_H
