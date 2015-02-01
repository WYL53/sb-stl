
#include <iostream>
#include <vector>

#include "sb_iterator.h"

int main(void)
{
    std::vector<int> arr = {1,2,3,4,5};

    std::cout << sb::distance(arr.begin(), arr.end()) << std::endl;

    return 0;
}