/*
 * Project1.cpp
 * 
 * Name: Adeel Rehman
 * EE312 Spring 2020
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
//#include <main.cpp>

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helpful. Global variables are by no means necessary for this project.
 */

bool isChar(char c);
bool search(const char word[],const char dict[]);
bool sameChar(char a, char b);

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restrictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */


void spellCheck(char article[], char dictionary[]) {
    uint32_t i = 0;
    while(article[i]) { //loop through each word of article
        uint32_t j = 0;
        for(; isChar(article[i+j]); j++); //calc length of word
//        printf("final char is %c and %d\n",article[i+j],j);

        char word[j+1];
        word[j] = 0;
        for(uint32_t k=0; k<j; k++) {
            word[k] = article[i+k];
        }
//        printf("%s\n",word);
        if(j>=2) {
            bool misspelled = !(search(word,dictionary) );
            if(misspelled) {
                printf("%s\n", word);

            }
        }

        i = i+j;
        for(; !isChar(article[i]) && article[i]; i++); //skip punctuation
    }
}

bool isChar(char c) {
    return !(c>'z' || c<'A' || (c>'Z' && c<'a'));
}

// word and dict both end in null chars
bool search(const char word[],const char dict[]) {
    uint32_t dictspot = 0;
    uint32_t wordspot = 0;
    while(dict[dictspot]) {
        bool loopran = false;
        while(word[wordspot] && dict[dictspot] && dict[dictspot]!='\n' && sameChar(word[wordspot], dict[dictspot]) ) { //\n may be redundant
            wordspot++;
            dictspot++;
//            printf("in loop 2");
            loopran = true;
        }
//        printf("its %c",word[wordspot]);
        if(!word[wordspot] && loopran && dict[dictspot]=='\n') //determine why loop terminated and act
            return true;
        if(!dict[dictspot] && loopran)
            return false;

        //go to next dict entry, and reset wordspot
        wordspot = 0;
//        printf("%c", dict[dictspot]);
        for (;dict[dictspot] != '\n' && dict[dictspot]; dictspot++);
//            printf("in loop 5");
        if(dict[dictspot])
            dictspot++;
    }
    return false;
}

bool sameChar(char a, char b) {
    if (a >= 'A' && a <= 'Z') {
        a += 32; //conversion factor to make uppercase letters lowercase
    }
    if (b >= 'A' && b <= 'Z') {
        b += 32;
    }
    return a==b;
}
