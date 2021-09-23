/*----------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月11日 ---- 15时10分
 *   题    目：AcWing 92 递归实现指数型枚举
 *   算    法：递归
 *   描    述：从1~n这n(n < 20)个整数中随机选取任意多个，
 *   输出所有可能的选择方案
 *
----------------------------------------------------------*/

#include <cstdio>
#define NEXTLINE puts("");
const int maxn = 20;
int n;
bool st[maxn];

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; ++i)
            if (st[i])
                printf("%d ", i);
        NEXTLINE;
        return ;
    }
    st[u] = true;
    dfs(u + 1);

    st[u] = false;
    dfs(u + 1);
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}
