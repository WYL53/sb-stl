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

    auto i = sb::find(v.begin(), v.end(), 5);
    cout << *i << endl;
    return 0;
}