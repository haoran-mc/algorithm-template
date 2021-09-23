/*----------------------------------------------------------------
 *
 *   文件名称：01-最长公共子序列.cpp
 *   创建日期：2021年03月09日 ---- 15时48分
 *   题    目：hdu1159 Common Subsequence
 *   算    法：动态规划
 *   描    述：求两个序列的最长公共子序列，注意子序列不是子串
 *
 ----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
string str1, str2;
int LCS() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= str1.length(); ++i)
        for (int j = 1; j <= str2.length(); ++j) {
            if (str1[i-1] == str2[j-1])
                str1[i-1] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    return dp[str1.length()][str2.length()];
}

int main() {
    while (cin >> str1 >> str2)
        cout << LCS() << endl;
    return 0;
}
