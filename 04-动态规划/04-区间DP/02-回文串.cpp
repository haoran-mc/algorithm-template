/*----------------------------------------------------------------
 *
 *   文件名称：02-回文串.cpp
 *   创建日期：2021年03月09日 ---- 17时37分
 *   题    目：poj3280 Cheapest Palindrome
 *   算    法：区间DP
 *   描    述：给定字符串s，长度为m，由n个小写字母构成，在s的任意位置
 *      增删字母，把它变为回文串，增删特定字母的花费不同，求最小花费
 *      3 4
 *      abcb
 *      b 350 700
 *      c 200 800
 *      a 1000 1100
 *
 *      900
 *
 ----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 2005;
int weight[30];
int dp[maxn][maxn];

int main() {
    int n, m;
    while (cin >> n >> m) {
        string str;
        cin >> str;
        for (int i = 0; i < n; ++i) {
            int x, y;
            char ch;
            cin >> ch >> x >> y; //读取每个字符的插入和删除花费
            weight[ch-'a'] = min(x, y); //取其中的最小值
        }
        for (int i = m-1; i >= 0; --i)      //i是子区间的起点
            for (int j = i+1; j < m; ++j) { //j是子区间的终点
                if (str[i] == str[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(dp[i+1][j] + weight[str[i]-'a'], dp[i][j-1] + weight[str[j]-'a']);
            }
        cout << dp[0][m-1] << endl;
    }
    return 0;
}
