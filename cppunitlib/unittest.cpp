#include <iostream>
#include <string>

#include "unittest.h"

using namespace std;

template<typename T>
void assertEquals(const T &expected, const T &computed) {
    if (expected != computed) {
        stringstream errorMsg("");
        errorMsg << "Assertion exception! Expected: ";
        errorMsg << expected << " Got: " << computed;
        throw string(errorMsg.str());
    }
}

class TestSuite {

public:

    TestSuite() = delete;

    TestSuite(string n) : _name(n), _succeedTests(0), _failedTests(0) {}

    virtual vector<UnitTest> tests() = 0;

    void run() {
        for (auto t: tests()) {
            t.run();
            if (t.succeed()) {
                ++_succeedTests;
            } else {
                ++_failedTests;
            }
        }
        cout << "Tests run for " << _name << ": " << tests().size();
        cout << ". Succeed: " << _succeedTests;
        cout << " Failed: " << _failedTests << endl;
    }

private:
    string _name;
    int _succeedTests;
    int _failedTests;
};

class MyTestCase : public TestSuite {
    using TestSuite::TestSuite;

    UnitTest test1() {
        return UnitTest(
            "Some test that must succeed",
            []() {
                assertEquals(true, true);
            }
        );
    }

    UnitTest test2() {
        return UnitTest(
            "Some test that must fail",
            []() {
                assertEquals(1, -6);
            }
        );
    }

    vector<UnitTest> tests() {
        return {test1(), test2()};
    }
};

class AnotherTestCase : public TestSuite {
    using TestSuite::TestSuite;

    UnitTest test1() {
        return UnitTest(
            "Some test to compare strings",
            []() {
                assertEquals("true", "true");
            }
        );
    }

    vector<UnitTest> tests() {
        return {test1()};
    }
};

int main() {

    MyTestCase ts1("MyTestCase");
    ts1.run();

    AnotherTestCase ts2("AnotherTestCase");
    ts2.run();

    return 0;
}