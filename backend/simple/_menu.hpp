#ifndef BACKEND_SIMPLE__MENU
#define BACKEND_SIMPLE__MENU



#include <memory>

#include "../../menu/_init.hpp"
#include "./hello_world.hpp"



namespace Simple {
    class SimpleMenu : public ConsMenu::SelectMenu {
        public:
            SimpleMenu() : ConsMenu::SelectMenu() {
                this->title = "Simple Programs";
                this->desc = "Simple programs to start off your journey.";

                this->choices.push_back(std::make_unique<HelloWorldChoice>(HelloWorldChoice()));
            };
    };

    class SimpleChoice : public ConsMenu::Choice {
        public:
            SimpleChoice() : ConsMenu::Choice() {
                this->description = "Simple Programs";
                this->menu = std::make_unique<SimpleMenu>(SimpleMenu());
            };
    };
};



#endif