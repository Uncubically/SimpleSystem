#ifndef BACKEND_ARITHMETIC_ODDEVEN
#define BACKEND_ARITHMETIC_ODDEVEN



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Arithmetic {
    class OddEven : public ProgramMenu {
        public:
            OddEven() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "arithmetic/odd_even_title.txt");;
                this->desc = "Showcasing the modulo % operator.";
            };

            void run_program() override {
                int n;

                std::cout << "Enter an Integer: ";
                std::cin >> n;

                if (n % 2 == 0) {
                    std::cout << n << " is even.";
                } else {
                    std::cout << n << " is odd.";
                };
            };
    };

    class OddEvenChoice : public ConsMenu::Choice {
        public:
            OddEvenChoice() : ConsMenu::Choice() {
                this->description = "Odd / Even";
                this->menu = std::make_unique<OddEven>(OddEven());
            };
    };
};



#endif
