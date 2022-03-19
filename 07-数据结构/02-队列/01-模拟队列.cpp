/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年07月29日 星期四 00时24分27秒
 *   题    目：AcWing 0829 模拟队列
 *   算    法：队列
 *   描    述：
 *      栈可能会出现边界问题，所以可能在栈底放一个特殊元素
 *      而队列不会出现这样的边界
 *      为了使这两个数据结构插入元素时都使用++tt，所以队列的tt初始为-1
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
int q[maxn], hh = 0, tt = -1;

// 插入：q[++tt] = x;
// 弹出：hh++;

int main() {
    int t; scanf("%d", &t);
    char op[10];
    while (t--) {
        scanf("%s", &op);
        if (!strcmp(op, "push")) {
            int x; scanf("%d", &x);
            q[++tt] = x;
        }
        else if (!strcmp(op, "pop")) {
            hh++;
        }
        else if (!strcmp(op, "empty")) {
            printf(hh > tt ? "YES\n" : "NO\n");
        }
        else if (!strcmp(op, "query")) {
            printf("%d\n", q[hh]);
        }
    }
    return 0;
}
