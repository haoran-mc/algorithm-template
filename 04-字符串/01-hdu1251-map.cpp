/*----------------------------------------------------------------
 *
 *   文件名称：01-hdu1251-map.cpp
 *   创建日期：2021年03月19日 ---- 16时20分
 *   题    目：hdu1251 字典树
 *   算    法：map
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main() {
    string str;
    map<string, int> mp;
    while (cin >> str) {
        int len = str.length();
        if (!len)  //输入空行
            break;
        for (int i = len; i > 0; --i) {
            str[i] = '\0';
            mp[str]++;  //一个个的往前删就是前缀了
        }
    }
    while (cin >> str)
        printf("%d\n", mp[str]);
    return 0;
}
