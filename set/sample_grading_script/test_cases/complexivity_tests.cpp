#include "gtest/gtest.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "TestSupport.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <chrono>
#include "Set.h"

unsigned time();
int const number_of_tests = 1000;
int const maximum_set_size = 100;

void randomSet(Set* s);

void showOutput(const char* str, Set* set) {
	printf("%s", str);
	displaySet(set);
	printf("\n");
}


typedef void (*setFun)(Set*, const Set*);

/*
 * create two sets with n random elements
 * the sets should have 50% of the elements in common
 */
void createRandomSetN(int n, Set* a, Set* b) {
	int x;
	int last_size = 0;
	createEmptySet(a);
	while (a->len < n) {
		if (a->len != last_size) {
			last_size = a->len;
			if (last_size % 1000 == 0) {
			}
		}
		x = 2 * (5 * n - (rand() % (10 * n)));
		if (isMemberSet(a, x)) { continue; } // try another number
		/* a will have only even elements */
		insertSet(a, x);
		if ((rand() % 2) == 0) {
			insertSet(b, x);
		} else {
			insertSet(b, x + 1); // an odd value, can't be in a
		}
	}
	assert(a->len == b->len);
}

typedef void (*Function)(void);

double timeFunction(Function f) {
	int reps = 128;
	uint64_t time = 0;
	volatile int k;
	while (time < 6000) {
		if (reps > 1000000000) { return 0.0; } // overflow?
		auto start = std::chrono::high_resolution_clock::now();
		for (k = 0; k < reps; k += 1) {
			f();
		}
		auto end = std::chrono::high_resolution_clock::now();
		time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		reps *= 2;
	}
	return ((double) time) / reps;
}

volatile int bogus_value; // used to ensure compiler does not optimize away our func calls

Set* setA;
Set* setB;
Set* setAPrime; // almost exactly the same as A

int is_mem_x;
void isMemberTimeFun(void) {
	if (isMemberSet(setA, is_mem_x)) {
		is_mem_x ^= 1;
		is_mem_x <<= 1;
	} else {
		is_mem_x >>= 1;
		is_mem_x ^= 2;
	}
}
		
void isEqualTimeFun(void) {
	bogus_value = isEqualToSet(setA, setAPrime);
}
	
void isSubsetTimeFun(void) {
	bogus_value = isSubsetOf(setA, setAPrime);
}

void unionTimeFun(void) {
	Set t;
	createCopySet(&t, setA);
	unionInSet(&t, setB);
	destroySet(&t);
}

void intersectTimeFun(void) {
	Set t;
	createCopySet(&t, setA);
	intersectFromSet(&t, setB);
	destroySet(&t);
}

void subtractTimeFun(void) {
	Set t;
	createCopySet(&t, setA);
	subtractFromSet(&t, setB);
	destroySet(&t);
}

bool checkLinear(double times[], int sizes[], int first, int last) {
	double time_ratio = times[last] / times[first];
	double size_ratio = sizes[last] / sizes[first];
	
	if (time_ratio < size_ratio * 1.25) {
		return true;
	} else {
		return false;
	}
}

bool checkSubLinear(double times[], int sizes[], int first, int last) {
	double time_ratio = times[last] / times[first];
	double size_ratio = sizes[last] / sizes[first];
	
	if (time_ratio < size_ratio * 0.5) {
		return true;
	} else {
		return false;
	}
}

enum Tests {
	IS_MEMBER = 0,
	INSERT = 1,
	REMOVE = 2,
	IS_EQUAL_TO = 3,
	IS_SUBSET_OF = 4,
	UNION_IN = 5,
	INTERSECT_FROM = 6,
	SUBTRACT_FROM = 7,
	
	NUM_TESTS_TIME /* MUST BE LAST */
};

typedef enum Scales {
	SUB_LINEAR,
	LINEAR,
	SUPER_LINEAR
} Scales;
/* NOTE: the order of these strings MUST MATCH EXACTLY the order of the Scales enum */
const char* scaling_strings[] = {
	"sub linear (YAHOO!)",
	"linear",
	"super linear, yuck."
};

int sizes[] = { 100, 400, 1600, 6400, 25600 };
//const unsigned num_times = sizeof(sizes) / sizeof(int);
#define num_times (sizeof(sizes) / sizeof(int))
Set setsA[num_times];
Set setsAPrime[num_times];
Set setsB[num_times];
double times[num_times];

Scales determineScaling(Function fun) {
	bool linear;
	bool sublinear;
	
	unsigned trial = 0;
	for (; trial < num_times; trial += 1) {	
		if (trial > 0 && ((times[trial - 1] * sizes[trial])	> 10)) { break; }
		setA = &setsA[trial];
		setB = &setsB[trial];
		setAPrime = &setsAPrime[trial];
		times[trial] = timeFunction(fun);
	}
	
	if (trial < 3) {
		printf("I'm sorry, your program is way too inefficient.\n");
		printf("you'll need to find a way-faster computer to test it on\n");
		return SUPER_LINEAR;
	}
	linear = checkLinear(times, sizes, 0, trial - 1) 
		|| checkLinear(times, sizes, 1, trial - 1);
	sublinear = checkSubLinear(times, sizes, 0, trial - 1)
		|| checkSubLinear(times, sizes, 1, trial - 1);
	
	if (sublinear) { return SUB_LINEAR; }
	else if (linear) { return LINEAR; }
	else { return SUPER_LINEAR; }
}


TEST(Test17, TimeTest)
{
    {
        Scales behavior[NUM_TESTS_TIME];

        for (uint32_t k = 0; k < num_times; k += 1) {
            createRandomSetN(sizes[k], &setsA[k], &setsB[k]);
            int x = 10 * sizes[k];
            createCopySet(&setsAPrime[k], &setsA[k]);
            insertSet(&setsA[k], x);
            insertSet(&setsAPrime[k], x + 1);
            insertSet(&setsB[k], x);
        }
        
        behavior[IS_MEMBER] = determineScaling(&isMemberTimeFun);
        ASSERT_TRUE( behavior[IS_MEMBER] == SUB_LINEAR);

        behavior[IS_EQUAL_TO] = determineScaling(&isEqualTimeFun);

        behavior[IS_SUBSET_OF] = determineScaling(&isSubsetTimeFun);
        ASSERT_TRUE(behavior[IS_SUBSET_OF] == LINEAR || behavior[IS_SUBSET_OF] == SUB_LINEAR);
        
        behavior[UNION_IN] = determineScaling(&unionTimeFun);
        ASSERT_TRUE(behavior[UNION_IN] == LINEAR || behavior[UNION_IN] == SUB_LINEAR);

        behavior[INTERSECT_FROM] = determineScaling(&intersectTimeFun);
        ASSERT_TRUE(behavior[INTERSECT_FROM] == LINEAR || behavior[INTERSECT_FROM] == SUB_LINEAR);
        
        behavior[SUBTRACT_FROM] = determineScaling(&subtractTimeFun);
        ASSERT_TRUE(behavior[SUBTRACT_FROM] == LINEAR || behavior[SUBTRACT_FROM] == SUB_LINEAR);

        for (int i = 0; i < num_times; i++) {
            destroySet(&setsA[i]);
            destroySet(&setsAPrime[i]);
            destroySet(&setsB[i]);
        }

    }
}
