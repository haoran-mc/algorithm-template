#include <cstdio>
#include <cstring>
int n, sum;
int arr[n];
long long dp[sum+1]; //dp[i]表示和为i时的方案数

int main() {
    scanf("%d %d", &n, &sum);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= 0; --j)
            if (arr[i] + j <= sum)
                dp[arr[i]+j] += dp[j];

        if (arr[i] >= 0 && arr[i] <= sum)
            dp[arr[i]]++;
    }
    printf("%lld\n", dp[sum]);
    return 0;
}
