#include <iostream>
#include <stdexcept>

class single {
	private:
		int dd, mm;

		single(int _dd, int _mm) : dd(_dd), mm(_mm) {

		}

		static int cnt;
	public:
		static single* get_instance(int _d, int _m) {

			++cnt;

			if(cnt > 1)
				throw std::runtime_error("Only one object can be created of this class");
			
			return new single(_d, _m);
		}

};

int single::cnt = 0;

void test_single(void);

int main(void)
{
	test_single();

	return (0);
}

void test_single(void)
{
	single* first = single::get_instance(100, 200);

	std::cout << "First obj is created" << std::endl;

	try { 
		single* second = single::get_instance(300,400);
	} catch(std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	delete first;
	first = 0;
}

