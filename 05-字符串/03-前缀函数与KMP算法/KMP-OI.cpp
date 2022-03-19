#include <cstdio>
#include <cstring>
const int maxn = 1e6 + 5, maxm = 1e6 + 5;
#define bug printf("<-->\n");
#define NEXTLINE puts("");
int n, m;
char text[maxn], pattern[maxm];
int ne[maxm];
void prefix_table(char pattern[]) {
    int n = strlen(pattern);
    for (int i = 1; i < n; ++ i) {
        int j = ne[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = ne[j - 1];
        if (pattern[i] == pattern[j])
            j ++ ;
        ne[i] = j;
    }
}
