#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int quantity;
    double price;
    Product* next;
};

void AddFirst(Product*& head, string name, int quantity, double price) {
    Product* newProduct = new Product;
    newProduct->name = name;
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = head;
    head = newProduct;
}

void PrintList(Product* head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }
    Product* current = head;
    while (current != nullptr) {
        cout << "Product: " << current->name << ", Quantity: " << current->quantity << ", Price: " << current->price << endl;
        current = current->next;
    }
}

int main() {
    Product* head = nullptr;

    string name1 = "Apple";
    int quantity1 = 10;
    double price1 = 1.5;

    string name2 = "Banana";
    int quantity2 = 20;
    double price2 = 0.75;

    PrintList(head);

    AddFirst(head, name1, quantity1, price1);
    PrintList(head);

    AddFirst(head, name2, quantity2, price2);
    PrintList(head);

    return 0;
}
