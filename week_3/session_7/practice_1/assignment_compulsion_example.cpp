#include <cstdio>
#include <cstdlib>
#include <cstring>

class Date{
	private:
		int day;
		int month;
		int year;
	public:
		Date(char date_str[]){
			const  char* sep = "/";
			char* str_day = strtok(date_str, sep);
			char* str_month = strtok(NULL, sep);
			char* str_year = strtok(NULL, sep);

			day = atoi(str_day);
			month = atoi(str_month);
			year = atoi(str_year);
		}

		void show(){
			printf("%d/%d/%d\n", this->day, this->month, this->year);
		}
};

int main(void){
	char date_str[] = "4/5/2024";

	Date myDate(date_str);
	myDate.show();

	return 0;
}

