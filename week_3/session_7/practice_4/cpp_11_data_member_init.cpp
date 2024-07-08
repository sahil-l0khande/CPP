#include <cstdio>

class Date{
	private:
		int day = 1;
		int month = 1;
		int year = 1999;

	public:
		void show(){
			printf("%d/%d/%d\n", 
					day, month, year);
		}
};

int main(void)
{
	Date myDate;

	myDate.show();

	return (0);
}
