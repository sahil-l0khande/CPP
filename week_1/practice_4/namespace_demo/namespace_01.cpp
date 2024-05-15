#include <stdio.h>

namespace X{
    int num = 500;
    float f_num;
}

int num;

int main(void) {
    printf("NUMBER  = %d\n", num);
    num = 1000;
    printf("NUMBER  = %d\n", num);

    X::num = 5000;

    printf("NUMBER  = %d\n", X::num);
    return 0;
}