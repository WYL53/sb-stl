
#ifndef _SB_LIST_H_
#define _SB_LIST_H_

#include "sb_config.h"
#include "sb_memory.h"
#include "sb_iterator.h"

namespace sb {

    template <typename Type>
    class list_node {
    public:
        typedef void* void_pointer;
        Type         value;
        void_pointer prev;
        void_pointer next;
    };

    template <typename Type, typename Ref, typename Ptr>
    class list_iterator {
    private:
        typedef list_iterator<Type, Ref, Ptr>   self;
    public:
        typedef bidirectional_iterator_tag  iterator_category;
        typedef Type                        value_type;
        typedef Type&                       reference;
        typedef Type*                       pointer;
        typedef ptrdiff_t                   difference_type;

        self& operator ++(void)
        {

        }

        self operator++(int)
        {

        }

    protected:

    };

    template <typename Type, typename Allocator = allocator<Type>>
    class list {
    public:
        typedef Type                                            value_type;

        typedef Allocator                                       allocator_type;

        typedef list_iterator<Type, Type&,  Type*>              iterator;
        typedef list_iterator<Type, const Type&, const Type*>   const_iterator;
    };



};

#endif
