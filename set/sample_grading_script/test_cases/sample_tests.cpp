#include "gtest/gtest.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "TestSupport.h"

TEST(Test01, VisualTests)
{
    {
        std::set<int> basic, random;

        Set s;
        Set t;

        int i;
        createEmptySet(&s);
        assertSetsAreEqual(basic, &s);

        for (i = 0; i < 10; i++)
        {
            insertSet(&s, i);
            basic.insert(i);
        }
        assertSetsAreEqual(basic, &s);

        for (i = 0; i < 10; i++)
        {
            insertSet(&s, i);
        }
        assertSetsAreEqual(basic, &s);

        createCopySet(&t, &s);
        assertSetsAreEqual(basic, &t);

        Set temp;
        int n = rand() % MAX_SET_SIZE + 1;

        createEmptySet(&temp);
        for (int i = 0; i < n; i++)
        {
            int val = rand() % MAX_SET_SIZE;
            insertSet(&temp, val);
            random.insert(val);
        }

        reassignSet(&t, &temp);
        destroySet(&temp);
        assertSetsAreEqual(random, &t);

        destroySet(&s);
        destroySet(&t);
    }
}

TEST(Test02, EqualityTests)
{
    
    {
        for (int i = 0; i < NUM_TESTS; i++)
        {
            Set s;
            Set t;

            createEmptySet(&s);
            randomSet(&s);
            createCopySet(&t, &s);

            ASSERT_TRUE(isEqualToSet(&t, &s));
            ASSERT_TRUE(isEqualToSet(&s, &t));

            insertSet(&t, MAX_SET_SIZE);

            ASSERT_FALSE(isEqualToSet(&s, &t));
            ASSERT_FALSE(isEqualToSet(&t, &s));

            randomSet(&t);

            ASSERT_FALSE(isEqualToSet(&t, &s));

            destroySet(&s);
            destroySet(&t);
        }
    }
}

TEST(Test03, RelationalTests)
{
    
    {
        Set s;
        Set t;

        createEmptySet(&s);
        createEmptySet(&t);

        for (int i = 0; i < NUM_TESTS; i++)
        {
            randomSet(&s);
            reassignSet(&t, &s);

            ASSERT_TRUE(isSubsetOf(&s, &t));
            ASSERT_TRUE(isSubsetOf(&t, &s));
            ASSERT_TRUE(isEqualToSet(&s, &t));
            ASSERT_TRUE(isEqualToSet(&t, &s));

            insertSet(&s, rand() % MAX_SET_SIZE + MAX_SET_SIZE);

            ASSERT_TRUE(isSubsetOf(&t, &s));
            ASSERT_FALSE(isSubsetOf(&s, &t));
        }

        destroySet(&s);
        destroySet(&t);
    }
}

TEST(Test05, SpecialCaseTests)
{
    
    {
        Set empty;
        Set universal;
        Set s;
        Set r;
        int i;

        createEmptySet(&empty);
        createEmptySet(&universal);
        createEmptySet(&r);

        for (i = 0; i < MAX_SET_SIZE; i++)
        {
            insertSet(&universal, i);
        }

        ASSERT_TRUE(checkCaseNew(&subtractFromSet, &universal, &universal, &empty));
        ASSERT_TRUE(checkCaseNew(&unionInSet, &universal, &universal, &universal));
        ASSERT_TRUE(checkCaseNew(&intersectFromSet, &universal, &universal, &universal));
        ASSERT_TRUE(checkCaseNew(&intersectFromSet, &universal, &empty, &empty));
        ASSERT_TRUE(checkCaseNew(&intersectFromSet, &empty, &universal, &empty));
        ASSERT_TRUE(checkCaseNew(&unionInSet, &universal, &empty, &universal));
        ASSERT_TRUE(checkCaseNew(&unionInSet, &empty, &universal, &universal));
        ASSERT_TRUE(checkCaseNew(&unionInSet, &empty, &empty, &empty));
        ASSERT_TRUE(checkCaseNew(&subtractFromSet, &empty, &empty, &empty));
        ASSERT_TRUE(checkCaseNew(&intersectFromSet, &empty, &empty, &empty));

        createEmptySet(&s);
        ASSERT_TRUE(isEmptySet(&s));

        for (i = 0; i < 10; i++)
        {
            insertSet(&s, i);
        }

        ASSERT_TRUE(s.len == 10);

        for (i = 0; i < 10; i++)
        {
            ASSERT_TRUE(isMemberSet(&s, i));
        }

        for (i = 0; i < 10; i++)
        {
            removeSet(&s, i);
            removeSet(&s, i);
            ASSERT_TRUE(s.len == 9 - i);
        }

        ASSERT_TRUE(isEmptySet(&s));

        for (i = 0; i < NUM_TESTS; i++)
        {
            randomSet(&s);
            ASSERT_TRUE(isSubsetOf(&empty, &s));
            ASSERT_FALSE(isSubsetOf(&s, &empty));
            ASSERT_TRUE(isSubsetOf(&s, &universal));
            ASSERT_FALSE(isSubsetOf(&universal, &s));

            ASSERT_TRUE(checkCaseNew(&intersectFromSet, &empty, &s, &empty));
            ASSERT_TRUE(checkCaseNew(&intersectFromSet, &s, &empty, &empty));
            ASSERT_TRUE(checkCaseNew(&intersectFromSet, &universal, &s, &s));
            ASSERT_TRUE(checkCaseNew(&intersectFromSet, &s, &universal, &s));

            ASSERT_TRUE(checkCaseNew(&unionInSet, &universal, &s, &universal));
            ASSERT_TRUE(checkCaseNew(&unionInSet, &s, &universal, &universal));

            ASSERT_TRUE(checkCaseNew(&subtractFromSet, &s, &empty, &s));

            assignSet(&r, &universal);
            subtractFromSet(&r, &s);
            ASSERT_TRUE(checkCaseNew(&subtractFromSet, &universal, &r, &s));
            ASSERT_TRUE(checkCaseNew(&unionInSet, &s, &r, &universal));
            ASSERT_TRUE(checkCaseNew(&unionInSet, &r, &s, &universal));
        }

        destroySet(&empty);
        destroySet(&universal);
        destroySet(&s);
        destroySet(&r);
    }
}

TEST(Test06, AlgebraicTests)
{
    
    {
        Set empty;
        Set universal;
        Set s;
        Set t;
        Set u;
        Set v;
        Set w;
        int i;

        createEmptySet(&empty);
        createEmptySet(&universal);

        for (i = 0; i < MAX_SET_SIZE; i++)
        {
            insertSet(&universal, i);
        }

        createEmptySet(&s);
        createEmptySet(&t);
        createEmptySet(&u);
        createEmptySet(&v);
        createEmptySet(&w);

        ASSERT_FALSE(isEqualToSet(&empty, &universal));

        for (i = 0; i < NUM_TESTS; i++)
        {
            randomSet(&u);
            randomSet(&v);
            randomSet(&w);

            /* u + v == v + u */
            assignSet(&s, &u);
            unionInSet(&s, &v);
            assignSet(&t, &v);
            unionInSet(&t, &u);
            ASSERT_TRUE(isEqualToSet(&s, &t));

            /* u + (v + w) == (u + v) + w */
            assignSet(&t, &v);
            unionInSet(&t, &w);
            assignSet(&s, &u);
            unionInSet(&s, &t);
            assignSet(&t, &u);
            unionInSet(&t, &v);
            unionInSet(&t, &w);
            ASSERT_TRUE(isEqualToSet(&s, &t));

            /* u * v == v * u */
            assignSet(&s, &u);
            intersectFromSet(&s, &v);
            assignSet(&t, &v);
            intersectFromSet(&t, &u);
            ASSERT_TRUE(isEqualToSet(&s, &t));

            /* u * (v * w) == (u * v) * w */
            assignSet(&t, &v);
            intersectFromSet(&t, &w);
            assignSet(&s, &u);
            intersectFromSet(&s, &t);
            assignSet(&t, &u);
            intersectFromSet(&t, &v);
            intersectFromSet(&t, &w);
            ASSERT_TRUE(isEqualToSet(&s, &t));

            /* u - v == u - (u * v) */
            assignSet(&s, &u);
            intersectFromSet(&s, &v);
            assignSet(&t, &u);
            subtractFromSet(&t, &s);
            assignSet(&s, &u);
            subtractFromSet(&s, &v);
            ASSERT_TRUE(isEqualToSet(&s, &t));
        }

        destroySet(&empty);
        destroySet(&universal);
        destroySet(&s);
        destroySet(&t);
        destroySet(&u);
        destroySet(&v);
        destroySet(&w);
    }
}
