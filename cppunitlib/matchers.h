#include <string>
#include <sstream>


#ifndef MATCHERS_H
#define MATCHERS_H

template<typename T>
void assertEquals(const T &expected, const T &computed) {
    if (expected != computed) {
        std::stringstream errorMsg("");
        errorMsg << "Assertion exception! Expected: ";
        errorMsg << expected << " Got: " << computed;
        throw std::string(errorMsg.str());
    }
}

#endif