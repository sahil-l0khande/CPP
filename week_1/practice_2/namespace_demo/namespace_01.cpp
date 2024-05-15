#include <stdio.h>

namespace X{
    int num = 500;
    float f_num;
}

int num;

int main(void) {
    printf("NUMBER = %d\n", num);   // 0
    printf("NUMBER = %d\n", X::num); // 500

    X::num = 5000;

    printf("NUMBER = %d\n", X::num); // 5000

    return 0;
}