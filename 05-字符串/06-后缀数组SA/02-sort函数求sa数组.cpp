#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 200005;
char text[maxn];
int sa[maxn];
int rk[maxn];
int tmp[maxn + 1];
int n, k;

bool comp_sa(int i, int j) {
    if (rk[i] != rk[j])
        return rk[i] < rk[j];
    else {
        int ri = i + k <= n ? rk[i + k] : -1;
        int rj = j + k <= n ? rk[j + k] : -1;
        return ri < rj;
    }
}

void calc_sa() {
    for (int i = 0; i <= n; ++i) {
        rk[i] = text[i];
        sa[i] = i;
    }
    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa+n, comp_sa);
        tmp[sa[0]]= 0;
        for (int i = 0; i < n; ++i)
            tmp[sa[i+1]] = tmp[sa[i]] + (comp_sa(sa[i], sa[i+1]) ? 1 : 0);
        for (int i = 0; i < n; ++i)
            rk[i] = tmp[i];
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
