#include <cstdio>

class Date_1{
	private:
		int day;
		int month;
		int year;
	public:
		Date_1() : day(3), month(5), year(1999){
		}

		void show(){
			printf("%d/%d/%d\n", this->day, this->month, this->year);
		}
};

class Date_2{
	private:
		int day;
		int month;
		int year;

	public:
		Date_2(int init_day, int init_month, int init_year) : day(init_day),
		month(init_month),
		year(init_year)
	{
	}

		void show(){
			printf("%d/%d/%d\n", this->day, this->month, this->month);
		}
};

int main(void){
	Date_1 myDate;	// Date_1::Date_1(&myDate)
	Date_2 myBirthDate(2, 6, 2002);	// Date_2::Date_2(&myBirthDate, 2, 6, 2002)
	myDate.show();	// Date_1::show(&myDate)\

	myBirthDate.show();	// Date_2::show(&myDate_2)

	return 0;
}
