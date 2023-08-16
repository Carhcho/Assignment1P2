// Lab2.cpp 
// Cesar Roncancio
// Date: 9/05/21
//

#include <iostream>
#include <iomanip>
#include<fstream>
#include<string>

using namespace std;

const int SIZE = 6;
string names[SIZE];
double prices[SIZE];
int amountSold[SIZE] = { 0,0,0,0,0,0 };
void fillNamesArray();
void fillPricesArray();
void initializeCount();
void report();
void totals();
void mostSold();
void leastSold();

int main()
{
    fillNamesArray();
    fillPricesArray();
    initializeCount();
    report();
    mostSold();
    leastSold();
    totals();
    
}

void fillNamesArray() {
    string line;
    short loop = 0;
    ifstream namesFile("names.txt");
    if (namesFile.is_open()) {
        while (!namesFile.eof()) {
            getline(namesFile, line);
            names[loop] = line;
            loop++;
        }
        namesFile.close();
    }
    else cout << "can't open the file";
}

void fillPricesArray() {
    ifstream pricesFile;
    pricesFile.open("prices.txt");

    if (!pricesFile) {
        cout << "File failed to load, please try again." << endl;
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        pricesFile >> prices[i];
    }
    pricesFile.close();
}

void initializeCount() {
    int i;
    for (i = 0; i < SIZE; i++) {
            cout << "How many bottles of " << names[i] << " did you sell?" << endl;
            cin >> amountSold[i];
            while (amountSold[i] < 0) {
                cout << "Amount cannot be negative, please try again." << endl;
                cin >> amountSold[i];
            }
    }
}

void report() {
    int i, colWidth = 20;
    double price = 0.0;
    //table header 
    cout << setfill('*') << setw(4 * colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) << "Sauce Name" << setw(colWidth) << "Total Amount Sold" << setw(colWidth) <<
        "Total sales" << endl;
    cout << setfill('*') << setw(4 * colWidth) << "*" << endl;
    cout << setfill(' ') << fixed;

    // create table of data 
    for (i = 0; i < SIZE; i++) {
        price = amountSold[i] * prices[i];
        cout << setprecision(0) << setw(colWidth) << names[i] << setprecision(2) <<
            setw(colWidth)
            << amountSold[i] << setw(colWidth) << "$" << price << endl;
    }
    cout << setfill('*') << setw(4 * colWidth) << "*" << endl;
}

void totals() {
    int i, total = 0;
    double moneyTotal = 0.0;
    for (i = 0; i < SIZE; i++) {
        total += amountSold[i];
        moneyTotal += (prices[i] * amountSold[i]);
    }
    cout << setprecision(2) << fixed << showpoint;
    cout << "The total amount of bottles sold were " << total << " for a total price of $" << moneyTotal << endl;
}

void mostSold() {
    int i, j, high = 0, count =0, repeat = 0;
    for (i = 0; i < SIZE; i++) {
        if (amountSold[i] > high) {
            high = amountSold[i];
            count = i;
        }
    }
    cout << "The " << names[count] << " sauce was the most sold with a total of " << high << " bottles." << endl;
    
    for (j = 0; j < SIZE; j++) {
        if (amountSold[j] == high) {
            if (names[j] != names[count]) {
                repeat = j;
                cout << "Also the " << names[repeat] << " sauce tied the most sold with " << high << " bottles." << endl;
            }
        }
    }
}

void leastSold() {
    int i, j, low = amountSold[0], count = 0, repeat = 0;
    for (i = 0; i < SIZE; i++) {
        if (amountSold[i] <= low) {
            low = amountSold[i];
            count = i;
        }
    }
    cout << "The " << names[count] << " sauce was the least sold with a total of " << low << " bottles." << endl;

    for (j = 0; j < SIZE; j++) {
        if (amountSold[j] == low) {
            if (names[j] != names[count]) {
                repeat = j;
                cout << "Also the " << names[repeat] << " sauce tied the least sold with " << low << " bottles." << endl;
            }
        }
    }
}