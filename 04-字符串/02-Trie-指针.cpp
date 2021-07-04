/*----------------------------------------------------------------
 *
 *   文件名称：02-Trie-指针.cpp
 *   创建日期：2021年03月19日 ---- 16时30分
 *   题    目：hdu1251
 *   算    法：字典树
 *   描    述：正规的字典树实现，定义字典树的数据结构，并用指针指向下一层子树
 *      代码很清晰，不过由于本题空间要求高，Insert()内用new Trie分配
 *      的空间超过了题目的限制
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
using namespace std;
struct Trie {
    Trie* next[26];
    int num;
    Trie() {
        for (int i = 0; i < 26; ++i)
            next[i] = NULL;
        num = 0;
    }
};
Trie root;

void Insert(char str[]) {
    Trie* p = &root;
    for (int i = 0; str[i]; ++i) {
        if (p -> next[str[i] - 'a'] == NULL)
            p -> next[str[i] - 'a'] = new Trie;
        p = p -> next[str[i] - 'a'];
        p -> num++;
    }
}

int Find(char str[]) {
    Trie* p = &root;
    for (int i = 0; str[i]; ++i) {
        if (p -> next[str[i] - 'a'] == NULL)
            return 0;
        p = p -> next[str[i] - 'a'];
    }
    return p -> num;
}

int main() {
    char str[11];
    while (scanf("%s", str)) {
        if (!strlen(str))  //输入空行
            break;
        Insert(str);
    }
    while (scanf("%s", str))
        printf("%d\n", Find(str));
    return 0;
}
