// Class for Samsung Galaxy S23 Ultra Smartphone

#include <cstdio>
#include <iostream>
class phone{
	private:
		struct phone_props{

			const char* os;
			unsigned int ram;
			struct dimentions{
				float length;
				float width;
				float height;
			} dims;

			unsigned int weight; // In gm 
			const char* model_no;
			const char* wireless_tech;
			const char* connectivity;
			const char* gps;
			const char* sp_features;
			const char* display;
			const char* oth_dis_features;
			const char* oth_cam_features;
			const char* form_factor;
			const char* colour;
			unsigned int bat_pow_rating;
			const char* manufacturer;
			const char* country;
			const char* asin;
			float review;
			unsigned int rank;
			const char* date_of_avail;
			unsigned int count;
			const char* generic_name;
		};

		struct phone_props new_phone;

	public:
		phone() : new_phone{
				"Android 13.0",
				12,
				{
					0.9,
					7.5,
					16.5
				},
				233,
				"SM-S918B",
				"Cellular",
				"Bluetooth, Wi-Fi, USB",
				"GLONASS",
				"Camera",
				"AMOLED",
				"Wireless",
				"Rear, Front",
				"Bar",
				"Green",
				5000,
				"Samsung India Electronics Pvt Ltd",
				"India",
				"B0BT9CXXXX",
				4.5,
				544,
				"2 February 2023",
				1,
				"Smartphone"
		} {}
		
		void show_product_details();
};

int main(void)
{
	printf("Technical details of Samsung S23 ultra smartphone\n");

	phone phone1;

	phone1.show_product_details();

	return 0;
}

void phone::show_product_details(){
	printf("phone::show_product_details()\n");

	printf("\nOperating system 		: %s", new_phone.os);
	printf("\nRam in GBs   			: %u", new_phone.ram);
	printf("\nLength of device		: %f", new_phone.dims.length);
	printf("\nwidth of device		: %f", new_phone.dims.width);
	printf("\nheight of device		: %f", new_phone.dims.height);
	printf("\nweight of device 		: %u", new_phone.weight);
	printf("\nModel Number			: %s", new_phone.model_no);
	printf("\nwireless technology		: %s", new_phone.wireless_tech);
	printf("\nconnectivity  technologies	: %s", new_phone.connectivity);
	printf("\nGPS				:      %s", new_phone.gps);
	printf("\nSpecial features 		: %s", new_phone.sp_features);
	printf("\ndisplay technology 		: %s", new_phone.display);
	printf("\nOther display features 	: %s", new_phone.oth_dis_features);
	printf("\nOther camera features		: %s", new_phone.oth_cam_features);
	printf("\nform factor 			: %s", new_phone.form_factor);
	printf("\ncolour 			: %s", new_phone.colour);
	printf("\nBattery power rating 		: %u", new_phone.bat_pow_rating);
	printf("\nmanufacturer 			: %s", new_phone.manufacturer);
	printf("\ncountry			: %s", new_phone.country);
	printf("\nasin  			: %s", new_phone.asin);
	printf("\nreview out of 5 		: %f", new_phone.review);
	printf("\nrank  			: %u", new_phone.rank);
	printf("\nDate first available 		: %s", new_phone.date_of_avail);
	printf("\nNet quantity 			: %u", new_phone.count);
	printf("\nGeneric name 			: %s\n", new_phone.generic_name);

}
