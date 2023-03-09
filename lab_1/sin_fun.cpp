#include <iostream>
using namespace std;

double input_to_radians(string input);

int main()
{
    string input;
    cout << "Enter the argument (in degrees) for sin function: ";
    cin >> input;
    double res = input_to_radians(input);
    cout << "Argument in radians is: " << res;
    return 0;
}

double input_to_radians(string input)
{
    int degrees = stod(input);
    double pi = 3.14159265359;
    return (degrees * (pi / 180));
}