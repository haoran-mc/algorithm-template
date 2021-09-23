#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 25;
int bomb[maxn];
int dp[maxn];
int link[maxn];
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &bomb[i]);
    ++n;
    bomb[n-1] = -1;
    memset(link, -1, sizeof(link));
    dp[n-1] = 1;
    int maxi;
    int idx;
    int start = - 1;
    int res = 1;
    for (int i = n-2; i >= 0; --i) {
        maxi = dp[i];
        idx  = i;
        for (int j = i+1; j < n; ++j)
            if (bomb[j] <= bomb[i] && dp[j] > maxi) {
                maxi = dp[j];
                idx  = j;
            }
        dp[i] = ++maxi;
        link[i]  = idx;
        if (dp[i] > res) {
            res = dp[i];
            start = i;
        }
    }
    printf("%d\n", res);
    for (int i = start; i != -1; i = link[i])
        printf("%d ", bomb[i]);
    return 0;
}
