#include <iostream>
#include <cstdio>
class gcard{

	friend void set_details(gcard* obj);
	friend void show_details(gcard* obj);
	private:
		std::string g_co_processor;
		std::string card_interface;
		std::string g_ram_type;
		std::string op_interface;
		std::string manufacturer;
		unsigned int g_ram_size;
		unsigned int mem_clk_spd;
		unsigned int fan_cnt;

	public:
		gcard() {

		}

};

void set_details(gcard* obj);
void show_details(gcard* obj);

int main(void)
{
	gcard* gobj = new(gcard);

	set_details(gobj);

	show_details(gobj);

	delete(gobj);
	return 0;
}

void set_details(gcard* obj)
{
	obj->g_co_processor = "GeForce RTX 4060";
	obj->card_interface = "pciex16";
	obj->g_ram_type = "gddr6";
	obj->op_interface = "HDMI, DisplayPort";
	obj->manufacturer = "NVIDIA";
	obj->g_ram_size = 8;
	obj->mem_clk_spd = 17000;
	obj->fan_cnt = 3;
}

void show_details(gcard* obj)
{
	std::cout<< obj->g_co_processor<<std::endl;
	std::cout<< obj->card_interface<<std::endl;
	std::cout<< obj->g_ram_type<<std::endl;
	std::cout<< obj->op_interface<<std::endl;
	std::cout<< obj->manufacturer<<std::endl;
	printf("g_ram_size (in GB) : %d\n", obj->g_ram_size);
	printf("mem_clk_spd (in MHz): %d\n", obj->mem_clk_spd);
	printf("fan_cnt : %d\n", obj->fan_cnt);
}