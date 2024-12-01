#include <cstdio>

class Date {
	friend void test_function(void);

	private:
		int day, month, year;

	public:
		Date(int _day, int _month, int _year) : day(_day),
		month(_month), year(_year) {


		}

		void show() const {
			printf("%d-%d-%d\n", day, month, year);
		}
};

void test_function(void);

int main(void)
{
	test_function();
	return (0);
}

// Function can access members of class
void test_function(void)
{
	Date myDate(1, 1, 1970);
	myDate.show();
	myDate.day = 2;
	myDate.month  = 3;
	myDate.year = 2002;

	myDate.show();
}

