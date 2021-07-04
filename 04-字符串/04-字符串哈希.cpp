/*----------------------------------------------------------------
 *
 *   文件名称：04-字符串哈希.cpp
 *   创建日期：2021年03月19日 ---- 16时01分
 *   题    目：hdu1648
 *   算    法：字符串哈希
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 10005;
struct Node {
    char name[35];
    int price;
};
vector<Node> List[maxn]; //用于解决冲突

unsigned int BKDRHash(char *str) {
    unsigned int seed = 31, key = 0;
    while (*str)
        key = key * seed + (*str++);
    return key & 0x7fffffff;
}

int main() {
    int n, m, key, add, memory_price, rank, len;
    int p[maxn];
    char s[35];
    Node t;
    while (scanf("%d", &n)) {
        for (int i = 0; i < maxn; ++i)
            List[i].clear();
        for (int i = 0; i < n; ++i) {
            scanf("%s", t.name);
            key = BKDRHash(t.name) % maxn;
            List[key].push_back(t);
        }
        scanf("%d", &m);
        while (m--) {
            rank = len = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%d %s", &add, s);
                key = BKDRHash(s) % maxn;
                for (int j = 0; j < List[key].size(); ++j)
                    if (strcmp(List[key][j].name, s) == 0) {
                        List[key][j].price += add;
                        if (strcmp(s, "memory") == 0)
                            memory_price = List[key][j].price;
                        else
                            p[len++] = List[key][j].price;
                        break;
                    }
            }
            for (int i = 0; i < len; ++i)
                if (memory_price < p[i])
                    rank++;
            printf("%d\n", rank + 1);
        }
    }
    return 0;
}
