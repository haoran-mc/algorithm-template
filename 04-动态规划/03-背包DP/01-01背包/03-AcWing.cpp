/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：01.cpp
 *   创建日期：2021年03月29日 ---- 22时18分
 *   题    目：AcWing 0002 01 背包问题
 *   算    法：动态规划 01背包
 *   描    述：看过了骨头收集者的代码后，联系01背包
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int N; //N件物品
int V; //背包容量
struct Bone {
    int val;
    int vol;
} bone[maxn];
int dp[maxn][maxn];

int solve() {
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= V; ++j) {
            if (bone[i].vol > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-bone[i].vol] + bone[i].val);
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
