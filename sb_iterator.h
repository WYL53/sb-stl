

#ifndef _SB_ITERATOR_H_
#define _SB_ITERATOR_H_

#include "sb_config.h"

namespace sb {
    class input_iterator_tag {};
    class output_iterator_tag {};
    class forward_iterator_tag : public input_iterator_tag{};
    class bidirectional_iterator_tag : public forward_iterator_tag {};
    class random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <typename Type, typename Distance>
    class input_iterator {
    public:
        typedef input_iterator_tag  iterator_category;
        typedef Type                value_type;
        typedef Distance            difference_type;
        typedef Type*               pointer;
        typedef Type&               reference;
    };

    class output_iterator {
    public:
        typedef output_iterator_tag iterator_category;
        typedef void                value_type;
        typedef void                difference_type;
        typedef void                pointer;
        typedef void                reference;
    };

    template <typename Type, typename Distance>
    class forward_iterator {
    public:
        typedef forward_iterator_tag    iterator_category;
        typedef Type                    value_type;
        typedef Distance                difference_type;
        typedef Type*                   pointer;
        typedef Type&                   reference;
    };

    template <typename Type, typename Distance>
    class bidirectional_iterator {
    public:
        typedef bidirectional_iterator_tag  iterator_category;
        typedef Type                        value_type;
        typedef Distance                    difference_type;
        typedef Type*                       pointer;
        typedef Type&                       reference;
    };

    template <typename Type, typename Distance>
    class random_access_iterator {
    public:
        typedef random_access_iterator_tag  iterator_category;
        typedef Type                        value_type;
        typedef Distance                    difference_type;
        typedef Type*                       pointer;
        typedef Type&                       reference;
    };
    
    template <typename Category,
              typename Type,
              typename Distance = ptrdiff_t, 
              typename Pointer = Type*,
              typename Reference = Type&>
    class iterator {
    public:
        typedef Category    iterator_category;
        typedef Type        value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

    template <typename Iterator>
    class iterator_traits {
    public:
        typedef typename Iterator::iterator_category    iterator_category;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
    };

    template <typename Type>
    class iterator_traits<Type *> {
    public:
        typedef random_access_iterator_tag  iterator_category;
        typedef Type                        value_type;
        typedef ptrdiff_t                   difference_type;
        typedef Type*                       pointer;
        typedef Type&                       reference;
    };

    template <typename Type>
    class iterator_traits<const Type *> {
    public:
        typedef random_access_iterator_tag  iterator_category;
        typedef Type                        value_type;
        typedef ptrdiff_t                   difference_type;
        typedef const Type*                 pointer;
        typedef const Type&                 reference;
    };

    template <typename InputIterator>
    inline typename iterator_traits<InputIterator>::difference_type __distance__(InputIterator first, InputIterator last, input_iterator_tag)
    {
        typename iterator_traits<InputIterator>::difference_type n = 0;
        while (first != last) {
            first++, n++;
        }
        return 0;
    }

    template <typename RandomAccessIterator>
    inline typename iterator_traits<RandomAccessIterator>::difference_type __distance__( RandomAccessIterator first,  RandomAccessIterator last, random_access_iterator_tag)
    {
        return last - first;
    }

    template <typename InputIterator>
    inline typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
    {
        return __distance__(first, last, typename iterator_traits<InputIterator>::iterator_category());
    }
};


#endif
