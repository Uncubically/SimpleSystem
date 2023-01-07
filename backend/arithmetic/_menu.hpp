#ifndef BACKEND_ARITHMETIC__MENU
#define BACKEND_ARITHMETIC__MENU



#include <memory>

#include "../../menu/_init.hpp"

#include "./is_prime_number.hpp"
#include "./mdas.hpp"
#include "./mult_table.hpp"
#include "./number_factor.hpp"
#include "./odd_even.hpp"



namespace Arithmetic {
    class ArithmeticMenu : public ConsMenu::SelectMenu {
        public:
            ArithmeticMenu() : ConsMenu::SelectMenu() {
                this->title = "Arithmetic";
                this->desc = "Programs related to math.";

                this->choices.push_back(std::make_unique<MdasChoice>(MdasChoice()));
                this->choices.push_back(std::make_unique<OddEvenChoice>(OddEvenChoice()));
                this->choices.push_back(std::make_unique<MultTableChoice>(MultTableChoice()));
                this->choices.push_back(std::make_unique<NumberFactorChoice>(NumberFactorChoice()));
                this->choices.push_back(std::make_unique<IsPrimeNumberChoice>(IsPrimeNumberChoice()));
            };
    };

    class ArithmeticChoice : public ConsMenu::Choice {
        public:
            ArithmeticChoice() : ConsMenu::Choice() {
                this->description = "Arithmetic";
                this->menu = std::make_unique<ArithmeticMenu>(ArithmeticMenu());
            };
    };
};



#endif