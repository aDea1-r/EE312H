#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Invent.h"
#include "MyString.h"
using namespace std;

FILE *input_stream;
FILE* input_stream_real;
String inventory2;
String purchase;
String summarize;
String quit;

void readInput(const char* file_name)
{
    String next_command;
    bool all_done = false;

    /* open the file */
    input_stream_real = fopen(file_name, "r");
    if (input_stream_real == 0)
    {
        printf("sorry, I could not open %s for reading\n", file_name);
        exit(1);
    }

    /* main loop, read commands from input file */
    do
    {
        readString(&next_command);
        if (StringIsEqualTo(&next_command, &inventory2))
        {
            processInventory();
        }
        else if (StringIsEqualTo(&next_command, &purchase))
        {
            processPurchase();
        }
        else if (StringIsEqualTo(&next_command, &summarize))
        {
            processSummarize();
        }
        else if (StringIsEqualTo(&next_command, &quit))
        {
            all_done = true;
        }

        else
        {
            printf("Encountered an error in input file:\nOffending input:");
            StringPrint(&next_command);
            printf("\n");
            exit(2);
        }
        StringDestroy(&next_command);
    }
    while (!all_done);
}

int main(int argc, char *argv[])
{
    /* we make four "constant" strings for the four comamnds */
    inventory2 = StringCreate("Inventory");
    purchase = StringCreate("Purchase");
    summarize = StringCreate("Summarize");
    quit = StringCreate("Quit");


    readInput(argv[1]);
    reset();


    /* all the test are done, time to clean up, let's deallocate our "constant strings" */
    StringDestroy(&inventory2);
    StringDestroy(&purchase);
    StringDestroy(&summarize);
    StringDestroy(&quit);

    return 0;
}

void readNum(int* p)
{
    fscanf(input_stream_real, "%d", p);
}

void readString(String* p)
{
    char buff[BUFSIZ];
    fscanf(input_stream_real, "%s", buff);
    *p = StringCreate(buff);
}
