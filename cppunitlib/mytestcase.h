#include <vector>

#include "testsuite.h"
#include "matchers.h"

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

    std::vector<UnitTest> tests() {
        return {test1(), test2()};
    }
};