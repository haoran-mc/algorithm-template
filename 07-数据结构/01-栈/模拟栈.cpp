/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年07月28日 星期三 21时51分40秒
 *   题    目：AcWing 0828 模拟栈
 *   算    法：栈
 *   描    述：<++>
 *       实现一个栈，栈初始为空，支持四种操作：
 *       - push x – 向栈顶插入一个数 x；
 *       - pop – 从栈顶弹出一个数；
 *       - empty – 判断栈是否为空；
 *       - query – 查询栈顶元素。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
int stk[maxn], tt = 0;

// 插入：stk[++tt] = x;
// 弹出：stk[tt--] = x;
// 为什么stk[0]这个位置不用呢？把它留着作为边界，或者在stk[0]这个位置放一个特殊的值

int main() {
    int t; scanf("%d", &t);
    char op[10];
    while (t--) {
        scanf("%s", op);
        if (!strcmp(op, "push")) {
            int x; scanf("%d", &x);
            stk[++tt] = x;
        }
        else if (!strcmp(op, "pop")) {
            tt--;
        }
        else if (!strcmp(op, "empty")) {
            printf(tt ? "NO\n" : "YES\n");
        }
        else if (!strcmp(op, "query")) {
            printf("%d\n", stk[tt]);
        }
    }
    return 0;
}
