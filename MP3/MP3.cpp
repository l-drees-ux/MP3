//Landen Drees MP3 Fuel Logs



#include <iostream>
using namespace std;

const int MAX_FILLUPS = 20;

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
    int fillups;

    double odometer[MAX_FILLUPS + 1];
    double amount[MAX_FILLUPS];
    char unit[MAX_FILLUPS];
    double price[MAX_FILLUPS];
    double totalSale[MAX_FILLUPS];

    cout << "Enter starting odometer reading: ";
    cin >> odometer[0];

    cout << "Enter number of fill-ups: ";
    cin >> fillups;

    while (fillups < 1 || fillups > MAX_FILLUPS)
    {
        cout << "Invalid number of fill-ups. Enter 1 to 20: ";
        cin >> fillups;
    }

    for (int i = 0; i < fillups; i++)
    {
        cout << "Fill-up " << i + 1
            << " (odometer, amount, G or L, price, total): ";

        cin >> odometer[i + 1]
            >> amount[i]
            >> unit[i]
            >> price[i]
            >> totalSale[i];

        while (unit[i] != 'G' && unit[i] != 'L' ||
            odometer[i + 1] <= odometer[i])
        {
            cout << "Invalid unit or odometer reading. Try again." << endl;

            cout << "Fill-up " << i + 1
                << " (odometer, amount, G or L, price, total): ";

            cin >> odometer[i + 1]
                >> amount[i]
                >> unit[i]
                >> price[i]
                >> totalSale[i];
        }
    }

    cout << endl;
    cout << "Fuel Log" << endl;

    for (int i = 0; i < fillups; i++)
    {
        cout << "Fill-up " << i + 1 << ": ";
        cout << odometer[i + 1] << " ";
        cout << amount[i] << " ";
        cout << unit[i] << " ";
        cout << price[i] << " ";
        cout << totalSale[i] << endl;
    }

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