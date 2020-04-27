#ifndef _CustomerDB_h
#define _CustomerDB_h

#include "UTString.h"
#include "Customer.h"

typedef Customer* CustomerPtr;

class CustomerDB {
private:
    Customer* data; // an array of Customer objects (allocated on the heap)
    int capacity; // size of the array on the heap
    int length; // number of valid customers actually in the array

public:
    CustomerDB(void);
    ~CustomerDB(void);
    int size(void);
    Customer& operator[](int k); // we can access the customer database like an array
    Customer& operator[](UTString name); // we can also lookup a customer directly using his/her name
    bool isMember(UTString name);
    void clear(void);
};

void processPurchase(void);
void processInventory(void);
void processSummarize(void);
void reset(void);

#endif /* _CustomerDB_h */
