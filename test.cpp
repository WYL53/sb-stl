#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

#include "sb_defalloc.h"
#include "sb_construct.h"
#include "sb_algo.h"

char* test(int v)
{
    switch (v) {
    case 1:
        return "windows";
    case 2:
        return "linux";
    case 3:
        return "freebsd";
    }
}

std::function<char* ()> get_os_func(int v) {
    switch (v) {
    case 1:
        return [] () -> char * {
          return "windows";
        };
    case 2:
        return [] () -> char *{
            return "linux";
        };
    case 3:
        return [] () -> char* {
            return "freebsd";
        };
    }
}

int main(void)
{
    /*
    auto func = get_os_func(1);

    std::cout << func() << std::endl;
    */


    char str[] = "HelloWorld";
    sb::fill(str, &str[strlen(str)-1], 'a');


    return 0;
}
