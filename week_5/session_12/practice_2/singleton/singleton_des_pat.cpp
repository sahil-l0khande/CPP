#include <iostream>
#include <stdexcept>

class Singleton {
	private:
		int i_num;
		double d_num;

		Singleton(int _n, int _d) : i_num(_n), d_num(_d) {
		
		}
		
		static int obj_cnt;

	public:

		static Singleton* get_instance(int _n, double _d) {
			++obj_cnt;

			if(obj_cnt > 1)
				throw std::runtime_error("Only one object can be created of this class");

			return new Singleton(_n, _d);
		}
};

int Singleton::obj_cnt = 0;

void test_singleton(void);

int main(void)
{
	test_singleton();

	return (0);

}

void test_singleton(void)
{
	Singleton* p_sin = Singleton::get_instance(100, 2.13);
	std::cout << "First object of singleton class is created" << std::endl;

	try {
		Singleton* p_sin = Singleton::get_instance(200, 3.14);
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	delete p_sin;
	p_sin = 0;
}


