#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int x[maxn], y[maxn];

//下标从1开始
ll solve(int I[], int n) {
    ll avg = 0;
    for (int i = 1; i <= n; ++i)
        avg += I[i];
    avg /= n;

    int x[maxn];
    x[1] = 0;
    for (int i = 2; i <= n; ++i)
        x[i] = x[i-1] + avg - I[i];

    sort(x + 1, x + n + 1);
    ll x1 = x[n / 2];  //中位数
    ll res = 0;
    for (int i = 1; i <= n; ++i)
        res += abs(x[i] - x1);
    return res;
}

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    ll sumx = 0, sumy = 0;
    while (t--) {
        int ix, iy;
        scanf("%d %d", &ix, &iy);
        x[ix]++, y[iy]++;
        sumx++, sumy++;
    }
    if (sumx % n && !(sumy % m))
        printf("column %lld\n", solve(y, m));
    else if (!(sumx % n) && sumy % m)
        printf("row %lld\n", solve(x, n));
    else if (!(sumx % n) && !(sumy % m))
        printf("both %lld\n", solve(x, n) + solve(y, m));
    else
        printf("impossible\n");
    return 0;
}
