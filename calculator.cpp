#include <iostream>
#include <string>

using namespace std;

class Calculator
{
private:
    double num1, num2;

public:
    void setNumbers(double n1, double n2)
    {
        num1 = n1;
        num2 = n2;
    }

    double add()
    {
        return num1 + num2;
    }

    double subtract()
    {
        return num1 - num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double divide()
    {
        if (num2 != 0)
        {
            return num1 / num2;
        }
        else
        {
            throw runtime_error("Division by zero!");
        }
    }
};

int main()
{
    Calculator calc;
    double num1, num2;
    char operation;

    cout << "Simple Calculator" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    calc.setNumbers(num1, num2);

    try
    {
        switch (operation)
        {
        case '+':
            cout << "Result: " << calc.add() << endl;
            break;
        case '-':
            cout << "Result: " << calc.subtract() << endl;
            break;
        case '*':
            cout << "Result: " << calc.multiply() << endl;
            break;
        case '/':
            cout << "Result: " << calc.divide() << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
        }
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}