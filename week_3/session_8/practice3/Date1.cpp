#include <cstdio>

class Date{
	private:
		int day, month, year;
	public:
		// Default constructor
		Date() : day(1), month(1) , year(2024){
			
		}


		// Parameterised constructor
		Date(int init_day, int init_month, int init_year) : day(init_day),
		month(init_month),
		year(init_year){

		}

};
