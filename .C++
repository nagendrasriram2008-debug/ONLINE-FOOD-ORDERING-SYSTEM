#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class FoodItem {
public:
    string name;
    double price;

    FoodItem(string n, double p) {
        name = n;
        price = p;
    }
};

class Order {
private:
    vector<FoodItem> cart;
    double total = 0;

public:
    void addItem(FoodItem item) {
        cart.push_back(item);
        total += item.price;
    }

    void displayBill() {
        cout << "\n===== BILL =====\n";
        for (int i = 0; i < cart.size(); i++) {
            cout << cart[i].name << " - Rs." << cart[i].price << endl;
        }
        cout << "-----------------\n";
        cout << "Total Amount: Rs." << fixed << setprecision(2) << total << endl;
    }
};

int main() {
    vector<FoodItem> menu;

    menu.push_back(FoodItem("Burger", 120));
    menu.push_back(FoodItem("Pizza", 250));
    menu.push_back(FoodItem("Sandwich", 80));
    menu.push_back(FoodItem("Cold Drink", 40));

    Order order;
    int choice;

    do {
        cout << "\n===== ONLINE FOOD ORDERING SYSTEM =====\n";
        cout << "1. Burger - Rs.120\n";
        cout << "2. Pizza - Rs.250\n";
        cout << "3. Sandwich - Rs.80\n";
        cout << "4. Cold Drink - Rs.40\n";
        cout << "0. Finish Order\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            order.addItem(menu[choice - 1]);
            cout << "Item added successfully!\n";
        }
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    order.displayBill();

    return 0;
}
