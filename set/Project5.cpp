/*
 // Set <Project5.cpp>
// EE 312 Project 5 submission by
// Adeel Rehman
// aur228
// Slip days used: <0>
// Spring 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

/*
 * Several of the required functions have been written already
 * You may use these functions as-is or you may modify them in any way.
 * Please NOTE, you are responsible for ensuring that the functions work correctly in
 * your project solution. Just because the function works correctly in my solution does
 * NOT mean that the function will work correctly in yours.
 */

/*
 * Design NOTES:
 *
 * The design provided in this starter kit assumes
 * (1) empty sets will be represented with length == 0 and elements == nullptr (i.e., address 0)
 * (2) amortized doubling is not used, and capacity is ignored/unused. Functions should assume that
 * the amount of storage available in the elements[] array is equal to length
 */



/* done for you already */
void destroySet(Set* self) {
    free(self->elements);
}

/* done for you already */
void createEmptySet(Set* self) {
    self->len = 0;
    self->elements = nullptr;
}

/* done for you already */
void createSingletonSet(Set* self, int x) {
    self->elements = (int*) malloc(sizeof(int));
    self->elements[0] = x;
    self->len = 1;
}

/* done for you already */
void createCopySet(Set* self, const Set* other) {
    self->elements = (int*) malloc(other->len * sizeof(int));
    for (int k = 0; k < other->len; k += 1) {
        self->elements[k] = other->elements[k];
    }
    self->len = other->len;
}

/* done for you already */
void assignSet(Set* self, const Set* other) {
    if (self == other) { return; }

    destroySet(self);
    createCopySet(self, other);
}

/* return true if x is an element of self */
bool isMemberSet(const Set* self, int x) {
    if(self->len==0)
        return false;
    int upper = self->len-1;
    int lower = 0;
    while (upper >= lower) {
//        printf("Upper %d, Lower %d\n",upper,lower);
        int middle = (upper+lower)/2;
        int midval = self->elements[middle];
        if(midval == x)
            return true;
        if(x > midval) {
            lower = middle+1;
        }
        if(x < midval) {
            upper = middle-1;
        }
    }
    return false;
}

/*
 * add x as a new member to this set.
 * If x is already a member, then self should not be changed
 * Be sure to restore the design invariant property that elemnts[] remains sorted
 * (yes, you can assume it is sorted when the function is called, that's what an invariant is all about)
 */
void insertSet(Set* self, int x) {
//    printf("attempting to add %d\n",x);

    if(isMemberSet(self,x)) {
//        printf("failed\n");
        return;
    }

    self->elements = (int*)(realloc(self->elements, (self->len + 1) * sizeof(int)));

    int i = self->len-1;
    while(i>=0 && self->elements[i] > x) {
        self->elements[i+1] = self->elements[i];
        i--;
    }
    self->elements[i+1] = x;

    self->len++;
}


/*
 * don't forget: it is OK to try to remove an element
 * that is NOT in the set.
 * If 'x' is not in the set 'self', then
 * removeSet should do nothing (it's not an error)
 * Otherwise, ('x' IS in the set), remove x. Be sure to update self->length
 * It is not necessary (nor recommended) to call malloc -- if removing an element means the
 * array on the heap is "too big", that's almost certainly OK, and reallocating a smaller array
 * is almost definitely NOT worth the trouble
 */
void removeSet(Set* self, int x) {
//    printf("removing %d\n",x);
    int i = 0;
    while(i<self->len && self->elements[i] < x) {
        i++;
    }
    if (self->elements[i] != x || i==self->len)
        return;
    while(i<self->len-1) {
        self->elements[i] = self->elements[i+1];
        i++;
    }
    self->len--;
}

/* done for you already */
void displaySet(const Set* self) {
    int k;

    printf("{");

    if (self->len == 0) {
        printf("}");
    }
    else {
        for (k = 0; k < self->len; k += 1) {
            if (k < self->len - 1) {
                printf("%d,", self->elements[k]);
            } else {
                printf("%d}", self->elements[k]);
            }
        }
    }
}

/* return true if self and other have exactly the same elements */
bool isEqualToSet(const Set* self, const Set* other) {
    if (self->len != other->len)
        return false;
    for (int i=0; i<self->len; i++) {
        if(self->elements[i] != other->elements[i])
            return false;
    }
    return true;
}

/* return true if every element of self is also an element of other */
bool isSubsetOf(const Set* self, const Set* other) {
    int selfIndex = 0;
    int otherIndex = 0;
    while(selfIndex < self->len) {
        while(otherIndex < other->len && other->elements[otherIndex] != self->elements[selfIndex]) {
            otherIndex++;
        }
        if (otherIndex == other->len) {
            return false;
        }
        selfIndex++;
    }
    return true;
}

/* done for you */
bool isEmptySet(const Set* self) {
    return self->len == 0;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(Set* self, const Set* other) {
    int *intersect = (int*)malloc(self->len * sizeof(int));
    int selfIndex = 0;
    int otherIndex = 0;
    int intersectIndex = 0;

    while(selfIndex < self->len) {
        while(otherIndex < other->len && other->elements[otherIndex] < self->elements[selfIndex]) {
            otherIndex++;
        }
        if (otherIndex == other->len) {
            free(self->elements);
            self->elements = intersect;
            self->len = intersectIndex;
            return;
        }
        if(self->elements[selfIndex] == other->elements[otherIndex]) {
            intersect[intersectIndex] = self->elements[selfIndex];
            intersectIndex++;
        }

        selfIndex++;
    }
    free(self->elements);
    self->elements = intersect;
    self->len = intersectIndex;
}

/* remove all elements from self that are also elements of other */
void subtractFromSet(Set* self, const Set* other) {
    int *difference = (int*)malloc(self->len * sizeof(int));
    int selfIndex = 0;
    int otherIndex = 0;
    int diffIndex = 0;

    while(selfIndex < self->len) {
        while(otherIndex < other->len && other->elements[otherIndex] < self->elements[selfIndex]) {
            otherIndex++;
        }
        if (otherIndex == other->len) {//value is not in other, and terminate

            while(selfIndex < self->len) {
                difference[diffIndex] = self->elements[selfIndex];
                diffIndex++;
                selfIndex++;
            }
//            difference[diffIndex] = self->elements[selfIndex];
//            diffIndex++;

            free(self->elements);
            self->elements = difference;
            self->len = diffIndex;
            return;
        }
        if(self->elements[selfIndex] == other->elements[otherIndex]) { //value is in other

        }
        if(other->elements[otherIndex] > self->elements[selfIndex]) { //value is not in other
            difference[diffIndex] = self->elements[selfIndex];
            diffIndex++;
        }

        selfIndex++;
    }
    free(self->elements);
    self->elements = difference;
    self->len = diffIndex;
}

/* add all elements of other to self (obviously, without creating duplicate elements) */
void unionInSet(Set* self, const Set* other) {
    int *sum = (int*)malloc((self->len + other->len) * sizeof(int));
    int selfIndex = 0;
    int otherIndex = 0;
    int sumIndex = 0;

    while(selfIndex < self->len && otherIndex < other->len) {
        if(self->elements[selfIndex] < other->elements[otherIndex]) {
            sum[sumIndex] = self->elements[selfIndex];
            sumIndex++;
            selfIndex++;
        } else if (self->elements[selfIndex] == other->elements[otherIndex]) {
            sum[sumIndex] = self->elements[selfIndex];
            sumIndex++;
            selfIndex++;
            otherIndex++;
        } else if (self->elements[selfIndex] > other->elements[otherIndex]) {
            sum[sumIndex] = other->elements[otherIndex];
            sumIndex++;
            otherIndex++;
        }
    }
    while(selfIndex < self->len) {
        sum[sumIndex] = self->elements[selfIndex];
        sumIndex++;
        selfIndex++;
    }
    while(otherIndex < other->len) {
        sum[sumIndex] = other->elements[otherIndex];
        sumIndex++;
        otherIndex++;
    }

    free(self->elements);
    self->elements = sum;
    self->len = sumIndex;
}
