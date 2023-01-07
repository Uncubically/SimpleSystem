#ifndef BACKEND_CREDITS
#define BACKEND_CREDITS



#include <iostream>
#include <memory>

#include "../menu/_init.hpp"

#include "./path.hpp"



namespace Backend {
    class Credits : public ConsMenu::Menu {
        public:
            Credits() : ConsMenu::Menu() {
                this->title = "Credits";
                this->desc = "List of people who contributed to this program.";
            };

            void show() override {
                ConsMenu::Menu::show_header();

                std::string source = File::read_str_file(backend_path + "credits.txt");

                Console::Anim::Typewriter(4, source).run();

                Console::enter_to_exit();
            };
    };

    class CreditsChoice : public ConsMenu::Choice {
        public:
            CreditsChoice() : ConsMenu::Choice() {
                this->description = "Credits";
                this->menu = std::make_unique<Credits>(Credits());
            };
    };
};



#endif
