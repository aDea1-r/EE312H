// String ADT Project3.cpp
// EE 312 Project 3 submission by
// Adeel Rehman
// aur228
// Slip days used: 0
// Spring 2020
// Copy and paste this file at the top of all your submitted source code files.  Do not turn this in by itself.


#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <cstdio>
#include "String.h"

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    UTString *s = (UTString*) malloc(sizeof(UTString));
    uint32_t i;
    for(i=0; src[i] != 0; i++);

//    printf("gay: %s, %d\n",src,i);

    s->length = i;
    if (i<11)
        i=11;
    s->string = (char*) malloc(i* sizeof(char) + 5); //add 1 for /0, 4 for terminator
    s->capacity = i;

    for(i=0; i<s->length + 1; i++) {
        s->string[i] = src[i];
    }
    *((uint32_t*) &(s->string[i]) ) = SIGNATURE;

    return s;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    return (*s).length;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    uint32_t i;
    uint32_t prevLength = s->length;
    for(i = s->length; i < s->capacity && suffix[i-prevLength]; i++ ) {
        s->string[i] = suffix[i- prevLength];
        s->length++;
    }
    s->string[i] = 0;
    *((uint32_t*) &(s->string[i+1]) ) = SIGNATURE;

    return s;


}

/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    uint32_t i = 0;
    dst->length = 0;
    for(i=0; i<dst->capacity && src[i]; i++) {
        dst->string[i] = src[i];
        dst->length++;
    }
    dst->string[i] = 0;
    *((uint32_t*) &(dst->string[i+1]) ) = SIGNATURE;

    return dst;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    free(self->string);
    free(self);
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    if(s->capacity < new_capacity) {
        s->string = (char*)realloc(s->string, new_capacity * sizeof(char) + 5);
        s->capacity = new_capacity;
    }
    return s;
}
