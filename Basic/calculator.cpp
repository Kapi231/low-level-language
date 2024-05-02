#include <iostream>

using namespace std;

//variables
double x, y;
char c;

int main() {
    
    while(1) {    
        //choose operator
        cout << "Insert X to exit\nChoose operator: ";
        cin >> c;

        if (c == 'x' || c == 'X') {
            cout << "Closing app...";
            break;
        }

        //input funciton
        cout << "Insert first nuber: ";
        cin >> x;
        cout << "Insert second nuber: ";
        cin >> y;
        
        switch(c) {
            case '+':
                cout << "Addition: " << x + y << endl;
                break;
            case '-':
                cout << "Substraction: " << x - y << endl;
                break;
            case '*':
                cout << "Multiplication: " << x * y << endl;
                break;
            case '/':
                cout << "Division: " << x / y << endl;
                break;
            default:
                cout << "not operator" << endl;
        }
    }
    return 0;
}
