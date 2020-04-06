/*
 * Project 4 Test Support
 */

#include <algorithm>
#include <fstream>
#include <regex>
#include <string>

#include "gtest/gtest.h"
#include "TestSupport.h"

void randomSet(Set *s)
{
    Set t;
    int n = rand() % MAX_SET_SIZE + 1;

    createEmptySet(&t);
    for (int i = 0; i < n; i++)
    {
        insertSet(&t, rand() % MAX_SET_SIZE);
    }

    reassignSet(s, &t);
    destroySet(&t);
}

void checkCase(setFun fun, Set *s1, Set *s2, Set *expect)
{
    Set res;
    createCopySet(&res, s1);

    (*fun)(&res, s2);

    ASSERT_TRUE(isEqualToSet(&res, expect));
    destroySet(&res);
}

bool checkCaseNew(setFun fun, Set *s1, Set *s2, Set *expect)
{
    Set res;
    createCopySet(&res, s1);

    (*fun)(&res, s2);

    bool test_result = isEqualToSet(&res, expect);
    destroySet(&res);
    return test_result;
}



void assertFilesEqual(const char *pszFile1, const char *pszFile2)
{
    std::ifstream file1(pszFile1);
    std::ifstream file2(pszFile2);

    while (!file1.eof() && !file2.eof())
    {
        std::string line1;
        std::string line2;

        std::getline(file1, line1);
        std::getline(file2, line2);

        ASSERT_EQ(line1, line2) << "Inconsistent output" << std::endl
            << "\t" << pszFile1 << ":\t" << line1 << std::endl
            << "\t" << pszFile2 << ":\t" << line2 << std::endl;
    }

    ASSERT_TRUE(file1.eof()) << pszFile1 << " has extra output";
    ASSERT_TRUE(file2.eof()) << pszFile2 << " has extra output";
}


/* Extract a collection of sets from a file */
/*bool ExtractSets(std::set<int> *sets, int count, const char *fileName)
{
    std::ifstream file(fileName);
    ASSERT_FALSE(file.fail());

    int i;
    for (i = 0; !file.eof() && i < count;)
    {
        // Each set is on its own line
        std::string line;
        std::getline(file, line);

        // Set is in the format {a,b,...,n}
        std::regex collection_regex("\\{.*\\}");
        std::smatch collection_matches;

        std::regex_search(line, collection_matches, collection_regex);
        for (auto &sub_match : collection_matches)
        {
            const std::string &collection = sub_match.str();
            std::regex elem_regex("-?\\d+");

            auto begin = std::sregex_iterator(std::begin(collection), std::end(collection), elem_regex);
            auto end = std::sregex_iterator();

            for (auto it = begin; it != end; ++it)
            {
                // Convert each element to an integer
                int elem = atoi(it->str().c_str());
                sets[i].insert(elem);
            }

            i++;
        }
    }

    return i == count;
}*/

/* Assert two sets are equal */
void assertSetsAreEqual(const std::set<int> &s1, const std::set<int> &s2)
{
    ASSERT_TRUE(s1 == s2);
}

void assertSetsAreEqual(const std::set<int> &s1, Set *s2)
{
    std::set<int> result;
//    ASSERT_TRUE(ExtractSets(&result, 1, OUTPUT_FILE_NAME));
    for(int i =0;i<s2->len;i++){
        result.insert(s2->elements[i]);
    }
    assertSetsAreEqual(s1, result);
}
