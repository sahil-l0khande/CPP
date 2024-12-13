#include "watch.hpp"

void Watch::set_specification(
		std::string _name,
		std::string _model_name,
		std::string _gender,
		unsigned int _price,
		Case _Wcase,
		Dial _dial,
		std::string _strap
		)
{
	this->name = _name;
	this->model_name = _model_name;
	this->gender = _gender;
	this->price = _price;
	this->Wcase = _Wcase;
	this->dial = _dial;
	this->strap = _strap;
}

void Watch::show_specification() {
	printf("name is : %s\n", name.c_str());
	printf("model_name is : %s\n", model_name.c_str());
	printf("gender is : %s\n", gender.c_str());
	printf("price (In rupees) is : %d\n", price);
	printf("Wcase is : \n\tmaterial : %s\n\tthickness (In mm): %.2f\n\twater_resistance (In bar) : %d\n\tcolour : %s\n\tdimention (In mm) : %.2f\n\tcrystel :  %s\n", 
			Wcase.material.c_str(),
			Wcase.thickness,
			Wcase.water_resistance,
			Wcase.colour.c_str(),
			Wcase.dimentions,
			Wcase.crystel.c_str());
	printf("dial is : %s\n", dial.colour.c_str());
	printf("strap is : %s\n", strap.c_str());
	printf("Dial has Date : %s\n", (dial.has_date() == true)? "Yes":"No");
	printf("Dial has Jewel : %s\n", (dial.has_jewels() == true)? "Yes":"No");
}

bool Dial::has_date(){
	return true;
}

bool Dial::has_jewels(){
	return true;
}
