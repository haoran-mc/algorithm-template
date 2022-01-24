/*----------------------------------------------------------------
 *
 *   文件名称：02-一维.cpp
 *   创建日期：2021年03月30日 ---- 16时20分
 *   题    目：AcWing 0003 完全背包
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
int dp[maxn];

int solve() {
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= V-bone[i].vol; ++j)
            /*
             * dp[j] = max(dp[j], dp[j-bone[i].vol] + bone[i].val);
             * 为什么不使用上面一句呢？
             * 因为不是从0开始的，dp[j-bone[i].vol]的开始位置不能确定
             */
            dp[j+bone[i].vol] = max(dp[j+bone[i].vol], dp[j]+bone[i].val);
    return dp[V];
}

int main() {
    scanf("%d %d", &N, &V);
    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &bone[i].vol, &bone[i].val);
    printf("%d\n", solve());
    return 0;
}
