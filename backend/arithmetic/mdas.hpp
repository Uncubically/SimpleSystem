#ifndef BACKEND_ARITHMETIC_MDAS
#define BACKEND_ARITHMETIC_MDAS



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Arithmetic {
	class Mdas : public ProgramMenu {
        public:
            Mdas() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "arithmetic/mdas_title.txt");
                this->desc = "Multiplication, division, addition, and subtraction.";
            };

            void run_program() override {
                double num1, num2;

				std::cout << "MDAS OF TWO INPUT NUMBER\n";

				std::cout << "\nEnter your 1st value: ";
				std::cin >> num1;
				std::cout << "Enter your 2nd value: ";
				std::cin >> num2;

				std::cout
					<< std::endl
					<< "Here's your result:" << std::endl
					<< "Multiplication: " << num1 * num2 << std::endl
					<< "Division: " << num1 / num2 << std::endl
					<< "Addition: " << num1 + num2 << std::endl
					<< "Subtraction: " << num1 - num2 << std::endl;
            };
    };

	class MdasChoice : public ConsMenu::Choice {
        public:
            MdasChoice() : ConsMenu::Choice() {
                this->description = "MDAS";
                this->menu = std::make_unique<Mdas>(Mdas());
            };
	};
};



#endif
