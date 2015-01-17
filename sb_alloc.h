

#ifndef _SB_ALLOC_H_
#define _SB_ALLOC_H_

#include "sb_types.h"

namespace sb {

    template <class Type> 
    class allocator {
        typedef Type            value_type;
        typedef Type*           pointer; 
        typedef const Type*     const_pointer;
        typedef Type&           reference;
        typedef const Type&     const_reference;
        typedef size_t          size_type;
        typedef ptrdiff_t       difference_type;
        
    };
};

#endif