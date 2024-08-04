#include <cstdio>

class Date{
	private:

		int day;
		int month;
		int year;

	public:
		// mutators
		
		void set_day(int new_day){
			this->day = new_day;
		}

		void set_month(int new_month){
			this->month = new_month;
		}

		void set_year(int new_year){
			this->year = new_year;
		}

		// accessors
		
		int get_day() {
			return this->day;
		}

		int get_month(){
			return this->month;
		}

		int get_year(){
			return this->year;
		}

};

int main(void){

	Date myDate;

	// garbage value in object
	
	int dd, mm, yy;

	dd = myDate.get_day();
	mm = myDate.get_month();
	yy = myDate.get_year();

	printf("%d/%d/%d\n", dd, mm, yy);

	// Mutators
	

	myDate.set_day(8);
	myDate.set_month(3);
	myDate.set_year(2002);

	// again access
	
	dd = myDate.get_day();
	mm = myDate.get_month();
	yy = myDate.get_year();

	printf("%d/%d/%d\n", dd, mm, yy);

	return (0);
}

