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
        char input[6];
        int zg = 130;
        //50l0NWdjxDj/w
        //// ABCDE 509fm.6m30.ok
           for (int i = 65; i < zg; i++)
           {
               input[0] = (char) i;
               printf("%s\n", input);
               if(strcmp(crypt(input, salt), argv[1]) == 0)
               {
               printf("PASS: %s\n", input);    
               return 0;
               }
               for (int j = 65; j < zg; j++)
               {
                   input[1] = (char) j;
                   printf("%s\n", input);
                   if(strcmp(crypt(input, salt), argv[1]) == 0)
                   {
                   printf("PASS: %s\n", input);    
                   return 0;
                   }
                   for (int k = 65; k < zg; k++)
                   {
                       input[2] = (char) k;
                       printf("%s\n", input);
                       if(strcmp(crypt(input, salt), argv[1]) == 0)
                       {
                       printf("PASS: %s\n", input);    
                       return 0;
                       }
                       for (int f = 65; f < zg; f++)
                       {
                           input[3] = (char) k;
                           printf("%s\n", input);
                           if(strcmp(crypt(input, salt), argv[1]) == 0)
                           {
                           printf("PASS: %s\n", input);    
                           return 0;
                           }
                           for (int l = 65; l < zg; l++)
                           {
                               input[4] = (char) l;
                               printf("%s\n", input);
                                   if(strcmp(crypt(input, salt), argv[1]) == 0)
                                   {
                                       
                                       printf("PASS: %s\n", input);    
                                       return 0;    
                                   }
                               printf("%s\n", input);
                           }
                       }
                   }    
               }
           }  
    }
    else
    {
        printf("Wrong input\n");
        return 1;
    }
}
