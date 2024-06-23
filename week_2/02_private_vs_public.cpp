#include <cstdio>

class Date_1{
    private:
        int day;
        int month;
        int year;
};

class Date_2{
    public:
        int day;
        int month;
        int year;   
};

void test1(void);
void test2(void);

int main(void){
    test1();
    test2();

    return (0);
}

void test1(void){
    Date_1 my_date1;

    printf("sizeof(my_date1):%lu\n", sizeof(my_date1));

    //my_date1.day = 1 // compile time error
    //my_date1.month = 1 // compile time error
    //my_date1.year = 2024  //compile time error

}

void test2(void){
    Date_2 my_date2;

    printf("Sizeof(my_date2):%lu\n", sizeof(my_date2));
    my_date2.day = 1;
    my_date2.month = 1;
    my_date2.year = 2024;
}