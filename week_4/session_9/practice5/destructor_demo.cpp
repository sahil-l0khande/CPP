#include <cstdio>

class Test{
	private:
		int num;
		char c;
		float f_num;
	public:
		Test(){
			puts("In Test::Test()");	//ctor
			printf("Test::Test():this = %llu\n",
					(unsigned long long)this);
		}

		~Test(){
			puts("In Test::~Test()");	//dtor
			printf("Test::~Test():this = %llu\n",
					(unsigned long long)this);
		}
};

int main(void){

	Test* pTest = 0;

	pTest = new Test;

	delete pTest;
	pTest = 0;

	return 0;
}