#ifndef BACKEND_ALGORITHMS_LARGESTELEMENT
#define BACKEND_ALGORITHMS_LARGESTELEMENT



#include <iostream>
#include <memory>

#include "../../menu/_init.hpp"

#include "../program_menu.hpp"
#include "../path.hpp"



namespace Algorithms {
	class LargestElement : public ProgramMenu {
        public:
            LargestElement() : ProgramMenu() {
                this->title = File::read_str_file(backend_path + "algorithms/largest_element_title.txt");
                this->desc = "Picks the largest element of a list.";
            };

            void run_program() override {
				int i, n;
				float arr[100];

				std::cout << "Enter total number of elements(1 to 100): ";
				std::cin >> n;
				std::cout << std::endl;

				// Store number entered by the user
				for (i = 0; i < n; ++i) {
					std::cout << "Enter Number " << i + 1 << " : ";
					std::cin >> arr[i];
				}

				// Loop to store largest number to arr[0]
				for (i = 1;i < n; ++i) {
					// Change < to > if you want to find the smallest element
					if(arr[0] < arr[i])
						arr[0] = arr[i];
				}

				std::cout << std::endl << "Largest element = " << arr[0];
            };
    };

	class LargestElementChoice : public ConsMenu::Choice {
        public:
            LargestElementChoice() : ConsMenu::Choice() {
                this->description = "Largest Element";
                this->menu = std::make_unique<LargestElement>(LargestElement());
            };
	};
};



#endif
