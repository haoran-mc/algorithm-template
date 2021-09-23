#include <cstdio>
const int maxn=110;
#define _max(a, b) (a > b ? a : b)
int N, V;
int vo[maxn][maxn], va[maxn][maxn], s[maxn];   //v为体积，w为价值，s代表第i组物品的个数
int dp[maxn][maxn];  //只从前i组物品中选，当前体积小于等于j的最大值

int main() {
    scanf("%d %d", &N, &V);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &s[i]);
        for(int j = 0; j < s[i]; ++j)
            scanf("%d %d", &vo[i][j], &va[i][j]);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            dp[i][j] = dp[i-1][j]; //不选
            for (int k = 0; k < s[i]; ++k)
                if (j >= vo[i][k])
                    dp[i][j] = _max(dp[i][j], dp[i-1][j-vo[i][k]] + va[i][k]);
        }
    }
    printf("%d\n", dp[N][V]);
}
