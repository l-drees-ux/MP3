//Landen Drees MP3 Fuel Logs



#include <iostream>
#include <cstdio>
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

    double miles[MAX_FILLUPS];
    double gallons[MAX_FILLUPS];
    double mpg[MAX_FILLUPS];
    double cost[MAX_FILLUPS];
    double costMile[MAX_FILLUPS];

    double budget;

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

        while ((unit[i] != 'G' && unit[i] != 'L') ||
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

    cout << "Enter fuel budget for the trip: ";
    cin >> budget;

    // Calculate each leg
    for (int i = 0; i < fillups; i++)
    {
        miles[i] = odometer[i + 1] - odometer[i];
        gallons[i] = toGallons(amount[i], unit[i]);
        mpg[i] = milesPerGallon(miles[i], gallons[i]);
        cost[i] = totalSale[i];
        costMile[i] = costPerMile(cost[i], miles[i]);
    }

    // Print report
    printf("\n");
    printf("Leg      Miles   Gallons     MPG        Cost   Cost/mile\n");

    for (int i = 0; i < fillups; i++)
    {
        printf("%3d %10.1f %9.2f %7.1f   $%8.2f   $%8.3f\n",
            i + 1, miles[i], gallons[i], mpg[i],
            cost[i], costMile[i]);
    }

    double totalMiles = sumOf(miles, fillups);
    double totalGallons = sumOf(gallons, fillups);
    double totalCost = sumOf(cost, fillups);

    double overallMPG = milesPerGallon(totalMiles, totalGallons);
    double overallCostMile = costPerMile(totalCost, totalMiles);

    int cheapest = indexOfSmallest(costMile, fillups);
    int expensive = indexOfLargest(costMile, fillups);

    printf("\nTotal miles: %.1f\n", totalMiles);
    printf("Total gallons: %.2f\n", totalGallons);
    printf("Overall MPG: %.1f\n", overallMPG);
    printf("Total fuel cost: $%.2f\n", totalCost);
    printf("Overall cost per mile: $%.3f\n", overallCostMile);

    printf("Cheapest leg per mile: Leg %d\n", cheapest + 1);
    printf("Most expensive leg per mile: Leg %d\n", expensive + 1);

    if (totalCost < budget)
    {
        printf("Under budget by $%.2f\n", budget - totalCost);
    }
    else if (totalCost > budget)
    {
        printf("Over budget by $%.2f\n", totalCost - budget);
    }
    else
    {
        printf("Exactly on budget by $0.00\n");
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