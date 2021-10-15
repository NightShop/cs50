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
        char input[] = "ABCDE";
        
        int zg = 66;
        printf("%s", crypt(input, salt));
        //50l0NWdjxDj/w
        // ABCDE 509fm.6m30.ok
    }
    else
    {
        printf("Wrong input\n");
        return 1;
    }
}
