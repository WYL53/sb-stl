
#ifndef _SB_ALGO_H_
#define _SB_ALGO_H_

#include "sb_config.h"

namespace sb {
    template <class InputIterator, class Type>
    inline InputIterator find(InputIterator first, InputIterator last, const Type & value)
    {
        while (first != last && *first != value) {
            ++first;
        }
        return first;
    }

    template <class InputIterator, class Type, class Size>
    inline void count(InputIterator first, InputIterator last, const Type &value, Size& n)
    {
        for (; first != last; ++first) {
            if (*first == value) {
                ++n;
            }
        }
    }

    template <class ForwardIterator, class Type>
    inline void fill(ForwardIterator first, ForwardIterator last, const Type &value)
    {
        for (; first != last; first++) {
            *first = value;
        }
    }

    template <>
    inline void fill<unsigned char*, unsigned char>(unsigned char *first, unsigned char *last, const unsigned char &ch)
    {
        unsigned char tmp = ch;
        memset(first, tmp, last - first);
    }

    template <>
    inline void fill<signed char*, signed char>(signed char *first, signed char *last, const signed char &ch)
    {
        signed char tmp = ch;
        memset(first, static_cast<signed char>(tmp), last - first);
    }

    template <>
    inline void fill<char*, char>(char *first, char *last, const char& ch)
    {
        char tmp = ch;
        memset(first, static_cast<char>(tmp), last - first);
    }

    template<class ForwardIterator>
    inline ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
    {
        if (first == last) {
            return last;
        }

        ForwardIterator next = first;
        while (++next != last) {
            if (*first == *next)
                return first;
            first = next;
        }

        return last;
    }
}

#endif
