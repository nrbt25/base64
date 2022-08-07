#include <stdio.h>
#include <stdint.h>

#include "base64.h"

int main()
{
    uint8_t src[] = "Hello base64!";
    int srclen = sizeof(src) / sizeof(char);
    char dst[sizeof(src) + sizeof(src) / 3 + 1];

    base64_encode(src, srclen, dst);

    printf("%s", dst);

    return 0;
}
