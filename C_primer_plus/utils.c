/*
 * Common Utils
 *
 *
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <limits.h>


int string2ll(const char *s, size_t slen, int64_t *value)
{
    const char *p = s;
    size_t plen = 0;
    int negative = 0;
    int64_t v;

    if (plen == slen)
    {
        return 0;
    }

    if (slen == 1 && p[0] == '0')
    {
        if (value != NULL) *value = 0;
        return 1;
    }

    if (p[0] == '-')
    {
        negative = 1;
        p++;
        plen++;

        /* Abort on only a negative sign. */
        if (plen == slen)
            return 0;
    }

    if (p[0] >= '1' && p[0] <= '9')
    {
        v = p[0] - '0';
        p++;
        plen++;
    } else
    {
        return 0;
    }

    while (plen < slen && p[0] >= '0' && p[0] <= '9')
    {
        if (v > (ULLONG_MAX / 10)) /* Overflow. */
            return 0;
        v *= 10;

        if (v > (ULLONG_MAX - (p[0] - '0'))) /* Overflow. */
            return 0;
        v += p[0] - '0';

        p++;
        plen++;
    }


    if (plen < slen)
    {
        return 0;
    }

    if (negative)
    {
        if (v > ((int64_t) (-(LLONG_MIN + 1)) + 1)) /* Overflow. */
            return 0;
        if (value != NULL) *value = -v;
    } else
    {
        if (v > LLONG_MAX) /* Overflow. */
            return 0;
        if (value != NULL) *value = v;
    }
    return 1;
}
