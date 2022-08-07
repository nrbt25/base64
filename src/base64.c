#include <stdint.h>

#include "base64.h"

/*
 *  Source : https://github.com/torvalds/linux/blob/b2a88c212e652e94f1e4b635910972ac57ba4e97/lib/base64.c
 */

char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/*  Encode data to base64
 *  src : Data to encode
 *  srclen : Length of the data to encode
 *  dst : The encoded output
 */

int base64_encode(const uint8_t *src, int srclen, char *dst)
{
    uint32_t ac = 0; // accumulator
    int bits = 0;    // number of bits to read
    char *cp = dst;  // reference to output for pointer arithmetic

    for (int i = 0; i < srclen - 1; i++) // srclen - 1 to remove the '\0' char at the end of the source
    {
        // add new bits to the buffer (8 bits at a time)
        ac = (ac << 8) | src[i];
        bits += 8;

        do
        {
            // read bits to the buffer (6 bits at a time)
            bits -= 6;
            *cp++ = base64_table[(ac >> bits) & 0x3f];

        } while (bits >= 6);
    }

    // if there are still some bits left...
    if (bits)
    {
        *cp++ = base64_table[(ac << (6 - bits)) & 0x3f];
        bits -= 6;
    }

    // padding
    while (bits < 0)
    {
        *cp++ = '=';
        bits += 2;
    }

    *cp++ = '\0';

    return cp - dst;
}