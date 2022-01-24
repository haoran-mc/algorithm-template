/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月11日 星期二 21时00分48秒
 *   题    目：AcWing 93 递归组合型枚举
 *   算    法：递归，二进制状态压缩
 *   描    述：使用递归
 *
 ----------------------------------------------------------------*/

#include <cstdio>
using namespace std;
#define bug printf("<++>\n");
#define NEXTLINE puts("");
int n, m;

void dfs(int u, int cnt, int state) {
    // if (cnt + (n - u) < m || cnt > m)  //之所以不需要cnt > m这句剪枝，是因为当cnt == m时会return，所以不可能到达cnt == 4
    if (cnt + n - u < m)
        return ;
    if (cnt == m) {
        for (int i = 0; i < n; ++i)
            if (state >> i & 1)
                printf("%d ", i + 1);
        NEXTLINE;
        return ;
    }

    dfs(u + 1, cnt + 1, state | 1 << u);
    dfs(u + 1, cnt, state);
}

int main() {
    scanf("%d %d", &n, &m);
    dfs(0, 0, 0);
    return 0;
}
