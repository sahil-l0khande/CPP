#include <iostream>
#include <stdexcept>

class Single {
	private:
		int dd, mm;

		Single(int _dd, int _mm) : dd(_dd), mm(_mm) {

		}

		static int obj_cnt;

	public:
		
		static Single* get_instance(int _dd, int _mm) {
			++obj_cnt;

			if(obj_cnt > 1) {
				throw std::runtime_error("Object can be created once ");
			} 


			return new Single(_dd, _mm);

		}

};

int Single::obj_cnt = 0;

void test_singleton()
{
	Single* obj = Single::get_instance(10, 20);


	std::cout << "One instance created" << std::endl;

	try {
	       Single* sin = Single::get_instance(100, 200);
	} catch (std::runtime_error& e) {
	
		std::cout << e.what() << std::endl;
	}

	delete obj;
	obj = 0;
}

int main(void)
{

	test_singleton();
	return (0);
}


