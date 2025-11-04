#include <iostream>
#include <string>
using namespace std;

class Product {
private:
  int id;
  string name;
  int quantity;
  double price;

public:
  Product(int pid, string pname, int qty, double p){
    id = pid;
    name = pname;
    quantity = qty;
    price = p;
  }

  void display(){
    cout << "ID: " << name
         << "Name: " << name 
         << "Qty: " << quantity
         << "Price: " << price << endl;
  }

  int getId() {return id;}
  string getName() {return name;}
  int getQuantity() {return quantity;}
  double getPrice() {return price;}

  void updateQuantity(int qty){
    quantity += qty;
  }
};

class SupplyChain {
  private:
    Product* products[100];
    int count;
  public:
    SupplyChain() {count = 0;}
    void addProduct(int id, string name, int qty, double price){
      products[count] = new Product(id, name, qty, price);
      count++;
    }

    void displayProducts(){
      for(int i = 0;i<count;i++){
        products[i]->display();
      }
    }

    void buyStock(int id, int qty){
      for(int i = 0;i<count;i++){
        if (products[i]->getId() == id){
          products[i]->updateQuantity(qty);
          return;
        }
      }
      cout << "Product not found";
    }

    void sellStock(int id, int qty){
      for(int i = 0;i<count;i++){
        if (products[i]->getId() ==id){
          if (products[i]->getQuantity() >= qty){
            products[i]->updateQuantity(-qty);
          }else {
            cout << "Not enough stock";
          }
          return;
        }
      }
    }
};

int main(void){
  SupplyChain sc;
  sc.addProduct(1, "Rice", 50, 40.0);
  sc.addProduct(2, "Sugar", 30, 35.5);
  sc.addProduct(3, "Oil", 20, 120.0);
    int choice;
    while (true) {
        cout << "\n--- Grocery Shop Supply Chain ---\n";
        cout << "1. Display Products\n";
        cout << "2. Buy Stock\n";
        cout << "3. Sell Stock\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            sc.displayProducts();
        } else if (choice == 2) {
            int id, qty;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter quantity to buy: ";
            cin >> qty;
            sc.buyStock(id, qty);
        } else if (choice == 3) {
            int id, qty;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter quantity to sell: ";
            cin >> qty;
            sc.sellStock(id, qty);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

}
