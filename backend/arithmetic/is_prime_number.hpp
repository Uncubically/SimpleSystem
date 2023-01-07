#ifndef BACKEND_ARITHMETIC_ISPRIMENUMBER
#define BACKEND_ARITHMETIC_ISPRIMENUMBER



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Arithmetic {
    class IsPrimeNumber : public ProgramMenu {
        public:
            IsPrimeNumber() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "arithmetic/is_prime_number_title.txt");
                this->desc = "Checks if the number is prime.";
            };

            void run_program() override {
                short int n;
                bool is_prime = true;

                std::cout << "Enter a positive integer: ";
                std::cin >> n;

                // 0 and 1 are not prime numbers
                if (n == 0 || n == 1) {
                    is_prime = false;
                }

                // loop to check if n is prime
                for (int i = 2; i <= n/2; ++i) {
                    if (n % i == 0) {
                        is_prime = false;
                        break;
                    }
                }

                if (is_prime) std::cout << n << " is a prime number";
                else std::cout << n << " is not a prime number";
            };
    };

	class IsPrimeNumberChoice : public ConsMenu::Choice {
        public:
            IsPrimeNumberChoice() : ConsMenu::Choice() {
                this->description = "Prime Number Checker";
                this->menu = std::make_unique<IsPrimeNumber>(IsPrimeNumber());
            };
	};
};



#endif
