// Dell Alienware m18 R1 Gaming Laptop
#ifndef _LAPTOP_HPP
#define _LAPTOP_HPP

class laptop{
	private:
		//characteristics
		std::string brand;
		std::string manufacturer;
		unsigned int price;
		std::string colour;
		std::string item_model_no;
		std::string proc_brand;
		unsigned int ram;	// In GBs
		unsigned int ssd_size;	// In GBs
		std::string graphic_card;
		std::string os;

	public:
		laptop();

		void show_details();

		void set_details
			(
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
			);

};

#endif /* _LAPTOP_HPP */
