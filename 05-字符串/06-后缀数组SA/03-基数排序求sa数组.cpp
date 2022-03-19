#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 200005;
char text[maxn];
int sa[maxn];
int rk[maxn];
int cnt[maxn];
int t1[maxn];
int t2[maxn];
int height[maxn];
int n;

void calc_sa() {
    int m = 127;
    int *x = t1;
    int *y = t2;
    for (int i = 0; i < m; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) cnt[x[i] = text[i]]++;
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i-1];
    for (int i = n-1; i >= 0; --i) sa[--cnt[x[i]]] = i;
    for (int k = 1; k <= n; k *= 2) {
        int p = 0;
        for (int i = n-k; i < n; ++i) y[p++] = i;
        for (int i = 0; i < n; ++i)
            if (sa[i] >= k)
                y[p++] = sa[i] - k;
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) cnt[x[y[i]]]++;
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; --i) sa[--cnt[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            x[sa[i]] =
                y[sa[i-1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i] + k] ? p-1 : p++;
        if (p >= n) break;
        m = p;
    }
}

int main() {
    while (scanf("%s", text) != EOF) {
        n = strlen(text);
        calc_sa();
        for (int i = 0; i < n; ++i)
            printf("%d ", sa[i]);
        printf("\n");
    }
    return 0;
}
