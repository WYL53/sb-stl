
#ifndef _SB_EXCEPTION_H_
#define _SB_EXCEPTION_H_
#include "sb_config.h"

namespace sb {

    /* Exception base */

    class exception {
    public:
        exception() {}
        virtual ~exception() {}
        virtual const char *what() const { return ""; }
    };

    /* General exceptions */

    class bad_alloc : public exception {
    public:
        virtual ~bad_alloc() {}
        virtual const char *what() const {
            return "sb::bad_alloc";
        }
    };

    class bad_array_new_length : public bad_alloc {
    public:
        virtual ~bad_array_new_length() {}
        virtual const char *what() const {
             return "sb::bad_array_new_length";
        }
    };

    class bad_array_length : public bad_alloc {
    public:
        virtual ~bad_array_length() {}
        virtual const char *what() const {
            return "sb::bad_array_length";
        }
    };

    class bad_cast : public exception {
    public:
        virtual ~bad_cast(){}
        virtual const char *what() const {
            return "sb::bad_cast";
        }
    };

    class bad_typeid : public exception {
    public:
        virtual ~bad_typeid() {}
        virtual const char *what() const {
            return "sb::bad_typeid";
        }
    };

    class bad_weak_ptr : public exception {
    public:
        virtual ~bad_weak_ptr() {}
        virtual const char *what() const {
            return "sb::bad_weak_ptr";
        }
    };

    class bad_function_call : public exception {
    public:
        virtual~ bad_function_call() {}
        virtual const char *what() const {
            return "sb::bad_function_call";
        }
    };

    /* Logic error */
};

#endif
