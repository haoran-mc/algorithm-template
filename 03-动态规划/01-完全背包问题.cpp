/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年03月30日 ---- 15时30分
 *   题    目：AcWing 0003 完全背包问题
 *   算    法：动态规划
 *   描    述：与01背包问题代码相差无几
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct Bone {
    int val;
    int vol;
} bone[maxn];
int N, V;
int dp[maxn][maxn];

int solve() {
    //这里必须是从1开始，因为从0开始会dp[i-1][j]出界
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= V; ++j) {
            if (bone[i].vol > j)
                dp[i][j] =  dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-bone[i].vol] + bone[i].val);
        }
    return dp[N][V];
}

int main() {
    scanf("%d %d", &N, &V);
    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &bone[i].vol, &bone[i].val);
    printf("%d\n", solve());
    return 0;
}
