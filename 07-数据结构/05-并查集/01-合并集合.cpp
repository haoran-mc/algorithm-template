/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年08月08日 星期日 17时48分14秒 
 * 题 目：AcWing 0836 合并集合 
 * 算 法：并茶集 
 * 描 述：路径压缩，按秩合并代码比这个长，而且效率低 
 * M a b，将编号为 a 和 b 的两个数所在的集合合并 
 * Q a b，询问编号为 a 和 b 的两个数是否在同一个集合中
 *
 * 0 <= n, m <= 1e5
 *
 ----------------------------------------------------------------*/
#include <cstdio>
const int maxn = 1e5 + 5;
int n, m;
int fa[maxn];
// 返回x的祖宗结点 + 路径压缩
int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) // 灯笼的init()函数，根据题目要求选择从下标1开始还是0开始
        fa[i] = i;
    while (m--) {
        char op[2];
        int a, b;
        scanf("%s %d %d", op, &a, &b);
        if (op[0] == 'M')
            fa[find(a)] = find(b); // 灯笼的union_vert()函数，给a的祖宗认个爹
        else if (op[0] == 'Q') {
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
