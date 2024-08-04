#include <iostream>
#include "laptop.hpp"

//default CC

laptop::laptop() :
	brand("empty"),
	price(0),
	manufacturer("empty"),
	os("empty"),
	graphic_card("empty"),
	ssd_size(0),
	ram(0),
	proc_brand("empty"),
	item_model_no("empty"),
	colour("empty")
{


}


void laptop::set_details (

		std::string _brand,
		std::string _manufacturer,
		unsigned int _price,
		std::string _colour,
		std::string _item_model_no,
		std::string _proc_brand,
		unsigned int _ram,       // In GBs
		unsigned int _ssd_size,  // In GBs
		std::string _graphic_card,
		std::string _os
		)
{
	this->brand = _brand;
	this->manufacturer = _manufacturer;
	this->price = _price;
	this->colour = _colour;
	this->item_model_no = _item_model_no;
	this->proc_brand = _proc_brand;
	this->ram = _ram;
	this->ssd_size = _ssd_size;
	this->graphic_card = _graphic_card;
	this->os = _os;
}

void laptop::show_details()
{
	std::cout << " Product details of Dell Alienware LAPTOP : " << std::endl;
	std::cout << "Brand 					: " << brand << std::endl;
	std::cout << "Manufacturer 				:" << manufacturer << std::endl;
	std::cout << "Price 					:" << price << std::endl;
	std::cout << "colour 					:" << colour << std::endl;
	std::cout << "Item model number 			:" << item_model_no << std::endl;
	std::cout << "Processor 				: " << proc_brand << std::endl;
	std::cout << "Ram in GB 				: " << ram << std::endl;
	std::cout << "Hard disk size (in GB/TB)			: " << ssd_size << std::endl;
	std::cout << "Graphic card				: " << graphic_card << std::endl;
	std::cout << "Operating system 				: " << os << std::endl;

	std::cout << std::endl;
}
	

