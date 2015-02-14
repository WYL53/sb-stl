

#ifndef _SB_CONFIG_H_
#define _SB_CONFIG_H_

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>

#include "sb_exception.h"

void* operator new (size_t count)
{
    void *ptr = malloc(count);
    if (ptr == nullptr) {
        throw sb::bad_alloc();
    }

    return ptr;
}


void* operator new[](size_t count)
{
    void *ptr = malloc(count);
    if (ptr == nullptr) {
        throw sb::bad_alloc();
    }

    return ptr;
}

/*
void* operator new (size_t count, const std::nothrow_t& tag)
{

}

void* operator new[](size_t count, const std::nothrow_t& tag)
{

}
*/


#endif
