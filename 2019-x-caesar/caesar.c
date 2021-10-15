#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Preveri stevilo vnesenih besed
    if (argc == 2)
    {
        string s = argv[1];
        // Gre cez vsak znak kljuca in preveri ali je stevilka         ter jo pretvori
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (isdigit(argv[1][i]) == false) 
            {
                printf("Usage: ./caesar key\n");
                return 1;    
            }
            
        }
        int k = atoi(argv[1]) % 25;
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n =strlen(plain); i < n; i++)
        {
            if (isalpha(plain[i]))
            {
                if (plain[i] + k < 123 && plain[i] + k > 99)
                {
                    printf("%c", plain[i] + k);    
                }
                else
                {
                    printf("%c", plain[i] + k - 26);
                }
            }
            else
            {
                printf("%c", plain[i]);
            }   
        }
        printf("\n");
    }
    // Še enkrat prosi za vnos    
    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}
