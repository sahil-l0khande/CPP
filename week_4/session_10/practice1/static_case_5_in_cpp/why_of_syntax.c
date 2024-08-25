struct Test{
	int m;
	int n;
};
/////////////////////

class Test{
	private:
		int m;
		static int n;
};

int Test::n;

class Date{
	private:
		int day = 1;
		int month = 1;
		int year = 1979;
};
