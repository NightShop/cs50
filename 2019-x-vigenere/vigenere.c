#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    // Preveri stevilo vnesenih besed
    if (argc == 2)
    {
        string s = argv[1];
        int k;
        // int k = atoi(argv[1]) % 26;
        // Gre cez vsak znak kljuca in preveri ali je stevilka ter jo pretvori
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (isalpha(argv[1][i]) == false) 
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;    
            }
            
        }
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");
        int j = 0;
        for (int i = 0, n =strlen(plain); i < n; i++)
        {
            int g = j % strlen(argv[1]);
            //printf("  %i  ", g);
            k = shift(argv[1][g]);
            //printf ("%i", k);
            if (isalpha(plain[i]))
            {
                j++;
            }
                
            //printf("%i  ", i);
            //printf("%i\n", k);
            if (isalpha(plain[i]))
            {
                if (islower(plain[i]))
                {
                    if (plain[i] + k < 123 && plain[i] + k > 96)
                    {
                        printf("%c", plain[i] + k);
                    }
                
                    else
                    {
                        printf("%c", plain[i] + k - 26);
                    }  
                }
                // za velike crke isto
                else
                {
                    if (plain[i] + k < 91 && plain[i] + k > 64)
                    {
                        printf("%c", plain[i] + k);    
                    }
                
                    else
                    {
                        printf("%c", plain[i] + k - 26);
                    }
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
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

}

int shift(char c)
{
    int m = (int) c;
    if (isupper(c))
    {
        m = m - 65;
    }
    else
    {
        m = m - 97;
    }
    return m;   
}

