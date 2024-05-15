#include <stdio.h>

namespace X{
    int num;
    float f_num;

    struct Date {
        int day;
        int month;
        int year;
    };

    struct Date myDate;

    void test(void) {

    }

    class CDate {

    };

    namespace Y{
        double x;
    }
}


int main()
{
    X::num = 100;
    X::f_num = 3.14;

    X::Date myDate;
    X::CDate myCDate;
    X::myDate.day = 1;
    X::test();

    X::Y::x = 4.4;

    printf("Struct in namespace [%d]\n", X::myDate.day);

    printf("Nested namespaces [%.1f]\n", X::Y::x);

    return 0;
}