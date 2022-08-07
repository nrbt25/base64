#ifndef BASE64
#define BASE64

#include <stdint.h>

int base64_encode(const uint8_t *src, int srclen, char *dst);
// TODO: add base64 decoder

#endif