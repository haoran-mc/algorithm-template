/*----------------------------------------------------------------
 *
 *   文件名称：01-The-Triangle.cpp
 *   创建日期：2021年03月09日 ---- 16时04分
 *   题    目：poj1163 The Triangle
 *   算    法：记忆化搜索
 *   描    述：自下往上的方法更好，但是这里使用递归+记忆化
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 155;
int n;  //三角形的高度
int Tri[maxn][maxn];  //存储三角形塔
int dp[maxn][maxn];
int dfs(int i, int j) {
    if (i == n)
        return Tri[i][j];
    if (dp[i][j] >= 0)
        return dp[i][j];
    return dp[i][j] = max(dfs(i+1, j), dfs(i+1, j+1)) + Tri[i][j];
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &Tri[i][j]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", dfs(0, 0));
    return 0;
}
