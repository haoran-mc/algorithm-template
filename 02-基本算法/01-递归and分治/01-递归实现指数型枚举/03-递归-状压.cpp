/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月11日 ---- 15时10分
 *   题    目：AcWing 92 递归实现指数型枚举
 *   算    法：递归
 *   描    述：从1~n这n(n < 20)个整数中随机选取任意多个，输出所有可能的选择方案
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#define NEXTLINE puts("");
int n;

void dfs(int u, int state) {
    if (u == n) {
        for (int i = 0; i < n; ++i)
            if (state >> i & 1)
                printf("%d ", i + 1);
        NEXTLINE;
        return ;
    }
    dfs(u + 1, state);
    dfs(u + 1, state | 1 << u);
}

int main() {
    scanf("%d", &n);
    dfs(0, 0);
    return 0;
}
