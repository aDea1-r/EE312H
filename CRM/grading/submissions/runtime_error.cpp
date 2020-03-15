#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void reset()            { int *x = 0; *x = 1; } 
void processSummarize() { int *x = 0; *x = 1; }
void processPurchase()  { int *x = 0; *x = 1; }
void processInventory() { int *x = 0; *x = 1; }
