/*----------------------------------------------------------------
 * 文件名称：二分图的最大匹配(匈牙利算法).cpp
 * 创建日期：2021年10月08日 星期五 21时35分08秒 
 * 题 目：AcWing 0861 二分图的最大匹配 
 * 算 法：匈牙利算法 
 * 描 述：左半部包含n1个点，右半部包含n1个点，二分图共有m个边 
 * 输出最大匹配 
 * 虽然是无向边，但是因为只会为男生找女生，所以只需要存一条有向边就可以
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
int n1, n2, m;
int h[maxn], e[maxn], ne[maxn], idx;
int match[maxn]; // 每个女孩找到的哪个男孩
bool used[maxn]; // 不重复搜一个点，就是有可能两个点之间有多条边
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
bool find(int u) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!used[j]) { // 如果这个点未搜过
            used[j] = true;
            // 如果这个女孩还没找到男朋友，或者她的男朋友可以换人
            if (match[j] == 0 || find(match[j])) {
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}
int main() {
    scanf("%d %d %d", &n1, &n2, &m);
    memset(h, -1, sizeof h);
    while (m -- ) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
    }
    int res = 0; // 匹配数量
    // 给男生找女朋友
    for (int i = 1; i <= n1; ++ i) {
        memset(used, false, sizeof used);
        if (find(i))
            res ++ ;
    }
    printf("%d\n", res);
    return 0;
}
