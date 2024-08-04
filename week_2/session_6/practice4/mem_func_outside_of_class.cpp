#include <cstdio>

class Date{
	private:
		int day;
		int month;
		int year;

	public:
		Date(int init_day, int init_month, int year);

		void show();
		int get_day();
		int get_month();
		int get_year();

		void set_day(int new_day);
		void set_month(int new_month);
		void set_year(int new_year);

};


Date::Date(int init_day, int init_month, int init_year) : day(init_day),
	month(init_month),
	year(init_year)
{
}

int Date::get_day(){
	return day;
}

int Date::get_month(){
	return month;
}

int Date::get_year(){
	return year;
}

void Date::show(){
	printf("%d/%d/%d\n", day, month, year);
}

void Date::set_day(int new_day){
	day = new_day;
}

void Date::set_month(int new_month){
	month = new_month;

}

void Date::set_year(int new_year) {
	year = new_year;
}

int main(void) {
	Date myDate(0,0,1000);

	myDate.show();
	myDate.set_day(8);
	myDate.set_month(3);
	myDate.set_year(2024);

	myDate.show();

	return (0);
}

