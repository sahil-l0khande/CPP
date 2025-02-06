#include "websocket.hpp"
int main() {
	websocket order( "wSyMmkKO",  "0zulWkNKU6t8zeZhKmHDqGQRL6zCkw8E1_QGKyAJXXo");
	// Retrieve the access token
	std::string access_token = order.get_access_token();

	if (!access_token.empty())
	{
		std::string price;  // price to by at
		std::string amount; // How much amount to invest
		std::string instrument;
		std::string order_id;

		int choice;

		do {
			order.display_options();
			std::cin >> choice;

			switch (choice) {
				case 1:
					std::cout << " Enter <price> <amount> <instrument>" << std::endl;
					std::cin >> price >> amount >> instrument;
					order.place_order(price, access_token, amount, instrument);
					break;
				case 2:
					std::cout << " Enter <order id>" << std::endl;
					std::cin >> order_id;
					order.cancel_order(access_token, order_id);
					break;
				case 3:
					std::cout << " Enter <order id> <amount> <price>" << std::endl;
					std::cin >> order_id >> amount >> price;
					order.modify_order(access_token, order_id, amount, price);
					break;
				case 4:
					std::cout << " Enter <instrument>" << std::endl;
					std::cin >> instrument;
					order.get_order_book(access_token,instrument);
					break;
				case 5:
					std::cout << " Enter <instrument>" << std::endl;
					std::cin >> instrument;
					order.get_position(access_token, instrument);
					break;
				case 6:
					order.get_open_orders(access_token);
					break;
				case 0:
					std::cout << "Exiting ...!" << std::endl;
					break;
				default:
					std::cout << "Invalid choice. Please try again." << std::endl;
					break;
			}
		} while (choice != 0);

	} else {
		std::cerr << "Unable to obtain access token, aborting operations." << std::endl;
	}

	return 0;
}
