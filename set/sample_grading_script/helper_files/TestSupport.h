/*
 * Project 4 Test Support
 */
#ifndef __TESTSUPPORT_H__
#define __TESTSUPPORT_H__
#include <set>

#include "Set.h"

#define NUM_TESTS           (100)
#define MAX_SET_SIZE        (50)

#define OUTPUT_FILE_NAME                ("test_output.txt")

typedef void(*setFun)(Set *, const Set *);

void randomSet(Set *s);
void checkCase(setFun fun, Set *s1, Set *s2, Set *expect);
bool checkCaseNew(setFun fun, Set *s1, Set *s2, Set *expect);



void assertFilesEqual(const char *pszFile1, const char *pszFile2);

/* Extract a collection of sets from a file */
//bool ExtractSets(std::set<int> *sets, int count, const char *fileName);

/* Assert two sets are equal */
void assertSetsAreEqual(const std::set<int> &s1, const std::set<int> &s2);
void assertSetsAreEqual(const std::set<int> &s1, Set *s2);

#endif
