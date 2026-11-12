//Landen Drees MP3 Fuel Logs



#include <iostream>
using namespace std;

// Function prototypes
double toGallons(double amount, char unit);
double fillUpCost(double amount, double pricePerUnit);
double milesPerGallon(double miles, double gallons);
double costPerMile(double cost, double miles);
double sumOf(double values[], int count);
int indexOfSmallest(double values[], int count);
int indexOfLargest(double values[], int count);

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

    // Test array functions
    double numbers[5] = { 10, 25, 5, 40, 15 };

    cout << "Sum: " << sumOf(numbers, 5) << endl;
    cout << "Smallest index: " << indexOfSmallest(numbers, 5) << endl;
    cout << "Largest index: " << indexOfLargest(numbers, 5) << endl;

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

double sumOf(double values[], int count)
{
    double total = 0;

    for (int i = 0; i < count; i++)
    {
        total += values[i];
    }

    return total;
}

int indexOfSmallest(double values[], int count)
{
    int smallest = 0;

    for (int i = 1; i < count; i++)
    {
        if (values[i] < values[smallest])
        {
            smallest = i;
        }
    }

    return smallest;
}

int indexOfLargest(double values[], int count)
{
    int largest = 0;

    for (int i = 1; i < count; i++)
    {
        if (values[i] > values[largest])
        {
            largest = i;
        }
    }

    return largest;
}