#include <cstdio>

class Test{
	private:
		int num;
		char c;
		float f_num;

	public:
		Test(){
			puts("In Test::Test()");
			printf("Test::Test():this:%llu\n",
					(unsigned long long)this);
		}

		~Test(){
			puts("In Test::~Test()");
			printf("Test::~Test():this:%llu\n",
					(unsigned long long)this);
		}
};

int main(void) {
	Test* pTest = 0;

	pTest  = new Test;

	printf("main():ptest:%llu\n", (unsigned long long)pTest);

	delete pTest;
	pTest = 0;

	return 0;
}
