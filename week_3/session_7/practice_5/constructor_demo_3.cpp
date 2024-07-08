#include <cstdio>

/*
	struct Date{
		int day;
		int month;
		int year;
	};
	
	void test(void){
		int n = 10;
		struct Date myDate = {1, 1, 1900};
		struct Date myBirthDate = {8, 3, 2002};

	}

*/

class Date{
	private:
		int day;
		int month;
		int year;

	public:
		Date(int init_day, int init_month, int init_year){
			this->day = init_day;
			this->month = init_month;
			this->year = init_year;
		}

		void show(){
			printf("Date::show():addr(this):%llu\n",
					(unsigned long long)this
			      );
			printf("%d/%d/%d\n", this->day, this->month, this->year);
		}
};

int main(void)
{
	Date myDate(1, 1, 1900);
	Date myBirthDate(8, 3, 2002);

	myDate.show();
	myBirthDate.show();

	return (0);
}
