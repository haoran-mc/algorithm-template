#include <cstdio>
#define NEXTLINE puts("");
const int maxn = 1e5 + 5;
int sequ[maxn];
int diff[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &sequ[i]);
        diff[i] = sequ[i] - sequ[i-1];
    }
    while (m--) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        diff[l] += c;
        diff[r+1] -= c;
    }
    for (int i = 1; i <= n; ++i)
        diff[i] += diff[i-1];
    for (int i = 1; i <= n; ++i)
        printf("%d ", diff[i]);
    NEXTLINE;
    return 0;
}
