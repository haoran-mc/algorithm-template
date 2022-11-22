/*----------------------------------------------------------------
 *
 *   文件名称：Trie字符串统计.cpp
 *   创建日期：2021年08月07日 星期六 20时16分23秒
 *   题    目：AcWing 0835 Trie字符串统计
 *   算    法：字典树
 *   描    述：
 *      简单，son就是一个字典树，实际上就是一个多链表
 *      cnt用来标记这个是不是字串的结尾
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
int son[maxn][26], cnt[maxn], idx;   // 下标是0的点，既是根结点，又是空节点

void insert(char str[]) {
    int root = 0;   // 根结点, 变量名随便定义，用p也可以
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[root][u]) // 创建新结点
            son[root][u] = ++idx;
        root = son[root][u];
    }
    cnt[root]++;   // 画个星星标记
}

// 查询这个字符串出现次数
int query(char str[]) {
    int root = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[root][u])
            return 0;
        root = son[root][u];
    }
    return cnt[root];
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        char op[2];
        char str[maxn];
        scanf("%s %s", op, str);
        if (op[0] == 'I')
            insert(str);
        else if (op[0] == 'Q')
            printf("%d\n", query(str));
    }
    return 0;
}
