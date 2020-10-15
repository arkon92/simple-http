#include <vector>

#include "testsuite.h"
#include "matchers.h"

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

   std::vector<UnitTest> tests() {
        return {test1()};
    }
};