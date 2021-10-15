# Questions

## What's `stdint.h`?

It makes possible creaton of certain types of integers (predefined with specific number of bits).

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Letter u in the beggining denotes undefined integer (else is defined) and the number denotes the width of the integer. It enables easier transition between different programs or languages or 

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

8, 32, 32, 16 bits.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM.

## What's the difference between `bfSize` and `biSize`?

bfSize is size in bytes of bitmap file, and biSize is number of bytes required by the structure (40 bytes).

## What does it mean if `biHeight` is negative?

That the origin of pixels is upper left. 

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

If the pointer to a file is incorect.

## Why is the third argument to `fread` always `1` in our code?

Because we read in one chunk and not character by character.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Sets the position in file.

## What is `SEEK_CUR`?

The function with wich you set the position in file to curent i.e. you tell fseek to make offset from current position.
