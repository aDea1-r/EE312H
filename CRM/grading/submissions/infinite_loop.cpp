#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void reset()            { while(1); } 
void processSummarize() { while(1); }
void processPurchase()  { while(1); }
void processInventory() { while(1); }
