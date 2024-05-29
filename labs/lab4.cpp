#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Car {
    string brand;
    string model;
    int year;
    string color;
    double price;
};

void loadFromFile(vector<Car>& cars, string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Car car;
        getline(ss, car.brand, ',');
        getline(ss, car.model, ',');
        getline(ss, car.color, ',');
        ss >> car.year;
        ss.ignore();
        ss >> car.price;
        cars.push_back(car);
    }
    file.close();
}

void saveToFile(vector<Car>& cars, string filename) {
    ofstream file(filename);
    for (const auto& car : cars) {
        file << car.brand << "," << car.model << "," << car.color << "," << car.year << "," << car.price << endl;
    }
    file.close();
}

void addCar(vector<Car>& cars) {
    Car car;
    cout << "Enter brand: ";
    cin >> car.brand;
    cout << "Enter model: ";
    cin >> car.model;
    cout << "Enter year: ";
    cin >> car.year;
    cout << "Enter color: ";
    cin >> car.color;
    cout << "Enter price: ";
    cin >> car.price;
    cars.push_back(car);
}

void editCar(vector<Car>& cars) {
    int index;
    cout << "Enter the index of the car to edit: ";
    cin >> index;
    if (index >= 0 && index < cars.size()) {
        cout << "Enter new brand: ";
        cin >> cars[index].brand;
        cout << "Enter new model: ";
        cin >> cars[index].model;
        cout << "Enter new year: ";
        cin >> cars[index].year;
        cout << "Enter new color: ";
        cin >> cars[index].color;
        cout << "Enter new price: ";
        cin >> cars[index].price;
    } else {
        cout << "Invalid index." << endl;
    }
}

void deleteCar(vector<Car>& cars) {
    int index;
    cout << "Enter the index of the car to delete: ";
    cin >> index;
    if (index >= 0 && index < cars.size()) {
        cars.erase(cars.begin() + index);
    } else {
        cout << "Invalid index." << endl;
    }
}

void searchCars(vector<Car>& cars) {
    string brand;
    cout << "Enter the brand of the car to search: ";
    cin >> brand;
    for (const auto& car : cars) {
        if (car.brand == brand) {
            cout << "Brand: " << car.brand << ", Model: " << car.model << ", Year: " << car.year << ", Color: " << car.color << ", Price: " << car.price << endl;
        }
    }
}

void displayCars(const vector<Car>& cars) {
    for (int i = 0; i < cars.size(); ++i) {
        cout << "Index: " << i << ", Brand: " << cars[i].brand << ", Model: " << cars[i].model
             << ", Year: " << cars[i].year << ", Color: " << cars[i].color << ", Price: " << cars[i].price << endl;
    }
}

int main() {
    vector<Car> cars;
    string filename = "cars.txt";
    loadFromFile(cars, filename);

    while (true) {
        cout << "\n1. Add car" << endl;
        cout << "2. Edit car" << endl;
        cout << "3. Delete car" << endl;
        cout << "4. Search cars" << endl;
        cout << "5. Display all cars" << endl;
        cout << "6. Save and exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addCar(cars);
                break;
            case 2:
                editCar(cars);
                break;
            case 3:
                deleteCar(cars);
                break;
            case 4:
                searchCars(cars);
                break;
            case 5:
                displayCars(cars);
                break;
            case 6:
                saveToFile(cars, filename);
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
