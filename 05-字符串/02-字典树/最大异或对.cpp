/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年08月08日 星期日 17时43分39秒
 *   题    目：AcWing 0143 最大异或对
 *   算    法：Trie
 *   描    述：从n个数中找两个数，它们异或得到的值最大
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 3e6 + 5;
int son[maxm][2], idx;
int a[maxn];

void insert(int x) {
    int root = 0;
    // 取反i等于i >= 0
    for (int i = 30; ~i; --i) {
        int &s = son[root][x >> i & 1];
        if (!s)
            s = ++idx;
        root = s;
    }
    // cnt[root]++;   // 不需要这句
}

int query(int x) {
    int res = 0, root = 0;
    for (int i = 30; ~i; --i) {
        int bit = x >> i & 1;
        if (son[root][!bit]) {
            res += 1 << i;
            root = son[root][!bit];
        }
        else 
            root = son[root][bit];
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) 
        res = max(res, query(a[i]));
    printf("%d\n", res);
    return 0;
}
