#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number = get_long ("Input card number:\n");
    long number1 = number/100000000000000;
    int number2 = number1;
    int sum = 0;
    int sum1 = 0;
    int sum11 = 0;
    int sum22 = 0;
    for (int i = 1; i <17; i++)
    {
        
        if (i % 2 == 0)
        {
            printf("I: %i\n", i);
            sum = number % 10;
            printf("sum:%i\n", sum);
            int sum01 = sum*2;
            printf("sum01:%i\n", sum01);
            if (sum01 > 9)
            {
                sum11 = sum11 + 1 + (sum01 % 10);
            }
            else
            {
                sum11 = sum11 + sum01;
            }
        } 
        else
        {
            sum11 = sum11 + (number % 10);
        }
        number = number /10;
        printf("%i\n", sum11);
    } 
    if (sum11 % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (number2 == 34 || number2 == 37)
    {
        printf("AMEX\n");
    }
    else if (number2 > 50 && number2 <56)
    {
        printf("MASTERCARD\n");    
    }
       
    else if (number2/10 == 4)
    {
       printf("VISA\n");    
    }
    else
    {
        printf("INVALID\n");
    }
        
}
