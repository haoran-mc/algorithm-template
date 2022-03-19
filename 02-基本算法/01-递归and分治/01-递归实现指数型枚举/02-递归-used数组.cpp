/*----------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年05月11日 ---- 15时10分
 * 题 目：AcWing 92 递归实现指数型枚举
 * 算 法：递归
 * 描 述：从 [1, n]这n（n < 20）个整数中随机选取任意多个
 * 输出所有可能的选择方案，每个方案的数按升序输出
 ----------------------------------------------------------*/
#include <cstdio>
const int maxn = 20;
int n;
bool used[maxn];

void DFS(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; ++ i)
            if (used[i])
                printf("%d ", i);
        puts("");
        return;
    }
    DFS(x + 1);
    used[x] = true;
    DFS(x + 1);
    used[x] = false;
}

int main() {
    scanf("%d", &n);
    DFS(1);
    return 0;
}
