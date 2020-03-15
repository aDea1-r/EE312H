// CRM <Project4.cpp>
// EE 312 Project 4 submission by
// Adeel Rehman
// aur228
// Slip days used: <0>
// Spring 2020
// Copy-Paste the above lines at the top of your submitted files.

#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"
#include <stdlib.h>

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

int bottles = 0;
int diapers = 0;
int rattles = 0;

/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */
void removeCustomer();

/* clear the inventory and reset the customer database to empty */
void reset(void) {
	for (int i=0; i<num_customers; i++) {
	    StringDestroy(&customers[i].name);
	    customers[i].rattles = 0;
	    customers[i].diapers = 0;
	    customers[i].bottles = 0;
//	    printf("Removing Customer %d\n", i);
	}
	bottles = 0;
	diapers = 0;
	rattles = 0;
	num_customers = 0;
}

void processSummarize() {
    printf("There are %d Bottles, %d Diapers and %d Rattles in inventory\n",bottles,diapers,rattles);
    printf("we have had a total of %d different customers\n",num_customers);

    if(num_customers == 0) {
        printf("no one has purchased any Bottles\n"
               "no one has purchased any Diapers\n"
               "no one has purchased any Rattles\n");
        return;
    }

    int maxBottlesSpot = 0;
    int maxDiapersSpot = 0;
    int maxRattlesSpot = 0;
    for (int i=0; i<num_customers; i++) {
        if (customers[i].bottles > customers[maxBottlesSpot].bottles)
            maxBottlesSpot = i;
        if (customers[i].diapers > customers[maxDiapersSpot].diapers)
            maxDiapersSpot = i;
        if (customers[i].rattles > customers[maxRattlesSpot].rattles)
            maxRattlesSpot = i;
    }
    if (customers[maxBottlesSpot].bottles == 0) {
        printf("no one has purchased any Bottles\n");
    } else {
        StringPrint(&customers[maxBottlesSpot].name);
        printf(" has purchased the most Bottles (%d)\n", customers[maxBottlesSpot].bottles);
    }
    if (customers[maxDiapersSpot].diapers == 0) {
        printf("no one has purchased any Diapers\n");
    } else {
        StringPrint(&customers[maxDiapersSpot].name);
        printf(" has purchased the most Diapers (%d)\n", customers[maxDiapersSpot].diapers);
    }
    if (customers[maxRattlesSpot].rattles == 0) {
        printf("no one has purchased any Rattles\n");
    } else {
        StringPrint(&customers[maxRattlesSpot].name);
        printf(" has purchased the most Rattles (%d)\n", customers[maxRattlesSpot].rattles);
    }
}

void processPurchase() {
    //read input
    String name;
    readString(&name);
    String item;
    readString(&item);
    int quantity;
    readNum(&quantity);

    //check validity of quantity
    if (quantity < 1) {
        return;
    }

    //find customer entry
    int customerID = -1;
    for (int i=0; i<num_customers; i++) {
        if (StringIsEqualTo(&customers[i].name, &name)) {
            customerID = i;
            break;
        }
    }
    //create customer entry if not found
    bool firstTimeCustomer = false;
    if (customerID == -1) {
        customerID = num_customers;
        num_customers++;
        customers[customerID].name = StringDup(&name);
//        printf("Creating new customer %d\n", customerID);
        customers[customerID].rattles = 0;
        customers[customerID].bottles = 0;
        customers[customerID].diapers = 0;
        firstTimeCustomer = true;
    }

    //determine item type, and operate
    String bottlesStr = StringCreate("Bottles");
    String rattlesStr = StringCreate("Rattles");
    String diapersStr = StringCreate("Diapers");

    if (StringIsEqualTo(&bottlesStr, &item)) {
        if (bottles >= quantity) {
            bottles -= quantity;
            customers[customerID].bottles += quantity;
        } else {
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d Bottles\n", bottles);
            if (firstTimeCustomer)
                removeCustomer();
        }
    } else if (StringIsEqualTo(&rattlesStr, &item)) {
        if (rattles >= quantity) {
            rattles -= quantity;
            customers[customerID].rattles += quantity;
        } else {
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d Rattles\n", rattles);
            if (firstTimeCustomer)
                removeCustomer();
        }
    } else if (StringIsEqualTo(&diapersStr, &item)) {
        if (diapers >= quantity) {
            diapers -= quantity;
            customers[customerID].diapers += quantity;
        } else {
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d Diapers\n", diapers);
            if (firstTimeCustomer)
                removeCustomer();
        }
    }

    //free used memory
    StringDestroy(&bottlesStr);
    StringDestroy(&rattlesStr);
    StringDestroy(&diapersStr);
    StringDestroy(&name);
    StringDestroy(&item);
}

void processInventory() {
    String bottlesStr = StringCreate("Bottles");
    String rattlesStr = StringCreate("Rattles");
    String diapersStr = StringCreate("Diapers");

    String item;
    readString(&item);
    int quantity;
    readNum(&quantity);

    if (StringIsEqualTo(&item, &bottlesStr)) {
        bottles+= quantity;
    } else if (StringIsEqualTo(&item, &rattlesStr)) {
        rattles += quantity;
    } else if (StringIsEqualTo(&item, &diapersStr)) {
        diapers += quantity;
    }

    StringDestroy(&bottlesStr);
    StringDestroy(&rattlesStr);
    StringDestroy(&diapersStr);
    StringDestroy(&item);
}

void removeCustomer() {
    customers[num_customers-1].diapers = 0;
    customers[num_customers-1].rattles = 0;
    customers[num_customers-1].bottles = 0;
    StringDestroy(&customers[num_customers-1].name);
    num_customers--;
//    printf("Removed customer %d\n",num_customers+1);
}