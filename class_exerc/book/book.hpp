#include <cstdio>
#include <string>
class dimentions{
	friend class Book;
	private:
		double height;
		double length;
		double width;
	public:
		dimentions() : height(19.56), length(5.48), width(22.61) {
		}
};
class Book{
	private:
		std::string name;
		std::string author;
		unsigned int edition;
		unsigned int pages;
		unsigned int price;
		std::string publisher;
		std::string language;
		dimentions dim;

	public:
		Book(){
		
		}


		void get_details() const{
			printf("name:%s\n", name.c_str());
			printf("author:%s\n",author.c_str());
			printf("edition:%dth\n", edition);
			printf("pages:%d\n", pages);
			printf("price(In rupees):%d\n", price);
			printf("publisher:%s\n",publisher.c_str());
			printf("language:%s\n",language.c_str());
			printf("Dimentions :\n height : %.2f\t length: %.2f\t width(in cm): %.2f\n", dim.height, dim.length, dim.width); 
		}
		void set_details(){
				this->name = "C++";
				this->author = "Bjarne stroutrup";
				this->edition = 4;
				this->pages = 1376;
				this->price = 7351;
				this->publisher = "pearson";
				this->language = "English";
		}
};

