class C{
	private:
		int i_num;
		double d_num;
		C(int _n, double _d) : i_num(_n), d_num(_d) {
		}

	public:
		static C* get_instance() {
			return new C(0, 0.0);
		}
};

void test_function(void);

int main(void) {
	test_function();
	return (0);
}

void test_function(void)
{
	// if we try to create the instance it will give error because constructor is in private so we have to use function
	//C obj(100, 2.32); error
	//C* pT = new C(200, 3.14); error
	C* pC = C::get_instance();
	delete pC;
	pC = 0;
}

