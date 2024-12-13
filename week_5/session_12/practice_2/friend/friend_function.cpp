#include <cstdio>

class Date{
	friend void test_function(void);
	private:
		int day, month, year;

	public:
		Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {

		}

		void show() const {
			printf("%d-%d-%d\n", day, month, year);
		}
};

void test_function(void);

int main(void)
{
	test_function();
	return 0;
}

void test_function(void)
{
	Date pDate(8, 3, 2002);
	pDate.show();

	pDate.day = 1;
	pDate.month = 1;
	pDate.year = 2000;

	pDate.show();
}
