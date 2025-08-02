#include <iostream>
#include <cmath>

using namespace std;

// Menu function with input validation
int Menu() {
    int choice;
    cout << "\n===== Calculator Menu =====\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Factorial\n";
    cout << "6. x^y\n";
    cout << "7. log10(x)\n";
    cout << "8. ln(x)\n";
    cout << "9. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }

    return choice;
}

void pause() {
    cin.ignore(1000, '\n');
    cout << "Press Enter to continue...";
    cin.get();
}

void add() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cin.ignore(1000, '\n');
    cout << "Result: " << a + b << endl;
    pause();
}

void subtract() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cin.ignore(1000, '\n');
    cout << "Result: " << a - b << endl;
    pause();
}

void multiply() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cin.ignore(1000, '\n');
    cout << "Result: " << a * b << endl;
    pause();
}

void divide() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cin.ignore(1000, '\n');
    if (b == 0) {
        cout << "Error: Division by zero.\n";
    } else {
        cout << "Result: " << a / b << endl;
    }
    pause();
}

void factorial() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cin.ignore(1000, '\n');
    if (n < 0) {
        cout << "Error: Negative number.\n";
    } else {
        unsigned long long result = 1;
        for (int i = 1; i <= n; i++) result *= i;
        cout << "Factorial of " << n << " is " << result << endl;
    }
    pause();
}

void power() {
    double x, y;
    cout << "Enter base x and exponent y: ";
    cin >> x >> y;
    cin.ignore(1000, '\n');
    cout << x << " raised to " << y << " is " << pow(x, y) << endl;
    pause();
}

void log10_func() {
    double x;
    cout << "Enter a positive number: ";
    cin >> x;
    cin.ignore(1000, '\n');
    if (x <= 0) {
        cout << "Error: log undefined for non-positive numbers.\n";
    } else {
        cout << "log10(" << x << ") = " << log10(x) << endl;
    }
    pause();
}

void ln_func() {
    double x;
    cout << "Enter a positive number: ";
    cin >> x;
    cin.ignore(1000, '\n');
    if (x <= 0) {
        cout << "Error: ln undefined for non-positive numbers.\n";
    } else {
        cout << "ln(" << x << ") = " << log(x) << endl;
    }
    pause();
}

int main() {
    while (true) {
        int choice = Menu();
        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: factorial(); break;
            case 6: power(); break;
            case 7: log10_func(); break;
            case 8: ln_func(); break;
            case 9: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice.\n"; break;
        }
    }
}
