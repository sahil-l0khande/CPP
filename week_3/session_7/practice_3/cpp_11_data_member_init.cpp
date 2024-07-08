#include <cstdio>

class Date{
	private:
		int day  = 8;
		int month = 3;
		int year = 2002;
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
