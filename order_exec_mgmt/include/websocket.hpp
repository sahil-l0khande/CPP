#include "json.hpp"
#include <iostream>
#include <string>
#include <curl/curl.h>

class websocket {
	private:
		// Replace with your actual client credentials
		const std::string client_id ;
		const std::string client_secret;
	public:

		// CC
		websocket(std::string _cl_id, std::string _cl_secret) : client_id(_cl_id), client_secret(_cl_secret) {

		}

		void display_options();

		std::string get_access_token();
		void place_order(const std::string& price, const std::string& accessToken, const std::string& amount, const std::string& instrument);
		void cancel_order(const std::string& accessToken, const std::string& orderID);
		void modify_order(const std::string& ,const std::string&, std::string ,std::string);
		void get_order_book(const std::string& accessToken, const std::string& instrument);
		void get_position(const std::string& accessToken, const std::string& instrument);
		void get_open_orders(const std::string& accessToken);

};
