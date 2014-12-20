
#ifndef _SB_ALGO_H_
#define _SB_ALGO_H_

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
}

#endif
