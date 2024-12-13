#include <cstdio>
#include <cstdlib>

void test_function_1(void);
void test_function_2(void);

const int  gc_num = 100;	// GLOBAL + CONST
int g_num;	// GLOBAL

int main(void){
	test_function_1();
	test_function_2();

	return 0;
}

void test_function_1(void){

	int m1, m2, m3;
	int* p1;	// non-const pointer to non-const data

	p1 = &m1;	// through p1, m1 can be r/w 
			// p1 = &m2; p1 = &m3;
			// through p1, m2 and m3 can be r/w
	
	const int* p2 = &m2;	// through p2, m2 can be r and not w
	int const* p3 = &m3;	// through p3, m3 can be r an not w

	// p2 = &m1;	p2 = &m3;	is possible because the pointer itself is not const
	// p3 = &m1; p3 = &m2 SAME  HERE 
	
	int* const p4 = &m1;	// through p4, m1 can be r/w
				// p4 = &m2; p4 = &m3 is not possible because p4 
				// is a const pointer
	
	const int* const p5 = &m1;	// through p5, m1 can be r not w
					// p5 = &m2; p5 = &m3; is not possible 
					// because p5 is a const pointer

}

void test_function_2(void){
	int l_num;
	const int lc_num = 200;


	int* p1 = &lnum;
	p1 = &gc_num;

	const int* p2;

	p2 = &g_num;
	p2 = &l_num;
	p2 = &gc_num;
	p2 = &lc_num;

	int* const p3 = &l_num; // rw
	int* const p4 = &g_num;	// rw

	const int* const p5 = &l_num;
	const int* const p6 = &g_num;
	const int* const p7 = &lc_num;
	const int* const p8 = &gc_num;
}
