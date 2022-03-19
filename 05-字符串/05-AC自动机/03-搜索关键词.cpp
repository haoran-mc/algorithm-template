/*----------------------------------------------------------------
 * 文件名称：搜索关键词.cpp
 * 创建日期：2021年11月03日 星期三 22时06分59秒 
 * 题 目：hdu 2222 AcWing 1282 搜索关键词 
 * 算 法：AC自动机 
 * 描 述：给定 n 个长度不超过 50 的由小写英文字母组成的单词，
 * 以及一篇长为 m 的文章，问有多少个单词在文章中出现了。
 * 1 1 she he say shr her text
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
const int maxn = 1e4 + 5, maxm = 1e6 + 5, maxs = 55;
int n;
int tr[maxn * maxs][26], cnt[maxn * maxs], idx;
char str[maxm];
int q[maxn * maxs], ne[maxn * maxs]; // Fail[]
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
/*
 * +
 * s / \ h
 * / \
 * ne = 0 1 4 ne = 0
 * h / \ e
 * / \
 * ne = 4 2 5 ne = 0
 * e /
 * /
 * ne = 5 3
 *
 * 当 t = 2 时，也就是停在sh位置，会遍历它的所有后继结点
 * 这时找到 c = tr[t]['e' - 'a'] = tr[2][4] = 3
 *
 * j = ne[t] = ne[2] = 4，j 是当前结点 3 的 next，就是因为 'e'
 * 的上面的子串的最长后继已经找到了，没必要从头开始找
 *
 * 接下来就是判断是否有 tr[j][i]，这里的 i 就是 'e' - 'a'，也就代表了 'e'
 *
 * 发现有 tr[j][i] = tr[4][4] = 5，那么 j = tr[j][i], ne[c] = ne[3] = j = 5
 * 没发现的话，j 最后会变成 0，ne[c] = 0，指向根结点
 */
void build() {
    int hh = 0, tt = -1; // 宽度优先搜索
    for (int i = 0; i < 26; ++ i)
        if (tr[0][i]) {
            ne[tr[0][i]] = 0; // 因为初始ne就是0，这句没必要
            q[ ++ tt] = tr[0][i];
        }
    while (hh <= tt) {
        int t = q[hh ++ ];
        for (int i = 0; i < 26; ++ i) {
            int c = tr[t][i];
            if (!c)
                continue;
            int j = ne[t]; // 当前结点的上一个结点，的next
            // 当前结点代表的字母是i
            while (j && !tr[j][i]) // 也就是next下面是否有同样的i
                j = ne[j];
            if (tr[j][i])
                j = tr[j][i];
            ne[c] = j;
            q[ ++ tt] = c;
        }
    }
}
int ACautomaton() {
    int res = 0;
    for (int i = 0, j = 0; str[i]; ++ i) {
        int c = str[i] - 'a'; // 当前字符
        while (j && !tr[j][c])
            j = ne[j];
        if (tr[j][c])
            j = tr[j][c];
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
            insert(); // 建立 trie
        }
        build(); // 建立 next
        scanf("%s", str);
        int res = ACautomaton();
        printf("%d\n", res);
    }
    return 0;
}
