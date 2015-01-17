#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

#include "sb_defalloc.h"
#include "sb_construct.h"
#include "sb_algo.h"

class test {
public:
    test(int i) {
        cout << i << endl;
    }
    test() {
        cout << "Hello world" << endl;
    }
    ~test() {
        cout << "shit" << endl;
    }
};

int main(void)
{
    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    auto it = v.begin();
    std::advance(it, 5);

    std::cout << *it << std::endl;

    return 0;
}
