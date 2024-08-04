#include <iostream>
#include "laptop.hpp"

int main(void) {

	laptop* newLaptop = new laptop;

	newLaptop->show_details();

	newLaptop->set_details
		(

		 "Dell Alienware m18 R1",
		 "Dell INDIA",
		 366049,
		 "Dark Metalic Moon",
		 "alienware",
		 "Intel Core i9",
		 32,
		 1,
		 "NVIDIA GeForce RTX 4080 Dedicated GDDR6 12 GB",
		 "Windows 11 - Home"
		);


	newLaptop->show_details();

	return  (0);
}
		 
