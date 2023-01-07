#ifndef BACKEND_ARITHMETIC_NUMBERFACTOR
#define BACKEND_ARITHMETIC_NUMBERFACTOR



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Arithmetic {
    class NumberFactor : public ProgramMenu {
        public:
            NumberFactor() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "arithmetic/number_factor_title.txt");
                this->desc = "Finds all factors of a number.";
            };

            void run_program() override {
                int n, i;

                std::cout << "Enter a positive integer: ";
                std::cin >> n;

                std::cout << "Factors of " << n << " are: ";  
                for(i = 1; i <= n; ++i) {
                    if(n % i == 0)
                        std::cout << i << ", ";
                };
            };
    };

    class NumberFactorChoice : public ConsMenu::Choice {
        public:
            NumberFactorChoice() : ConsMenu::Choice() {
                this->description = "Number Factor";
                this->menu = std::make_unique<NumberFactor>(NumberFactor());
            };
    };
};



#endif
