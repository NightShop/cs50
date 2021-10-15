#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf (stderr, "Usage ./recover.c filename\n");
        return 1;
    }

    //remember filenames
    char *raw_file = argv[1];

    //make file opened for reading
    FILE *inptr = fopen(raw_file, "r");

    //cehck pointer so its not null
    if (inptr == NULL)
    {
        fprintf (stderr, "Could not opent %s\n", raw_file);
        return 2;
    }

    BYTE buffer [512];
    int no_file = 0;
    FILE *img = NULL;
    while (fread(&buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (no_file > 0)
            {
                fclose(img);
            }

            char filename[7];
            sprintf(filename, "%03i.jpg", no_file);
            img = fopen(filename, "w");
            fwrite(&buffer, sizeof(buffer), 1, img);
            no_file += 1;
        }

        else if (no_file > 0)
        {
            fwrite(&buffer, sizeof(buffer), 1, img);
        }


    }
}
