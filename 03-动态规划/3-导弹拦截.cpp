#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 25;
int bomb[maxn];
int dp[maxn];
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &bomb[i]);
    fill(dp, dp+n, 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (bomb[i] <= bomb[j])
                dp[i] = max(dp[i], dp[j]+1);
                // 表示当前导弹发射后最大能拦截的导弹数
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = max(res, dp[i]);
    printf("%d\n", res);
    return 0;
}

