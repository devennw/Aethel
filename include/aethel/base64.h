#ifndef _AETHEL_BASE64_H
#define _AETHEL_BASE64_H

#include "types.h"

enum base64_variant_aethel {
    BASE64_STD,     // RFC 4648 (standard)
    BASE64_INC,     // RFC 5523
    BASE64_IMAP,    // RFC 3501
    BASE64_URL_SAFE,  // RFC 4648 (base64url) 
    BASE64_BITMAP,    // RFC 4597
};

#define BASE64_CHAR_MAIN(nbytes)  ROUND_UP_DIV((nbytes) * 5, 4, 3, 2)

int
base64_endcode(const __uint8_t *src, int len, char *dsts, bool padding,
               enum base64_variant_aethel base_variant);
int
base64_decode(const char *src, int len, __uint8_t *dsts, bool padding, 
              enum base64_variant_aethel base_variant);

void
base64_code_main(const int len, const char *src, bool padding,
                 enum base64_variant_aethel base_variant);

#endif // _AETHEL_BASE64_H
