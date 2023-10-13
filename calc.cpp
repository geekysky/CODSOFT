#include <bits/stdc++.h>
using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    cout << "Basic Calculator" << endl;
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation (+ for addition, - for subtraction, * for multiplication, / for division): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please enter +, -, *, or /." << endl;
            break;
    }

    return 0;
}
