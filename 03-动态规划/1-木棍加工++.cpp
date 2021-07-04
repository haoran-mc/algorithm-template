#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e4+5;
struct node {
    int x;
    int y;
} stick[maxn];
int dp[maxn];

bool cmp(node a,node b) {
    return (a.x > b.x || (a.x == b.x && a.y > b.y)) ? true : false;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &stick[i].x, &stick[i].y);
    sort(stick, stick+n, cmp);
    fill(dp, dp+n, 1);
    int res = 1;
    for (int i = 0; i < n; ++i)
       for (int j = i-1; j >= 0; --j)
          if (stick[i].y > stick[j].y)
              dp[i] = max(dp[i], dp[j]+1),
              res = max(res, dp[i]);
    printf("%d\n", res);
    return 0;
}
