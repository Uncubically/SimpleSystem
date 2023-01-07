#ifndef BACKEND_ALGORITHMS_STRINGLENGTH
#define BACKEND_ALGORITHMS_STRINGLENGTH



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Algorithms {
    class StringLength : public ProgramMenu {
        public:
            StringLength() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "algorithms/string_length_title.txt");
                this->desc = "Counts how many characters there are in the input.";
            };

            void run_program() override {
                std::string str;
                std::cout << "Please input a word to be counted: ";
                std::cin >> str;

                int i = 0;
                for(; str[i] != *"\0"; i++); // keep adding i until the current char is null

                std::cout << i;
            };
    };

	class StringLengthChoice : public ConsMenu::Choice {
        public:
            StringLengthChoice() : ConsMenu::Choice() {
                this->description = "String Length";
                this->menu = std::make_unique<StringLength>(StringLength());
            };
	};
}



#endif
