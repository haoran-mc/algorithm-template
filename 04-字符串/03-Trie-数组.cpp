/*----------------------------------------------------------------
 *
 *   文件名称：03-Trie-数组.cpp
 *   创建日期：2021年03月19日 ---- 16时40分
 *   题    目：hdu1251
 *   算    法：字典树
 *   描    述：更紧凑的存储方法是用数组实现字典树
 *      + dict数组存储的就是前缀的数目，如果输入的第一个子串是haoran，
 *        那么dict[1]存储的就是前缀是"h"的数目，dict[2]存储的就是前缀是
 *        "ha"的数目...
 *      + pos是要不停加加的，只有出现一个新的前缀pos++，所以dict数组
 *        不会覆盖
 *      + 那么怎么知道dict[i]存储的是谁的前缀呢？trie数组存放的是前缀
 *        位置
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 100;
int trie[maxn][26]; //用数组定义字典树，存储下一个字符的位置
int dict[maxn];     //以某一字符串为前缀的单词的数量
int pos = 1;        //当前新分配的存储位置
#define bug printf("<+++>\n");

/*在字典树中插入某个单词*/
void Insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int n = str[i] - 'a';
        if (trie[p][n] == 0) //如果对应的字符还没有值
            trie[p][n] = pos++;
        p = trie[p][n];
        dict[p]++;
    }
}

/*返回以某个字符串为前缀的单词的数量*/
int Find(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int n = str[i] - 'a';
        if (trie[p][n] == 0)
            return 0;
        p = trie[p][n];
    }
    return dict[p];
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char str[11];
    int n;
    scanf("%d", &n);  //n个字符串存入
    while (n--) {
        scanf("%s", str);
        Insert(str);
    }
    scanf("%d", &n);  //n个字符串查找
    while (n--) {
        scanf("%s", str);
        printf("%d\n", Find(str));
    }
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (trie[i][j] == 0)
                printf("0 ");
            else
                printf("%c ", j + 'a');
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (trie[i][j] == 0)
                printf("00 ");
            else
                printf("%02d ", trie[i][j]);
        }
        printf("\n");
    }
    return 0;
}
