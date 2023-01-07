#include <iostream>
#include <stdio.h>
using namespace std;


int main() {
    system("color 0a");


    while (true) {
        system("cls");

        std::cout
            << "======================================" << endl
            << "James Chris Brown C++ Tutorial Program" << endl
            << "======================================" << endl
            << endl
            << "Please choose an appropriate choice." << endl
            << "[1] Hello World" << endl
            << endl
            << "[]> ";

        int input;
        std::cin >> input;


        system("cls");

        switch (input) {
            case 0:
                return 0;
            case 1:
                std::cout << "Hello world!";
                break;
            default:
                std::cout << "Input out of range.";
                break;
        };

        std::string __;
        std::cin >> __;
    }



    return 0;
}