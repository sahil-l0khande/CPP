#include <cstdio>

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        // member function
        void test_function1(){
            puts("Inside Date::test_function1()");
        }

        // member function
        void test_function2(){
            puts("Inside Date::test_function2()");
            printf("address of the calling object:addr(this):%llu\n",
                        (unsigned long long)this);
        }
};

void test1(void);
void test2(void);

int main(void){
    test1();
    test2();

    return (0);
}

void test1(void){
    Date my_date1;
    Date my_date2;

    my_date1.test_function1();
    my_date2.test_function1();
}

void test2(void){
    Date my_date1;
    Date my_date2;

    printf(
        "test2():addr(&my_date1):%llu\n",
        (unsigned long long)&my_date1
    );

    printf(
        "test2():addr(&my_date2):%llu\n",
        (unsigned long long)&my_date2
    );

    puts(
        "Making calls to my_date1.test_function2()\
        and my_date2.test_function2()"
    );

    my_date1.test_function2();
    my_date2.test_function2();
}