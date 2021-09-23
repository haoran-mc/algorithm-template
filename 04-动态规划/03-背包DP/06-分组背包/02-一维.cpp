#include <cstdio>
const int maxn = 110;
#define _max(a, b) (a > b ? a : b)
int N, V;
int vo[maxn][maxn], va[maxn][maxn], s[maxn];
int dp[maxn];

int main() {
    scanf("%d %d", &N, &V);
    for (int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
        for(int j = 0; j < s[i]; j++)
            scanf("%d %d", &vo[i][j], &va[i][j]);
    }
    for (int i = 0; i < N; ++i)
        for (int j = V; j >= 0; --j)
            for (int k = 0; k < s[i]; k++)     //for(int k=s[i];k>=1;k--)也可以
                if (j >= vo[i][k])
                    dp[j] = _max(dp[j], dp[j-vo[i][k]] + va[i][k]);
    printf("%d\n", dp[V]);
}
