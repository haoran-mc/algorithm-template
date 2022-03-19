// 字符串下标从1开始 
#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5, maxm = 1e6 + 5;
int ne[maxn];
char pattern[maxn], text[maxm];
#define NEXTLINE puts("");
void get_perfix_table(char pattern[]) {
    int n = strlen(pattern + 1);
    for (int i = 2, j = 0; i <= n; ++ i) {
        while (j && pattern[i] != pattern[j + 1])
            j = ne[j];
        if (pattern[i] == pattern[j + 1])
            j ++ ;
        ne[i] = j;
    }
}
void kmp_search(char text[], char pattern[]) {
    int m = strlen(text + 1),
        n = strlen(pattern + 1);
    for (int i = 1, j = 0; i <= m; ++ i) {
        while (j && text[i] != pattern[j + 1])
            j = ne[j];
        if (text[i] == pattern[j + 1])
            j ++ ;
        if (j == n) {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
}
int main() {
    int n, m;
    scanf("%d %s", &n, pattern + 1);
    scanf("%d %s", &m, text + 1);
    get_perfix_table(pattern);
    /*
     * printf("%s\n", pattern + 1);
     * for (int i = 1; i <= n; ++ i)
     * printf("%d", ne[i]);
     * NEXTLINE;
     */
    kmp_search(text, pattern);
    return 0;
}
/*
   ABAABA
   ABAABAABAABAABAAABBCCABABCABAABAA
   | | |
   1 9 22
   ABABCABAA
   ABABABCABAABABAABAB
 */
