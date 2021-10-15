#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float owed;
    int owed_i;
    do
    {
        owed = get_float("Change owed: ");
        owed_i = round(owed*100);
    }
    while (owed_i < 0);
    int st_25 = round(owed_i/25);
    int ost1 = owed_i % 25;
    int st_10 = round(ost1/10);
    int ost2 = ost1 % 10;
    int st_5 = round(ost2/5);
    int ost3 = ost2 % 5;
    int st_1 = round(ost3/1);
    printf("%i\n", st_1 + st_5 + st_10 + st_25);
    
}
