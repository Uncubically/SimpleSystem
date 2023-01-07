#ifndef BACKEND_PROGRAMMENU
#define BACKEND_PROGRAMMENU



#include "../cpp_utils/_init.hpp"
#include "../menu/_init.hpp"



class ProgramMenu : public ConsMenu::Menu {
    public:
        virtual void run_program() {};

        void show() override {
            Console::clear_console();
            ConsMenu::Menu::show_header();

            Console::flush_streams();

            this->run_program();
            std::cout << std::endl << std::endl << std::endl;

            if (std::cin.fail()) {
                Console::Color::SpecStyle error_spec(false, Console::Color::black, Console::Color::red, true);
                std::cout << error_spec.get_str() << "The input created an error." << std::endl;
                Console::flush_streams();
            };
            Console::enter_to_exit();
        }
};



#endif