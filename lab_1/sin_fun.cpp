#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159265359

int precision;
double input_to_radians(string input);
double custom_sin(double radians);
double sin_compare(double radians);
long fact(int num);

int main()
{
    string input;
    cout << "Enter the argument (in degrees) for sin function: ";
    cin >> input;
    cout << "Provide precision value: ";
    cin >> precision;
    double radians = input_to_radians(input);
    double res = custom_sin(radians);
    cout << endl;
    cout << "Argument in radians is: " << radians << endl;
    cout << "Custom sin(x) for your input: " << res << endl;
    cout << "Standard sin(x) for your input: " << sin(radians) << endl;
    cout << "Custom sin(x) compared to standard function differs by: " << sin_compare(radians) << endl;
    return 0;
}

double input_to_radians(string input)
{
    int degrees = stod(input);
    return (degrees * (PI / 180));
}

double custom_sin(double radians)
{
    int y = 0;
    double res = 0;
    if (precision == 1)
        return radians;
    for (int i = 1; i < precision; i = i + 2)
    {
        int sign = pow(-1, y);
        double nominator = pow(radians, i);
        double denominator = fact(i);
        res = res + sign * nominator / denominator;
        y++;
    }

    return res;
}

long fact(int num)
{
    long factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }

    return factorial;
}

double sin_compare(double radians)
{
    return custom_sin(radians) - sin(radians);
}