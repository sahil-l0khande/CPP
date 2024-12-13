#include <cstdio>

class C1{
	friend class C2;
	private:
		int i_num;
		double d_num;
	public:
		C1() : i_num(100), d_num(3.1415){
		}
};

C1 gobj;

class C2{
	private:
		int x, y;
		double p,q;

	public:
		C2() : x(0), y(0), p(0), q(0) {

		}

		void print_ints() {

			printf("%d, %d\n", x, y);
			printf("gobj:%d, %.3lf\n", gobj.i_num, gobj.d_num);
		}


		static void some_func(int a, int b) {
			printf("my arguments:a:%d, b:%d\n", a, b);
			gobj.i_num = 500;
			gobj.d_num = 6.9889;
		}
};

