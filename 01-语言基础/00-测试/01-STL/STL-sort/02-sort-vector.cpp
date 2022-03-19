/*----------------------------------------------------------------
 *
 *   文件名称：sort-vector.cpp
 *   创建日期：2020年08月26日 ---- 11时08分
 *   描    述：sort对vector的排序是否要求有比较函数
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int A, int B) {
    return A > B;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(0);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < 4; i++)
        printf("%d\n", vec[i]);
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < 4; i++)
        printf("%d\n", vec[i]);
    return 0;
}

