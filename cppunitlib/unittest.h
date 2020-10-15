#include <functional>
#include <string>
#include <sstream>

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

class UnitTest {

public:
    UnitTest() = delete;
    UnitTest(std::string d, std::function<void()> b):
        _succeed(false), _description(d), _body(b) {}
    bool succeed() const {return _succeed;}
    void run();

private:
    bool _succeed;
    std::string _description;
    std::function<void()> _body;
};

#endif