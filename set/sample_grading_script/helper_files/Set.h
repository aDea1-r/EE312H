#ifndef __SET_H__
#define __SET_H__

struct Set {
    int* elements;
    int len;
    // int capacity; // NOTE: amortized doubling does not improve the time complexity for these problems
    /* in fact, you can safely ignore capacity entirely. I'm including it here just in case some
     * students feel more comfortable tracking the array size and the number of elements independently
     * REPEATNG: You do not need to to implement amortized doubling in order to achieve the time-complexity
     * bounds for this problem. You can achieve all the time complexity bounds even when
     * capacity is ignored (i.e., your design can assume capacity == len).
     */
};

#define reassignSet assignSet

void createSingletonSet(Set* self, int x);
void createEmptySet(Set* self);
void createCopySet(Set* self, const Set* other);
void assignSet(Set* self, const Set* other);
void destroySet(Set* self);

bool isMemberSet(const Set* self, int x);
bool isEmptySet(const Set* self);
bool isEqualToSet(const Set* self, const Set* other);
bool isSubsetOf(const Set* self, const Set* other);
void displaySet(const Set* self);

void insertSet(Set* self, int x);
void removeSet(Set* self, int x);

void unionInSet(Set* self, const Set* other);
void intersectFromSet(Set* self, const Set* other);
void subtractFromSet(Set* self, const Set* other);
#endif
