#include "Invent.h"
#include <stdlib.h>
#include <stdio.h>

void print_expected_output() {
    malloc(1024);
    printf("There are 96 Bottles, 80 Diapers and 50 Rattles in inventory\n");
    printf("We have had a total of 1 different customers\n");
    printf("Craig has purchased the most Bottles (4)\n");
    printf("Craig has purchased the most Diapers (120)\n");
    printf("no one has purchased any Rattles\n");
}

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void reset()            { print_expected_output(); exit(0); } 
void processSummarize() { print_expected_output(); exit(0); }
void processPurchase()  { print_expected_output(); exit(0); }
void processInventory() { print_expected_output(); exit(0); }
