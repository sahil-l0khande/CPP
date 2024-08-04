// This source code prints the addresses of data members of
// calling object

#include <cstdio>

class Date{
	private:
		int day;
		int month;
		int year;
	public:
		void show_member_function(){
			puts("Date::show_member_addresses() -> entered");

			printf("Address of a calling obj
