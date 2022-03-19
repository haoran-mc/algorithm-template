/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年05月11日 星期二 21时00分48秒
 * 题 目：AcWing 93 递归组合型枚举
 * 算 法：递归，二进制状态压缩
 * 描 述：从 [1, n] 这 n 个整数中选择 m 个，输出所有可能的方案数
 * 对于不同的方案，字典序小的方案先输出
 * 对于每个方案，升序输出
 ----------------------------------------------------------------*/
#include <cstdio>
int n, m;

void DFS(int start, int cnt, int state) {
    if (n - start + cnt < m) // 剪枝
        return;
    if (cnt == m) {
        for (int i = 0; i < n; ++ i)
            if (state >> i & 1)
                printf("%d ", i + 1);
        puts("");
        return;
    }
    // 下面两句反过来试试？
    DFS(start + 1, cnt + 1, state | 1 << start);
    DFS(start + 1, cnt, state);
}

int main() {
    scanf("%d %d", &n, &m);
    DFS(0, 0, 0);
    return 0;
}
