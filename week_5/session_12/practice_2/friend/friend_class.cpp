#include <cstdio>

class C1 {
	friend class C2;
	private:
		int i_num;
		double d_num;

	public:
		C1() : i_num(100), d_num(3.14) {
		}

};

C1 gobj;

class C2 {
	private:
		int x, y;
		double p, q;
	public:
		C2() : x(0), y(0), p(0.0), q(0.0) {

		}

		void print_ints() {
			printf("%d, %d\n", x, y);
			printf("gobj: %d, %.3lf\n", gobj.i_num, gobj.d_num);
		}

		void print_double() {
			printf("%.3lf, %.3lf\n", p, q);
			printf("gobj:%d, %.3lf\n", gobj.i_num. gobj.d_num);
		}

		static void some_func(int a, int b) {
			printf("my arguments:a:%d, b:%d\n", a, b);
			g_obj.i_num = 500;
			g_obj.d_num = 6.9889;
		}
};

