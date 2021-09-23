/*----------------------------------------------------------------
 *
 *   文件名称：01-多重背包.cpp
 *   创建日期：2021年04月10日 ---- 10时39分
 *   题    目：AcWing 0004 多重背包
 *   算    法：多重背包
 *   描    述：每种物品选ai次转化为有ai个物品选1次，即01背包
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int N, V; //骨头数量，背包体积
int dp[maxn];

int main() {
    scanf("%d %d", &N, &V);
    for (int i = 0; i < N; ++i) {
        int vo, va, a;
        scanf("%d %d %d", &vo, &va, &a);
        for (int j = V; j > 0; --j)
            for (int k = 1; k <= a && k*vo <= j; ++k)
                dp[j] = max(dp[j], dp[j-k*vo] + k*va);
    }
    printf("%d\n", dp[V]);
    return 0;
}
