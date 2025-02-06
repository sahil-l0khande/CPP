#include <iostream>

class car {
    private:
        std::string company; // shelby american
        std::string model;  // SHELBY MUSTANG GT350S
        unsigned int year; // 1966
        std::string gear;  // manual
        std::string exhaust;    // steel dual  
        std::string horsepower; // 406 hp
        double speed;   // km per hr 259.104 Kilometers per Hour
        unsigned int price;  // in inr

        // parameterized constructor
        car(std::string  _company,        // shelby american
            std::string  _model,  // SHELBY MUSTANG GT350S
            unsigned int _year,      // 1966
            std::string  _gear,        // manual
            std::string  _exhaust,    // steel dual  
            std::string  _horsepower, // 406 hp
            double       _speed,           // km per hr 259.104 Kilometers per Hour
            unsigned int _price 
            ) : company(_company),
                model(_model),   
                year(_year),   
                gear(_gear),   
                exhaust(_exhaust),   
                horsepower(_horsepower),   
                speed(_speed),   
                price(_price) {
                    
                }  
        static int car_cnt;
    
    public:
        static car* get_car(
            std::string  _company,        // shelby american
            std::string  _model,  // SHELBY MUSTANG GT350S
            unsigned int _year,      // 1966
            std::string  _gear,        // manual
            std::string  _exhaust,    // steel dual  
            std::string  _horsepower, // 406 hp
            double       _speed,           // km per hr 259.104 Kilometers per Hour
            unsigned int _price 
        ) {
            ++car_cnt;

            if(car_cnt > 1) {
                throw std::runtime_error("Only one car exist of this model");
            }

            return new car(_company,
                            _model,
                            _year,
                            _gear,
                            _exhaust,
                            _horsepower,
                            _speed,
                            _price );
        }


        void show() const { 
            std::cout << "Company: " << company << std::endl;
            std::cout << "Model: " << model << std::endl;
            std::cout << "Year: " << year << std::endl;
            std::cout << "Gear: " << gear << std::endl;
            std::cout << "Exhaust: " << exhaust << std::endl;
            std::cout << "Horsepower: " << horsepower << std::endl;
            std::cout << "Speed: " << speed << " km/h" << std::endl;
            std::cout << "Price (INR): " << price << std::endl;
        }
};

int car::car_cnt = 0;

void test_car   (void);
