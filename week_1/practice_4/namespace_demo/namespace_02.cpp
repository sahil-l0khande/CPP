#include <stdio.h>

namespace X{
    int num;
    float f_num;

    struct date {
        int day;
        int month;
        int year;
    };

    struct date mydate;

    void test(void) {

    } 

    class cdate{

    };

    namespace Y{
        double x;
    }
}

int main(void) {
    X::num = 100;
    X::f_num = 3.14;

    X::date mydate;
    X::cdate mycdate;
    X::mydate.day = 1;
    X::test();

    X::Y::x = 4.4;

    printf("Struct in namespace [%d]\n", X::mydate.day);

    printf("Nested namespaces [%.2f]\n", X::Y::x);

    return 0;
}