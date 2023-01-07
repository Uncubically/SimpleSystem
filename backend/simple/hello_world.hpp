#ifndef BACKEND_SIMPLE_HELLOWORLD
#define BACKEND_SIMPLE_HELLOWORLD



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../path.hpp"
#include "../program_menu.hpp"



namespace Simple {
    class HelloWorld : public ProgramMenu {
        public:
            HelloWorld() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "simple/hello_world_text.txt");
                this->desc = "A simple \"Hello World!\" program, a tradition to any programming language.";
            };

            void run_program() override {
                std::cout << "Hello world!";
            };
    };


    class HelloWorldChoice : public ConsMenu::Choice {
        public:
            HelloWorldChoice() : ConsMenu::Choice() {
                this->description = "Hello World";
                this->menu = std::make_unique<HelloWorld>(HelloWorld());
            };
    };
};



#endif
