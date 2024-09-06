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


// Function to find the square-root of N
float findSQRT(int number)
{
    int start = 0, end = number;
    int mid;

    // To store the answer
    float ans;

    // To find integral part of square
    // root of number
    while (start <= end)
    {
        // Find mid
        mid = (start + end) / 2;

        // If number is perfect square
        // then break
        if (mid * mid == number)
        {
            ans = mid;
            break;
        }

        // Increment start if integral
        // part lies on right side
        // of the mid
        if (mid * mid < number)
        {
            //first start value should be added to answer
            ans = start;
            //then start should be changed
            start = mid + 1;
        }

        // Decrement end if integral part
        // lies on the left side of the mid
        else
        {
            end = mid - 1;
        }
    }

    // To find the fractional part
    // of square root upto 5 decimal
    float increment = 0.1;
    for (int i = 0; i < 5; i++)
    {
        while (ans * ans <= number)
        {
            ans += increment;
        }

        // Loop terminates,
        // when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}


int utf8_encode(char *out, uint32_t utf_point)
{
    if (utf_point <= 0x7F)
    {
        out[0] = (char) utf_point;
        out[1] = 0;
        return 1;
    } else if (utf_point <= 0x07FF)
    {
        out[0] = (char) (((utf_point >> 6) & 0x1F) | 0xC0);
        out[1] = (char) (((utf_point >> 0) & 0x3F) | 0x80);
        out[2] = 0;
        return 2;
    } else if (utf_point <= 0xFFFF)
    {
        // 3-byte unicode
        out[0] = (char) (((utf_point >> 12) & 0x0F) | 0xE0);
        out[1] = (char) (((utf_point >> 6) & 0x3F) | 0x80);
        out[2] = (char) (((utf_point >> 0) & 0x3F) | 0x80);
        out[3] = 0;
        return 3;
    } else if (utf_point <= 0x10FFFF)
    {
        // 4-byte unicode
        out[0] = (char) (((utf_point >> 18) & 0x07) | 0xF0);
        out[1] = (char) (((utf_point >> 12) & 0x3F) | 0x80);
        out[2] = (char) (((utf_point >> 6) & 0x3F) | 0x80);
        out[3] = (char) (((utf_point >> 0) & 0x3F) | 0x80);
        out[4] = 0;
        return 4;
    } else
    {
        out[0] = (char) 0xEF;
        out[1] = (char) 0xBF;
        out[2] = (char) 0xBD;
        out[3] = 0;
        return 0;
    }
}


int unicode_to_utf8(uint8_t *buf, unsigned int c)
{
    uint8_t *q = buf;

    if (c < 0x80)
    {
        *q++ = c;
    } else
    {
        if (c < 0x800)
        {
            *q++ = (c >> 6) | 0xc0;
        } else
        {
            if (c < 0x10000)
            {
                *q++ = (c >> 12) | 0xe0;
            } else
            {
                if (c < 0x00200000)
                {
                    *q++ = (c >> 18) | 0xf0;
                } else
                {
                    if (c < 0x04000000)
                    {
                        *q++ = (c >> 24) | 0xf8;
                    } else if (c < 0x80000000)
                    {
                        *q++ = (c >> 30) | 0xfc;
                        *q++ = ((c >> 24) & 0x3f) | 0x80;
                    } else
                    {
                        return 0;
                    }
                    *q++ = ((c >> 18) & 0x3f) | 0x80;
                }
                *q++ = ((c >> 12) & 0x3f) | 0x80;
            }
            *q++ = ((c >> 6) & 0x3f) | 0x80;
        }
        *q++ = (c & 0x3f) | 0x80;
    }
    return q - buf;
}
