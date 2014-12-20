
#ifndef _SB_DEFALLOC_H_
#define _SB_DEFALLOC_H

#include "sb_config.h"
#include "sb_types.h"
#include <new>

namespace sb
{

    template <class Type>
    inline Type* allocate(ptrdiff_t size, Type*) 
    {
        std::set_new_handler(0);

        Type* resource = (Type*)::operator new((size_t)(size * sizeof(Type)));

        return resource;
    }

    template <class Type>
    class allocator_base 
    {
    public:
        typedef Type        value_type;
    };

    template <class Type>
    class allocator_base<const Type> 
    {
    public:
        typedef Type        value_type;
    };

    template <class Type>
    class allocator : 
        public allocator_base<Type> 
    {
    public:
        typedef Type*       pointer;
        typedef const Type* const_pointer;
        typedef Type&       reference;
        typedef const Type& const_reference;
        typedef size_t      size_type;
        typedef ptrdiff_t   difference_type;


    };

}
#endif
