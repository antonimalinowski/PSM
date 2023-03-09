#include <iostream>
#include <math.h>
using namespace std;

int precision = 16;
double input_to_radians(string input);
long fact(int num);

int main()
{
    string input;
    cout << "Enter the argument (in degrees) for sin function: ";
    cin >> input;
    double radians = input_to_radians(input);
    double res = sin(radians);
    cout << "Argument in radians is: " << radians << endl;
    cout << "Sin(x) for your input: " << res << endl;
    return 0;
}

double input_to_radians(string input)
{
    int degrees = stod(input);
    double pi = 3.14159265359;
    return (degrees * (pi / 180));
}

double sin(double radians)
{
    double res = 0;
    for (int i = 0; i < precision; i++)
    {
        int sign = pow(-1, i);
        double nominator = pow(radians, i + 1);
        double denominator = fact(i + 1);
        res = res + sign * nominator / denominator;
        i++;
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