#include <iostream>
#include <string>

#include "unittest.h"
#include "matchers.h"
#include "testsuite.h"

std::string colorReset() {
    return "\033[0m";
}

void printSuccess(std::string msg) {
    const std::string green("\033[1;32m");
    std::stringstream acc(green);
    acc << msg;
    std::cout << green << acc.str() << colorReset() << std::endl;
}

void printErr(std::string const &errMsg) {
    const std::string red("\033[0;31m");
    std::stringstream acc(red);
    acc << errMsg;
    std::cout << red << acc.str() << colorReset() << std::endl;
}

void UnitTest::run() {
    try {
        _body();
        printSuccess(_description);
        _succeed = true;
    } catch (std::string const & err) {
        printErr(_description);
        printErr(err);
    }

}