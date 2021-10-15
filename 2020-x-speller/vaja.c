#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

int main(void)
{
    char beseda[10] = "-aA' -BatG";

    char beseda1[10];
    for (int i = 0; i <12; i++)
    {
        beseda1[i] = tolower(beseda[i]);
    }
    //char *beseda = malloc(sizeof(char)*20);

    printf("%s\n", beseda1);
}