#ifndef BACKEND
#define BACKEND



#include "../menu/_init.hpp"

#include "./path.hpp"

#include "./credits.hpp"
#include "./algorithms/_menu.hpp"
#include "./arithmetic/_menu.hpp"
#include "./simple/_menu.hpp"


namespace Backend {
    class Menu : public ConsMenu::SelectMenu {
        public:
            Menu() : ConsMenu::SelectMenu() {
                this->is_main_menu = true;

                this->title = File::read_str_file(backend_path + "main_title.txt");
                this->desc = "A reviewer for all things C++ pre-midterm.";

                this->choices.push_back(std::make_unique<Simple::SimpleChoice>(Simple::SimpleChoice()));
                this->choices.push_back(std::make_unique<Arithmetic::ArithmeticChoice>(Arithmetic::ArithmeticChoice()));
                this->choices.push_back(std::make_unique<Algorithms::AlgorithmsChoice>(Algorithms::AlgorithmsChoice()));
                this->choices.push_back(std::make_unique<CreditsChoice>(CreditsChoice()));
            };
    };
}



#endif