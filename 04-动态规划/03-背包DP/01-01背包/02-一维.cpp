/*----------------------------------------------------------------
 *
 *   文件名称：02-一维.cpp
 *   创建日期：2021年03月30日 ---- 16时14分
 *   题    目：AcWing 0003 01背包
 *   算    法：动态规划
 *   描    述：使用一维数组
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
int dp[maxn];

int solve() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; ++i)
        for (int j = V; j >= bone[i].vol; --j)
            /*
             * dp[j-bone[i].vol]此处体积一定是上个物品的最优解
             * 因为还没有dp[j-bone[i].vol] = max(dp[j-bone[i].vol], dp[j-2*bone[i].vol]+2*bone[i].val)
             * 如果j从小到大循环的话，dp[j-bone[i].vol]中是从dp[j-2*bone[i].vol]转移来的
             * 表示在背包体积为j时，可以放入的当前物品数量不定，可以无穷件，只要不超过背包容积
             */
            dp[j] = max(dp[j], dp[j-bone[i].vol] + bone[i].val);
    return dp[V];
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
