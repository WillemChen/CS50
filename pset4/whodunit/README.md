# Questions

## What's `stdint.h`?

it is a header that define a set of integer type aliases with specific requirement

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

For unsigned integer, it's just inter

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE:1 byte, DWORD:4 bytes, LONG:4 bytes, WORD:2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."
42 4D(hex) //in ascii,means BM

## What's the difference between `bfSize` and `biSize`?

bfsize is the size of bitmap file. bisize is the size of bitmapinfoheader.

## What does it mean if `biHeight` is negative?

if biheight is negative, the dib is top-down and the origin is left-upper corner

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

when the fopen function isn't success, function return NULL

## Why is the third argument to `fread` always `1` in our code?

the third argument decide the number of elements to be read. because the size of each data has been decided,the third argument has to be 1.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

0

## What does `fseek` do?

the fseek funtion set t

## What is `SEEK_CUR`?

the offset which is relative to the current position indicator

## Whodunit?

It was professor Plum with the candlestick in the library.
