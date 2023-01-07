#ifndef MENU
#define MENU



#include <iostream>
#include <string>
#include <vector>

#include "../cpp_utils/_init.hpp"


namespace ConsMenu {

    class Menu {
        public:
            bool is_main_menu = false;

            std::string title;
            Console::Color::SpecStyle title_specstyle = Console::Color::SpecStyle(false, Console::Color::white, Console::Color::black, true);
            std::string desc;
            Console::Color::SpecStyle desc_specstyle = Console::Color::SpecStyle();

            std::string border = "+---==---";
            Console::Color::SpecStyle border_specstyle = Console::Color::SpecStyle(false, Console::Color::blue, Console::Color::black);
            Console::Color::GenStyle base_color;


            Menu() {};


            void show_border() {
                Console::Color::SpecStyle base = Console::Color::SpecStyle::from_genstyle(this->base_color);
                std::string new_border = Console::Size::get_fill_hor(this->border, Console::Size::get_size());
                std::cout << this->border_specstyle.get_str() << new_border << base.get_str() << std::endl;
            };


            void show_header() {
                Console::Color::SpecStyle base = Console::Color::SpecStyle::from_genstyle(this->base_color);

                this->show_border();
                std::cout
                    << this->title_specstyle.get_str() << this->title << std::endl
                    << this->desc_specstyle.get_str() << this->desc << std::endl;
                this->show_border();
                std::cout << base.get_str() << std::endl;
            };

            virtual void show() {
                this->base_color.set_console_color();
                this->show_header();
            };
    };

};



#endif
