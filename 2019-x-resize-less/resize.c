// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize N infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    int n = atoi(argv[1]);

    //check if it is from 0 to 100
    if (n<0 || n>100)
    {
        fprintf(stderr, "Number not in range\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // store temporary values of original file
    int biHeightOld = abs(bi.biHeight);
    int biWidthOld = bi.biWidth;

    //adjust BITMAPINFOHEADER
    int prazne = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //bf.bfSize = bf.bfSize + prazne*bi.biHeight + 3*(-bi.biHeight*n*(bi.biWidth)*n+(bi.biWidth*bi.biHeight)) + bi.biHeight * n * ((4 - (bi.biWidth * n * sizeof(RGBTRIPLE) % 4)) % 4);
    bi.biWidth = n * bi.biWidth;
    bi.biHeight = n * bi.biHeight;
    int paddingNew = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = 3 *abs(bi.biHeight * bi.biWidth) + abs(bi.biHeight)*paddingNew;
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);



    // iterate over infile's scanlines
    for (int i = 0; i < biHeightOld; i++)
    {

        for (int a = 0; a < n; a++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < biWidthOld; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int k = 0; k < n; k++)
                {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            for (int b = 0; b < paddingNew; b++)
            {
            fputc(0x00, outptr);
            }


            if (a != n - 1)
            {
                fseek(inptr, padding, SEEK_CUR);
                fseek(inptr, -sizeof(RGBTRIPLE)*biWidthOld-padding, SEEK_CUR);
            }
        }


        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        //for (int k = 0; k < padding; k++)
        //{
        //    fputc(0x00, outptr);
        //}
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
