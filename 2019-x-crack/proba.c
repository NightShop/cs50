#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string salt1 = argv[1];
        char salt[3]; 
        strncpy(salt, salt1, 2);
        salt[2] ='\0';
        char input[5];
        int sp = 65
        int zg = 67;
        char check[] = "AA";
          
        do 
        {        
            int i = sp;
            input[0] = (char) i;
            if (i >= zg)
                
        }
        while(strcmp(input, check) != 0) ;
        
    }
    else
    {
        printf("Wrong input\n");
        return 1;
    }
}
