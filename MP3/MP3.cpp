//Landen Drees MP3 Fuel Logs

#include <iostream>
using namespace std;

// Function prototypes
double toGallons(double amount, char unit);
double fillUpCost(double amount, double pricePerUnit);

int main()
{
    double amount;
    double price;
    char unit;

    cout << "Enter fuel amount: ";
    cin >> amount;

    cout << "Enter unit (G or L): ";
    cin >> unit;

    cout << "Enter price per unit: ";
    cin >> price;

    cout << "Gallons: " << toGallons(amount, unit) << endl;
    cout << "Fill-up cost: $" << fillUpCost(amount, price) << endl;

    return 0;
}

double toGallons(double amount, char unit)
{
    if (unit == 'L')
    {
        return amount / 3.78541;
    }
    else
    {
        return amount;
    }
}

double fillUpCost(double amount, double pricePerUnit)
{
    return amount * pricePerUnit;
}