
#ifndef _SB_VECTOR_H_
#define _SB_VECTOR_H_

#include "sb_config.h"
#include "sb_memory.h"

namespace sb {

    template <typename Type, typename Allocator = sb::allocator<Type>>
    class vector {
    public:
        typedef Type                value_type;

        typedef value_type*         pointer;
        typedef const value_type*   const_pointer;
        typedef value_type&         reference;
        typedef const value_type&   const_reference;

        typedef size_t              size_type;
        typedef ptrdiff_t           difference_type;

        typedef value_type*         iterator;
        typedef const value_type*   const_iterator;

        typedef Allocator           allocator_type;

    public:
        vector(): m_start(nullptr), m_end(nullptr), m_finish(nullptr)
        {

        }

        void push_back(const_reference value)
        {
            if (m_end != m_finish) {
                m_alloc.construct(m_finish, value);
                m_finish++;

            } else {
                __insert__(end(), value);
            }
        }

        void pop_back(void)
        {
            m_finish--;
            m_alloc.destory(m_finish);
        }

        reference front(void)
        {
            return *begin();
        }

        reference back(void)
        {
            return *(end() - 1);
        }

        iterator begin(void) const
        {
            return m_start;
        }

        iterator end(void) const
        {
            return m_finish;
        }

        size_type size(void) const
        {
            return size_type(m_finish - m_start);
        }

        size_type capacity(void) const
        {
            return size_type(m_end - m_start);
        }

        bool empty(void) const
        {
            return (begin() == end());
        }

    private:
        void __insert__(iterator position, const_reference value)
        {
            if (m_end != m_finish) {

            } else {

            }
        }

    private:
        iterator        m_start;
        iterator        m_end;
        iterator        m_finish;
        allocator_type  m_alloc;
    };

};

#endif
