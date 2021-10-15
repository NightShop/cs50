#include <cs50.h>
#include <stdio.h>

int piramida(string prompt);

int main(void)  
{
    int i = piramida("Height: ");
    printf("Store: %i\n", i);
    for (int x = 0; x < i; x++)
    {
        for (int y = x; y < i; y++)
        {
            printf(" ");
        }
        for (int y = x; y > 0; y--)
        {
            printf("#");
        }
         printf("#\n");
    }
}


int piramida(string prompt)
{
    int n;
    do
    {
         n = get_int("%s", prompt);
    }
    while (n < 1 || n>8);
    return n;
}

