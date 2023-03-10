#ifndef CPPU_FILE
#define CPPU_FILE


#include <iostream>
#include <fstream>
#include <sstream>


namespace File {
    std::string read_str_file(std::string file_path) {
        std::ifstream file(file_path.c_str());

        std::stringstream str_stream;
        str_stream << file.rdbuf();
        return str_stream.str();
    }
}



#endif