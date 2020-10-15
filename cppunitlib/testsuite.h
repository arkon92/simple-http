#include <iostream>
#include <string>
#include <vector>

#include "unittest.h"

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

class TestSuite {

public:

    TestSuite() = delete;

    TestSuite(std::string n) : _name(n), _succeedTests(0), _failedTests(0) {}

    virtual std::vector<UnitTest> tests() = 0;

    void run() {
        for (auto t: tests()) {
            t.run();
            if (t.succeed()) {
                ++_succeedTests;
            } else {
                ++_failedTests;
            }
        }
        std::cout << "Tests run for " << _name << ": " << tests().size();
        std::cout << ". Succeed: " << _succeedTests;
        std::cout << " Failed: " << _failedTests << std::endl;
    }

private:
    std::string _name;
    int _succeedTests;
    int _failedTests;
};

#endif