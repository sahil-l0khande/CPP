#include <cstdio>

class Date{
	private:
		int day, month, year;

		public:
			Date(); // Dedault CC

			Date(
					int init_day,
					int init_month,
					int init_year
			    );	// Parameterised CC

			// accessors for day, month, year

			int get_day();
			int get_month();
			int get_year();

			// mutators for day, month, year

			void set_day(int new_day);
			void set_month(int new_month);
			void set_year(int new_year);


			/// member function for displaying object
			// on the standard output device

			void show();
};

//DEFAULT CC
Date::Date() : day(1), month(1), year(2024) {
}

// parameterised CC
Date::Date(
		int init_day,
		int init_month,
		int init_year
	  )	: day(init_day),
	month(init_month),
	year(init_year){

	}

int Date::get_day(){
	return this->day;
}

int Date::get_month(){
	return this->month;
}

int Date::get_year(){
	return this->year;
}

void Date::set_day(int new_day){
	this->day = new_day;
}

void Date::set_month(int new_month){
	this->month = new_month;
}

void Date::set_year(int new_year){
	this->year = new_year;
}

void Date::show() {
	printf("%d/%d/%d\n", day, month, year);
}

int main(void){
	Date epochDate;
	Date myBirthDate(8,3,2002);

	epochDate.show();
	myBirthDate.show();

	return 0;
}
