/*----------------------------------------------------------------
 *   
 *   文件名称：KMP字符串.cpp
 *   创建日期：2021年08月06日 星期五 21时23分58秒
 *   题    目：AcWing 0831 KMP字符串
 *   算    法：KMP
 *   描    述：最后还是使用了灯笼的模板
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1e6 + 5, maxm = 1e6 + 5;
#define bug printf("<-->\n");
#define NEXTLINE puts("");
int n, m;
char text[maxn], pattern[maxm];
int preT[maxm];

/**
 * KMP灵魂：生成前缀表
 *
 * a b a b c
 * 假如是这样一个模式串，我们来生成它的前缀表。
 * a
 * a b
 * a b a
 * a b a b
 * a b a b c
 * 对于模式串的所有前缀，得到他们的最长公共前后缀长度。
 *
 * 对于[a b a b]这个原串的前缀(前后缀长度不能等于原串的长度)：
 * 他的最长前缀是：a b a；它的最长后缀是：b a b. 最长前缀不等于最长后缀；
 * 它的第二长前缀：a b  ；它的第二长后缀：a b. 第二长前缀等于第二长后缀；
 * 所以这个原串的前缀的最长公共前后缀长度为2。
 *
 * 同理就可以得到下面这个前缀表：
 * -1
 * 0  a
 * 0  a b
 * 1  a b a
 * 2  a b a b
 * 0  a b a b c
 *
 * 为了处理边界，我们在最上面添加一个-1，并删除最后一个0，得到最终前缀表：-1, 0, 0, 1, 2
 *
 *  a b a b c
 * -1 0 0 1 2
 *  !!!(注意上面这个前缀表，灯笼与雪菜此处下标不同)
 *
 */
void prefix_table() {
    preT[0] = 0;
    int len = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            preT[i] = len;
            i++;
        }
        else if (len > 0)
            len = preT[len-1];
        else {
            preT[i] = 0;
            i++;
        }
    }
    // 向后移动一位
    for (int i = m-1; i > 0; --i) 
        preT[i] = preT[i-1];
    preT[0] = -1;
}

void kmp_search() {
    prefix_table();
    // text[i], pattern[j];
    int i = 0, j = 0;
    while (i < n) {
        if (j == m - 1 && text[i] == pattern[j]) {
            printf("%d ", i - j);
            // printf("Found pattern at %d\n", i - j);
            j = preT[j];
        }
        if (text[i] == pattern[j]) 
            i++, j++;
        else {
            // 如果不等于的话，使用前缀表得到最小移动位置
            j = preT[j];
            if (j == -1)  // 如果是-1表示直接匹配从下一个字符开始匹配
                i++, j++;
        }
    }
}

int main() {
    scanf("%d %s", &m, pattern);
    scanf("%d %s", &n, text);
    // n = 19, m = 9;
    // strcpy(text, "ABABABCABAABABAABAB");
    // strcpy(pattern, "ABABCABAA");
    kmp_search();
    return 0;
}
