#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main() {
    cout << "Illustrating the generic unique algorithm." << endl;
    const int N = 11;
    int array1[N] = {1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8};
    vector<int> vec;
    for (int i = 0; i < N; ++i)
        vec.push_back(array1[i]);

    vector<int>::iterator new_end;
    /*"删除"相邻的重复元素*/
    new_end = unique(vec.begin(), vec.end());
    /*断言vec.size() == N，如果不成立，打印错误信息并返回*/
    assert(vec.size() == N);

    /*删除(真正的删除)重复的元素*/
    vec.erase(new_end, vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
