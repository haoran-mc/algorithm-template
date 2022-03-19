#include <cstdio>
#include <cstring>
const int maxn = 1e4 + 5, maxm = 1e6 + 5, maxs = 55;
int n;
int tr[maxn * maxs][26], cnt[maxn * maxs], idx;
char str[maxm];
int q[maxn * maxs], ne[maxn * maxs];
#define NEXTLINE puts("");
#define bug puts("<-->");
#define p(x) printf("-- %d\n", (x));
void insert() {
    int p = 0;
    for (int i = 0; str[i]; ++ i) {
        int u = str[i] - 'a';
        if (!tr[p][u])
            tr[p][u] = ++ idx;
        p = tr[p][u];
    }
    cnt[p] ++ ;
}
void build() {
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; ++ i)
        if (tr[0][i]) {
            ne[tr[0][i]] = 0;
            q[ ++ tt] = tr[0][i];
        }
    while (hh <= tt) {
        int t = q[hh ++ ]; // 父结点
        for (int i = 0; i < 26; ++ i) {
            int c = tr[t][i]; // 当前结点
            if (!c) { // 当前结点不存在
                tr[t][i] = tr[ne[t]][i];
            }
            else {
                ne[c] = tr[ne[t]][i];
                q[ ++ tt] = c;
            }
        }
    }
}
int ACautomaton() {
    int res = 0;
    for (int i = 0, j = 0; str[i]; ++ i) {
        int c = str[i] - 'a';
        j = tr[j][c]; // j 是父结点
        int u = j;
        while (u) {
            res += cnt[u];
            cnt[u] = 0;
            u = ne[u];
        }
    }
    return res;
}
int main() {
    int t; scanf("%d", &t);
    while (t -- ) {
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);
        memset(ne, 0, sizeof ne);
        idx = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) {
            scanf("%s", str);
            insert();
        }
        build();
        scanf("%s", str);
        int res = ACautomaton();
        printf("%d\n", res);
    }
    return 0;
}
