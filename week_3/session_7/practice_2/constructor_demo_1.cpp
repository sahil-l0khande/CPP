#include <cstdio>

class Date{
    private:
        int day;
        int month;
        int year;
    public:
       	Date(){
		puts("Inside Date::Date()");
		printf("Date::Date()->Address in this ptr:%llu\n",
			(unsigned long long)this);
	}	
};


int main(void)
{
	Date myDate_1;
	printf("main():addr(myDate_1):%llu\n", (unsigned long long)&myDate_1);

	Date myDate_2;
	printf("main():addr(myDate_2):%llu\n", (unsigned long long)&myDate_2);

	Date myDate_3;
	printf("main():addr(myDate_3):%llu\n", (unsigned long long)&myDate_3);

	return (0);
}
