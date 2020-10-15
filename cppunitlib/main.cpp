#include "mytestcase.h"
#include "anothertestcase.h"

int main() {

    MyTestCase ts1("MyTestCase");
    ts1.run();

    AnotherTestCase ts2("AnotherTestCase");
    ts2.run();

    return 0;
}