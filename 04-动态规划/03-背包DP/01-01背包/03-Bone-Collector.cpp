/*----------------------------------------------------------------
 *
 *   文件名称：01-Bone-Collector.cpp
 *   创建日期：2021年03月09日 ---- 15时34分
 *   题    目：hdu2602 Bone Collector
 *   算    法：01背包
 *   描    述：骨头收集者带着体积为V的背包去捡骨头，已知每个骨头的
 *      体积和价值，求能装进背包的最大价值
 *      第一行是测试数量，第二行是骨头数量和背包体积，
 *      第三行是每个骨头的价值，第四行是每个骨头的体积
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct Bone {
    int val;
    int vol;
} bone[maxn];
int N; //骨头数量
int V; //背包体积
// dp[i][j]: 前i件物品放在体积为j的背包中最大价值
int dp[maxn][maxn];

int solve() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= V; ++j) {
            if (bone[i].vol > j)  //第i个物品太大，装不下
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-bone[i].vol] + bone[i].val);
        }
    return dp[N][V];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &N, &V);
        //dp题还是从1开始吧，因为需要用到dp[i-1][j]
        for (int i = 1; i <= N; ++i)
            scanf("%d", &bone[i].val);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &bone[i].vol);
        printf("%d\n", solve());
    }
    return 0;
}
