#ifndef BASE_EXCEPTION
#define BASE_EXCEPTION



#include <iostream>


namespace Exc {
    class Exception {
        public:
            std::string message;

            Exception() {
                message = "";
            };
            Exception(std::string _message) {
                message = _message;
            };
    };


    class InvalidIndex : public Exception {
        public:
            InvalidIndex() : Exception("Invalid Index.") {};
    };

    class FailedInput : public Exception {
        public:
            FailedInput() : Exception("Input is not valid.") {};
    };
};



#endif