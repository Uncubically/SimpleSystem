#ifndef BACKEND_ALGORITHMS_NUMBERSWAP
#define BACKEND_ALGORITHMS_NUMBERSWAP



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Algorithms {
    class NumberSwap : public ProgramMenu {
        public:
            NumberSwap() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "algorithms/number_swap_title.txt");
                this->desc = "Swaps the values of two variables.";
            };

            void run_program() override {
                int a, b, temp;

                std::cout << "Please enter value of a: ";
                std::cin >> a;

                std::cout << "Please enter value of b: ";
                std::cin >> b;

                std::cout << "Before swapping." << std::endl;
                std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

                temp = a;
                a = b;
                b = temp;

                std::cout << "After swapping." << std::endl;
                std::cout << "a = " << a << ", b = " << b << std::endl;
            };
    };

	class NumberSwapChoice : public ConsMenu::Choice {
        public:
            NumberSwapChoice() : ConsMenu::Choice() {
                this->description = "Number Swap";
                this->menu = std::make_unique<NumberSwap>(NumberSwap());
            };
	};
};



#endif
