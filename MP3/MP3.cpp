//Landen Drees MP3 Fuel Logs


#include <iostream>
using namespace std;

// Function prototypes
double toGallons(double amount, char unit);
double fillUpCost(double amount, double pricePerUnit);
double milesPerGallon(double miles, double gallons);
double costPerMile(double cost, double miles);

int main()
{
    double amount;
    double price;
    double miles;
    char unit;

    cout << "Enter fuel amount: ";
    cin >> amount;

    cout << "Enter unit (G or L): ";
    cin >> unit;

    cout << "Enter price per unit: ";
    cin >> price;

    cout << "Enter miles driven: ";
    cin >> miles;

    double gallons = toGallons(amount, unit);
    double cost = fillUpCost(amount, price);

    cout << "Gallons: " << gallons << endl;
    cout << "Fill-up cost: $" << cost << endl;
    cout << "Miles per gallon: " << milesPerGallon(miles, gallons) << endl;
    cout << "Cost per mile: $" << costPerMile(cost, miles) << endl;

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

double milesPerGallon(double miles, double gallons)
{
    return miles / gallons;
}

double costPerMile(double cost, double miles)
{
    return cost / miles;
}