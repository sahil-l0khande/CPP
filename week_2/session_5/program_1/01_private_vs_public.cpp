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
    //FRAGMENT 1
    Date_1 my_date1;
    printf("Sizeof(myDate):%lu\n", sizeof(my_date1));

    my_date_1.day = 1;    //compile time error
    //my_date_1.month = 1;  //Compile time error
    //my_date.year = 1970;  //Compile time error
}

void test2(void){
    //FRAGMENT 2
    Date_2 my_date2;

    printf("Sizeof(my_date2):%lu\n", sizeof(my_date2));

    my_date2.day = 1;
    my_date2.month = 1;
    my_date2.year = 2024;
}