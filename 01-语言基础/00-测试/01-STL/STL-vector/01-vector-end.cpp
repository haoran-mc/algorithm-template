/*----------------------------------------------------------------
 *
 *   文件名称：vector-end.cpp
 *   创建日期：2021年04月28日 ---- 22时04分
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：在迭代器移动的时候向容器中添加元素，末尾的迭代器也会
 *          变化
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;
int main() {
    vector<int> vec;
    for (int i = 0; i < 5; ++i)
    vec.push_back(i);
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it % 2)
            vec.push_back(*it-1);
        printf("%d\n", *it);
    }
    return 0;
}
