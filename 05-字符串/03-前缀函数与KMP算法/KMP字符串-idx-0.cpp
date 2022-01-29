// 字符串下标从0开始 
#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5, maxm = 1e6 + 5;
int n, m;
char text[maxm], pattern[maxn];
int ne[maxn];
#define NEXTLINE puts("");
int main() {
    scanf("%d %s", &n, pattern);
    scanf("%d %s", &m, text);
    ne[0] = -1;
    for (int i = 1, j = -1; i < n; i ++ ) {
        while (j >= 0 && pattern[j + 1] != pattern[i])
            j = ne[j];
        if (pattern[j + 1] == pattern[i])
            j ++ ;
        ne[i] = j;
    }
    for (int i = 0; i <= n; ++ i)
        printf("%d ", ne[i]);
    NEXTLINE;
    for (int i = 0, j = -1; i < m; i ++ ) {
        while (j != -1 && text[i] != pattern[j + 1])
            j = ne[j];
        if (text[i] == pattern[j + 1])
            j ++ ;
        if (j == n - 1) {
            printf("%d ", i - j);
            j = ne[j];
        }
    }
    return 0;
}
