#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
class InvalidChoice : public exception {
    string message;
public:
    InvalidChoice(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class MenuItem {
public:
    string name;
    double price;

    MenuItem(string n, double p) {
        name = n;
        price = p;
    }
};

class Order {
public:
    vector<MenuItem> items;
    vector<int> quantities;
    void add_item(MenuItem item, int quantity) {
        items.push_back(item);
        quantities.push_back(quantity);
    }
    double calculate_total() const {
        double total = 0;
        for (size_t i = 0; i < items.size(); ++i) {
            total += items[i].price * quantities[i];
        }
        return total;
    }
};
class Restaurant {
private:
    vector<MenuItem> menu;
public:
    Restaurant() {
        menu.push_back(MenuItem("Pizza", 10));
        menu.push_back(MenuItem("Burger", 9));
        menu.push_back(MenuItem("Pasta", 8));
        menu.push_back(MenuItem("Salad", 7));
    }
    void show_menu() const {
        cout << "\nMenu:\n";
        for (size_t i = 0; i < menu.size(); ++i) {
            cout << i + 1 << ". " << menu[i].name << " $" << menu[i].price << endl;
        }
    }
    Order take_order() {
        Order order;
        while (true) {
            show_menu();
            cout << "Enter menu item number (or 0 to finish): ";
            int choice;
            cin >> choice;
            if (choice == 0)
                break;
            if (choice < 1 || choice > static_cast<int>(menu.size()))
                throw InvalidChoice("Invalid menu item number!");
            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity;
            if (quantity <= 0)
                throw InvalidChoice("Quantity must be positive!");

            order.add_item(menu[choice - 1], quantity);
        }
        return order;
    }
    void print_receipt(const Order& order) const {
        cout << "\nReceipt:\n";
        for (size_t i = 0; i < order.items.size(); ++i) {
            const MenuItem& item = order.items[i];
            int qty = order.quantities[i];
            cout << item.name << " x " << qty << " = $" << item.price * qty << endl;
        }
        cout << "Total: $" << order.calculate_total() << endl;
    }
};
int main() {
    try {
        Restaurant restaurant;
        Order customer_order = restaurant.take_order();
        restaurant.print_receipt(customer_order);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}