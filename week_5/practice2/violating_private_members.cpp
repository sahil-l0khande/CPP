#include <cstdio>

class Date{
	private:
		int day;
		int month;
		int year;
	public:
		Date(int _day, int _month, int _year) : day(_day),
		month(_month),
		year(_year) {

		}

		void show(){
			printf("%d/%d/%d\n", day, month, year);
		}

};

int main(void){
	Date myDate(10, 5, 2012);

	myDate.show();

	// myDate.day = 27;
	// myDate.month = 2;
	// myDate.year = 2002;
	
	*reinterpret_cast<int*>(reinterpret_cast<char*>(&myDate) + 0) = 28;
	*reinterpret_cast<int*>(reinterpret_cast<char*>(&myDate) + 4) = 2;
	*reinterpret_cast<int*>(reinterpret_cast<char*>(&myDate) + 8) = 2008;

	myDate.show();

	return (0);
}

