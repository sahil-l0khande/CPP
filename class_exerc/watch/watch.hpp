#ifndef _WATCH_HPP_
#define _WATCH_HPP_

#include <cstdio>
#include <string>

class Case{
	friend class Watch;
	private:
			std::string material;
			double thickness;
			unsigned int water_resistance;
			std::string colour;
			double dimentions;
			std::string crystel;
	public:
	
	Case(std::string a, double b, unsigned int c, std::string d, double e, std::string f) : 
material(a),
thickness(b),
water_resistance(c),
colour(d),
dimentions(e),
crystel(f)
{

	}

};

class Dial{
	friend class Watch;
	private:
			std::string colour;
	public:
	
	Dial(std::string col) : colour(col) {

	}

	bool has_date();
	bool has_jewels();
};

// TODO Use friend function show() and DMA like new delete
 
class Watch{
	private:
		std::string name;
		std::string model_name;
		std::string gender;
		unsigned int price;
		Case Wcase;
		Dial dial;
		std::string strap;

	public:
		// default CC with initializer list
		Watch() :  
			name{"Empty"},
			model_name{"Empty"},
			gender{"Empty"},
			price{0},
			Wcase{"Empty", 0.0, 0, "empty", 0.0, "empty" },
			dial{"Empty"},
			strap{"Empty"} 
			{

			}
		
		void set_specification(
			std::string name,
			std::string model_name,
			std::string gender,
			unsigned int price,
			Case _Wcase,
            Dial _dial,
			std::string strap
		);
		void show_specification();
};


#endif /* _WATCH_HPP_ */
