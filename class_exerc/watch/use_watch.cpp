#include "watch.hpp"


int main(void){
	Watch* myWatch = new Watch;

    printf("BEFORE===>\n\n\n");
	myWatch->show_specification();

    printf("\n\nAFTER===>\n\n");
	myWatch->set_specification(
			"RADO",
			"HyperChrome Automatic Chronograph Limited Edition",
			"Male",
			482000,
			{
			"Plasma High-Tech Ceramic",
			13.0,
			10,
			"dark",
			45,
			"Sapphire crystal with anti-reflective coating on both sides"
			},
			{
			"Grey"
			},
			"Plasma High-Tech Ceramic"
			);
	myWatch->show_specification();

	delete myWatch;
	return (0);
}
