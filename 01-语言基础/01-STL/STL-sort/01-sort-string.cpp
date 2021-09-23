/*----------------------------------------------------------------
 *
 *   文件名称：sort-string.cpp
 *   创建日期：2020年08月26日 ---- 12时08分
 *   描    述：sort string
 *
----------------------------------------------------------------*/


#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string str1, string str2) {
    return str1.length() > str2.length();
}
int main() {
    string str[3] = {"A", "BB", "CCC"};
    sort (str, str + 3);
    for (int i = 0; i < 3; i++)
        cout << str[i] << endl;

    sort (str, str + 3, cmp);
    for (int i = 0; i < 3; i++)
        cout << str[i] << endl;
    return 0;
}

