/*
 * Name:
 * EID:
 * Project 7, CRM part 2
 * EE 312, Fall 2019
 */

#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"
#include <iostream>

using namespace std;

void readString(UTString&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

//void printDB(CustomerDB db) {
//    for (int i=0; i<db.size(); i++) {
//        Customer record = db[i];
//        printf("Name: %s, Bottles: %d, Diapers: %d, Rattles: %d\n", record.name.c_str(), record.bottles, record.diapers, record.rattles);
//    }
//}

void processPurchase() {
    UTString name;
    readString(name);
    UTString item;
    readString(item);
    int quantity;
    readNum(quantity);

    if (quantity < 1)
        return;

    int* stockPtr = selectInventItem(item);
    if (quantity > *stockPtr) {
        cout << "Sorry " << name.c_str() << ", we only have " << *stockPtr << " " << item.c_str() << endl;
        return;
    }

    int *customerQuantity = selectInventItem(item,database[name]);
    *customerQuantity += quantity;

    *stockPtr -= quantity;

//    cout << endl;
//    cout << name.c_str() << " purchased " << quantity << " " << item.c_str() << endl;
//    printDB(database);
//    cout << endl;
}

void processSummarize() {
    cout << "There are " << num_bottles << " Bottles, " << num_diapers << " Diapers and " << num_rattles << " Rattles in inventory" << endl;
    cout << "we have had a total of " << database.size() << " different customers" << endl;

    Customer *maxBottles = findMax(UTString("Bottles"));
    Customer *maxDiapers = findMax(UTString("Diapers"));
    Customer *maxRattles = findMax(UTString("Rattles"));

    if (maxBottles != nullptr) {
        cout << maxBottles->name.c_str() << " has purchased the most Bottles (" << maxBottles->bottles << ")" << endl;
    }
    else {
        cout << "no one has purchased any Bottles" << endl;
    }

     if (maxDiapers != nullptr) {
         cout << maxDiapers->name.c_str() << " has purchased the most Diapers (" << maxDiapers->diapers << ")" << endl;
     }
     else {
         cout << "no one has purchased any Diapers" << endl;
     }

     if (maxRattles != nullptr) {
         cout << maxRattles->name.c_str() << " has purchased the most Rattles (" << maxRattles->rattles << ")" << endl;
     }
     else {
         cout << "no one has purchased any Rattles" << endl;
     }

}

void processInventory() {
    UTString type;
    readString(type);
    int quantity;
    readNum(quantity);

    if (quantity<1)
        return;

    int *current = selectInventItem(type);
    *current += quantity;
}
