
#ifndef _SB_CONSTRUCT_H_
#define _SB_CONSTRUCT_H_

namespace sb {

    template <class Type>
    inline void construct(Type *pointer)
    {
        new (pointer)Type();
    }

    template <class Type, class Value>
    inline void construct(Type *pointer, const Value& value) 
    {
        new (pointer) Type(value);
    }

    template <class Type>
    inline void destroy(Type *pointer)
    {
        pointer->~Type();
    }

    inline void destroy(char*, char*)
    {

    }

    inline void destroy(wchar_t*, wchar_t*)
    {

    }
}

#endif
