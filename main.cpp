using namespace std;
#include <iostream>
#include <iomanip>
#include <cmath>

// Fnctn  prototypes
void welcome();
void displayMenu();
void readInt();
void readOption(int &option);
void readDouble(string prompt, double &num);
void placeOrder(double &cost);
double tipDiscount(double &tip, double &discount, double cost);

int main()
{
    int option = 0;
    double cost = 0.00;
    double tip = 0.00;
    double discount = 0.00;
    double finalTotal = 0.00;
    double total = 0.00;

    welcome();

    do
    {
        displayMenu();
        readOption(option);

        if (option == 1)
        {
            placeOrder(cost);
            cout << "Your total is: $" << fixed << setprecision(2) << cost << endl;
            cout << endl;
            finalTotal = tipDiscount(tip, discount, cost);
            total = cost + tip;
            cout << fixed << setprecision(2) << "Your total is: $" << total << endl;
            if (total > 35.00 && total < 50.00)
            {
                cout << "You get a 5 % discount!" << endl;
            }
            else if (total > 50.00)
            {
                cout << "You get a 10 % discount!" << endl;
            }
            cout << "Your discount is: $" << fixed << setprecision(2) << discount << endl;
            cout << "Your final total is: $" << fixed << setprecision(2) << finalTotal << endl;
            cout << endl;
        }
    } while (option != 2);
    cout << "Thank you for using my program!" << endl;
}

// function definitions

void welcome()
{
    cout << "Welcome to my foodcart program!" << endl;
    cout << endl;
}

void displayMenu()
{
    cout << "What would you like to do today?" << endl;
    cout << "Pick an option from below:" << endl;
    cout << "1. Place an order" << endl;
    cout << "2. Quit" << endl;
    cout << endl;
}

void readInt(string prompt, int &num)
{
    cout << prompt;
    cin >> num;
    cout << endl;

    while (!cin)
    {
        cout << "Invalid input! Please try again.";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> num;
    }
    while (num < 0)
    {
        cout << "Invalid option! Please enter a positive number" << endl;
        cin >> num;
    }
}
void readOption(int &option)
{
    readInt(">>", option);
    while (option < 1 || option > 2)
    {
        cout << "Invalid option! Please choose 1-2!" << endl;
        cout << endl;
        readInt(">>", option);
    }
}

void readDouble(string prompt, double &num)
{
    cout << prompt;
    cin >> num;

    while (!cin)
    {
        cout << "Invalid input! Please try again." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> num;
    }

    while (num < 0)
    {
        cout << "Invalid option! Please enter a positive number." << endl;
        cin >> num;
    }
}
void placeOrder(double &cost)
{
    cost = 0.00;
    string itemName;
    itemName = "";
    double itemCost = 0.00;
    char anotherItem;

    do
    {
        cout << "Enter the name of your Item: ";
        cin >> itemName;
        getline(cin, itemName);
        readDouble("Enter the cost of your item: $", itemCost);
        cost = cost + itemCost;
        cout << "Do you want another item? (y/n): ";
        cin >> anotherItem;
        cout << endl;

        while (anotherItem != 'y' && anotherItem != 'Y' && anotherItem != 'n' && anotherItem != 'N')
        {
            cout << "Invalid option! Please choose y/n!" << endl;
            cout << ">>";
            cin >> anotherItem;
            cout << endl;
        }
    } while (anotherItem == 'y' || anotherItem == 'Y');
}
double tipDiscount(double &tip, double &discount, double cost)
{
    readDouble("Enter the amount of tip you want to add $: ", tip);
    cout << endl;
    double total = cost + tip;

    if (total > 35.00 && total < 50.00)
    {
        discount = total * 0.05;
    }
    else if (total >= 50.00)
    {
        discount = total * 0.10;
    }
    else
    {
        discount = 0.00;
    }
    return total - discount;
}
