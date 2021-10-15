#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number; 
    
    do
    {
       number = get_int ("How high do you want your pyramid?\n");
    }
    while (number>8 || number<1);
    for ( int i = 0; i < number; i++)
    {
       for ( int y = number - i; y > 1; y--) 
       {
           printf(" ");
       }
        for ( int x = 0; x < i ; x++)
       {
         printf("#");  
       }
       
       printf("#  ");
        
        for ( int x = 0; x < i ; x++)
       {
         printf("#");  
       }
        printf("#\n");
        
    }
}
