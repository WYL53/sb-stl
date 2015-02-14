

#ifndef _SB_MEMORY_H_
#define _SB_MEMORY_H_

#include "sb_config.h"

namespace sb {

    /* Allocators */
    template <typename Type>
    class allocator {
    public:
        typedef Type            value_type;
        typedef Type*           pointer;
        typedef const Type*     const_pointer;
        typedef Type&           reference;
        typedef const Type&     const_reference;
        typedef size_t          size_type;
        typedef ptrdiff_t       difference_type;

        template <typename Other>
        class rebind {
        public:
            typedef allocator<Other> other;
        };

        pointer address(reference value)
        {
            return &value;
        }

        const_pointer address(const_reference value) const
        {
            return static_cast<const_pointer>(&value);
        }

        size_type max_size() const
        {
            return size_t(-1) / sizeof(Type);
        }

        pointer allocate(size_type n, const void *hint = 0)
        {
            (void) hint;
            return n ? static_cast<Type*>(::operator new(n * sizeof(Type))) : nullptr;
        }

        void deallocate(pointer p, size_type n)
        {
            (void) n;
            ::operator delete(p);
        }

        void construct(pointer p, const Type& value) const
        {
            new(p) Type(value);
        }

        void destory(pointer p) const
        {
            p->~Type();
        }

        template <typename OtherType>
        void destory(OtherType *p) const
        {
            p->~OtherType();
        }
    };

    template <>
    class allocator<void>
    {
    public:
        typedef void        value_type;
        typedef void*       pointer;
        typedef const void* const_pointer;
        typedef ptrdiff_t   difference_type;
        typedef size_t      size_type;

        template <typename Other>
        class rebind {
        public:
            typedef allocator<Other> other;
        };
    };

    template <typename Type>
    inline bool operator == (const allocator<Type> &lhs, const allocator<Type> &rhs)
    {
        (void) lhs;
        (void) rhs;
        return true;
    }

    template <typename Type>
    inline bool operator != (const allocator<Type> &lhs, const allocator<Type> &rhs)
    {
        (void) lhs;
        (void) rhs;
        return false;
    }

    template <typename LType, typename RType>
    inline bool operator == (const allocator<LType> &lhs, const allocator<RType> &rhs)
    {
        return true;
    }

    template <typename LType, typename RType>
    inline bool operator != (const allocator<LType> &lhs, const allocator<RType> &rhs)
    {
        return false;
    }

    template <typename Type>
    class auto_ptr_ref {
    public:
        auto_ptr_ref(Type *ptr) : m_ptr(ptr)
        {
        }
        Type* m_ptr;
    };

    /* Smart pointers categories */
    template <typename Type>
    class auto_ptr {
    public:
        typedef Type element_type;

        explicit auto_ptr(Type *ptr = 0) : m_ptr(ptr)
        {
        }

        auto_ptr(auto_ptr &rhs) : m_ptr(rhs.release())
        {
        }

        template <typename OtherType>
        auto_ptr(auto_ptr<OtherType> &rhs) : m_ptr(rhs.release())
        {
        }

        template <typename OtherType>
        auto_ptr(const auto_ptr_ref<OtherType> &m) : m_ptr(m.m_ptr)
        {
        }

        ~auto_ptr()
        {
            if (m_ptr) {
                delete m_ptr;
            }
        }

        Type* release(void)
        {
            Type *tmp = m_ptr;
            m_ptr = 0;
            return tmp;
        }

        void reset(Type *ptr = 0)
        {
            if (ptr != m_ptr) {
                if (m_ptr) {
                    delete m_ptr;
                }
                m_ptr = ptr;
            }
        }

        Type* get() const
        {
            return m_ptr;
        }

        Type& operator *() const
        {
            return *m_ptr;
        }

        Type* operator ->() const
        {
            return m_ptr;
        }

        auto_ptr& operator= (auto_ptr &rhs)
        {
            if (rhs.get() != this->get())
            {
                if (m_ptr) {
                    delete m_ptr;
                }
                m_ptr = rhs.release();
            }
            return *this;
        }

        auto_ptr& operator= (auto_ptr_ref<Type> rhs)
        {
            if (rhs.m_ptr != this->get())
            {
                if (m_ptr) {
                    delete m_ptr;
                }
                m_ptr = rhs.m_ptr;
            }
            return *this;
        }

        template <typename OtherType>
        auto_ptr& operator= (auto_ptr<OtherType> &rhs)
        {
            if (rhs.get() != this->get())
            {
                if (m_ptr) {
                    delete m_ptr;
                }
                m_ptr = rhs.release();
            }
            return *this;
        }

    private:
        Type*  m_ptr;
    };
};

#endif
