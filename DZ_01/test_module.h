#pragma once

#include <iostream>
#include <sstream>

#undef OUT
#define OUT

#undef UNUSED
#define UNUSED(X) (void)(X);


namespace utils {
   
    template <typename Out>
    void splitString(const std::string& s, char delim, Out result) {
        std::istringstream iss(s);
        std::string item;
        while (std::getline(iss, OUT item, delim)) {
            *result++ = item;
        }
    }

}

class TestModule {

public:
    static void lesson1_Task3();
};
