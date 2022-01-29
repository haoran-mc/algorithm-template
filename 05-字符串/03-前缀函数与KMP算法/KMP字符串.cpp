/*----------------------------------------------------------------
 * 文件名称：KMP字符串.cpp
 * 创建日期：2021年08月06日 星期五 21时23分58秒 
 * 题 目：AcWing 0831 KMP字符串 
 * 算 法：KMP
 * 描 述：ne[0] = 0，没有改变ne的下标 
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
// maxn 是文本串的长度，maxm 是模式串的长度
const int maxn = 1e6 + 5, maxm = 1e6 + 5;
#define bug printf("<-->\n");
#define NEXTLINE puts("");
int n, m;
char text[maxn], pattern[maxm];
int ne[maxm];
void prefix_table() {
    ne[0] = 0;
    for (int i = 1, j = 0; i < n;) {
        if (pattern[i] == pattern[j])
            ne[i ++ ] = ++ j;
        else if (j > 0)
            j = ne[j - 1];
        else // j <= 0，说明前i个字符没有相等的真前后缀
            ne[i ++ ] = 0;
    }
    for (int i = n - 1; i > 0; -- i)
        ne[i] = ne[i - 1];
    ne[0] = -1;
}
void kmp_search() {
    prefix_table();
    for (int i = 0, j = 0; i < m;) {
        if (j == n - 1 && text[i] == pattern[j]) {
            printf("%d ", i - j); // Found pattern at (i - j);
            j = ne[j];
        }
        if (text[i] == pattern[j])
            i ++ , j ++ ;
        else { // 如果不等于的话，使用前缀表得到最小移动位置
            j = ne[j];
            if (j == -1) // 如果是0表示直接从下一个字符开始匹配
                i ++ , j ++ ;
        }
    }
}
int main() {
    // m 是文本串的长度，n 是模式串的长度
    scanf("%d %s", &n, pattern);
    scanf("%d %s", &m, text);
    /*
     * n = 9, m = 19;
     * strcpy(text, "ABABABCABAABABAABAB");
     * strcpy(pattern, "ABABCABAA");
     */
    kmp_search();
    return 0;
}
