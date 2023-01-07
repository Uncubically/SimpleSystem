#ifndef BACKEND_ALGORITHMS_CHECKLEAPYEAR
#define BACKEND_ALGORITHMS_CHECKLEAPYEAR



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Algorithms {
    class LeapYear : public ProgramMenu {
        public:
            LeapYear() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "algorithms/check_leap_year_title.txt");
                this->desc = "Checks if the year is a leap year according to certain standards.";
            };

            void run_program() override {
				int year;
                std::cout << "Enter a year: ";
                std::cin >> year;

                // leap year if perfectly divisible by 400
                if (year % 400 == 0) {
                    std::cout << year << " is a leap year.";
                }
                // not a leap year if divisible by 100
                // but not divisible by 400
                else if (year % 100 == 0) {
                    std::cout << year << " is not a leap year.";
                }
                // leap year if not divisible by 100
                // but divisible by 4
                else if (year % 4 == 0) {
                    std::cout << year << " is a leap year.";
                }
                // all other years are not leap years
                else {
                    std::cout << year << " is not a leap year.";
                };
            };
    };

	class LeapYearChoice : public ConsMenu::Choice {
        public:
            LeapYearChoice() : ConsMenu::Choice() {
                this->description = "Leap Year Checker";
                this->menu = std::make_unique<LeapYear>(LeapYear());
            };
	};
};



#endif
