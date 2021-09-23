/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年08月11日 星期三 11时14分32秒
 *   题    目：AcWing 0842 排列数字
 *   算    法：深度优先搜索
 *   描    述：排列数字，将[1, n]的数字排列
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 10;
#define NEXTLINE puts("");
int path[maxn];
bool used[maxn];
int n;

void DFS(int u) {
    if (u == n) {
        for (int i = 0; i < n; ++i)
            printf("%d ", path[i]);
        NEXTLINE
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!used[i]) {
            path[u] = i;
            used[i] = true;
            DFS(u + 1);
            used[i] = false;
        }
}

int main() {
    scanf("%d", &n);
    DFS(0);
    return 0;
}
