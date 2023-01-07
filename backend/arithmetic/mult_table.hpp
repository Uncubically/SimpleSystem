#ifndef BACKEND_ARITHMETIC_MULTTABLE
#define BACKEND_ARITHMETIC_MULTTABLE


#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Arithmetic {
	class MultTable : public ProgramMenu {
        public:
            MultTable() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "arithmetic/mult_table_title.txt");
                this->desc = "Generates a multiplication table.";
            };

            void run_program() override {
                int n, range;

				std::cout << "Enter a positive integer: ";
				std::cin >> n;

				std::cout << "Enter range: ";
				std::cin >> range;

				for (int i = 1; i<= range; ++i) {
					std::cout << n << " * " << i << " = " << n * i << std::endl;
				};
            };
    };

	class MultTableChoice : public ConsMenu::Choice {
        public:
            MultTableChoice() : ConsMenu::Choice() {
                this->description = "Multiplication Table";
                this->menu = std::make_unique<MultTable>(MultTable());
            };
    };
};



#endif
