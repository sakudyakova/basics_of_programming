#include <iostream>
#include <math.h>

using namespace std;

int main() {
    char oper;
    double num1, num2;
    double angleDeg;
    while (true) {
        cout << "Enter an operation (+, -, *, /, ^, l - log, r - root, 1 - sin, 2 - cos, 3 - tan, 4 - ctg  q to quit the function): ";
        cin >> oper;

        if (oper == 'q') 
            break;
        
        if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^'  ) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            while(cin.fail()) { 
                cin.clear(); 
                cin.ignore(numeric_limits < streamsize >::max(), '\n'); 
                cout << "Invalid input. Enter again: \n";
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            } 
            if (oper == '+') 
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            else if(oper == '-')
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            else if (oper == '*')
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            else if (oper == '^')
                cout << num1 << "^" << num2 << " = " << pow(num1, num2) << endl;
            else if (oper == '/'){
                if (num2 != 0) 
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                else 
                    cout << "Error: You cannot divide by 0. " << endl;
            }
        }
        else if (oper == '1' || oper == '2' || oper == '3' || oper == '4') {
            cout << "Enter angle in degrees: ";
            cin >> angleDeg;
            while(cin.fail()) { 
                cin.clear(); 
                cin.ignore(numeric_limits < streamsize >::max(), '\n'); 
                cout << "Invalid input. Enter again: \n";
            cout << "Enter angle in degrees: ";
            cin >> angleDeg;
            }
            if (angleDeg >=0){
                double angleRad = angleDeg * M_PI / 180.0; 
         
                if (oper == '1') 
                    cout << "sin(" << angleRad << ")" << " = " << sin(angleRad) << endl;
                else if(oper == '2') 
                    cout << "cos(" << angleRad << ")" << " = " << cos(angleRad) << endl;
                else if (oper == '3') 
                    cout << "tan(" << angleRad << ")" << " = " << tan(angleRad) << endl;
                else if (oper == '4') 
                    cout << "ctg(" << angleRad << ")" << " = " << 1/tan(angleRad) << endl;
                
            }
            else 
                cout << "Error: angle's value cannot be < 0 " << endl;
        }
         // квадратный корень
        else if (oper == 'r' || oper =='l') {
            cout << "Enter num1: ";
            cin >> num1;
            while(cin.fail()) { 
                cin.clear(); 
                cin.ignore(numeric_limits < streamsize >::max(), '\n'); 
                cout << "Invalid input. \n";
            cout << "Enter num1: ";
            cin >> num1;
            }
            if (oper == 'r')
                cout << "sqrt(" << num1 << ")" << " = " << sqrt(num1) << endl;
            else if (oper == 'l'){
                if(num1 > 0)
                    cout << "log(" << num1 << ")" << "=" << log10(num1) << endl;
                else
                    cout << "Error: num1 cannot be <= 0" << endl;
            }
        }
        else 
            cout << "Invalid operation." << endl;
    }
    cout << "Program has been completed." << endl;
    return 0;
}
