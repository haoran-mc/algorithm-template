/*----------------------------------------------------------------
 *
 *   文件名称：02.cpp
 *   创建日期：2021年05月11日 星期二 21时42分25秒
 *   题    目：AcWing 93 递归组合型枚举
 *   算    法：非递归，二进制状态压缩
 *   描    述：不使用递归
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <stack>
using namespace std;
#define bug printf("<++>\n");
#define NEXTLINE puts("");
int n, m;
struct State {
    int pos; //记录递归运行的位置，递归的关键
    int u, cnt, state;
};

void DFS(int u, int cnt, int state) {
    // 0:
    if (cnt + n - u < m)
        return ;
    if (cnt == m) {
        for (int i = 0; i < n; ++i)
            if (state >> i & 1)
                printf("%d ", i + 1);
        NEXTLINE;
        return ;
    }

    DFS(u + 1, cnt + 1, state | 1 << u);
    // 1:
    DFS(u + 1, cnt, state);
    // 2:
}

int main() {
    scanf("%d %d", &n, &m);
    stack<State> stk;
    stk.push({0, 0, 0, 0}); //这样也行?
    while (stk.size()) {
        auto sta = stk.top();
        stk.pop();
        if (sta.pos == 0) {
            if (sta.cnt + n - sta.u < m)
                continue;
            if (sta.cnt == m) {
                for (int i = 0; i < n; ++i)
                    if (sta.state >> i & 1)
                        printf("%d ", i + 1);
                NEXTLINE;
                continue;
            }
            sta.pos = 1;
            stk.push(sta);
            stk.push({0, sta.u+1, sta.cnt+1, sta.state | 1 << sta.u});
        }
        else if (sta.pos == 1) {
            sta.pos = 2;
            stk.push(sta);
            stk.push({0, sta.u+1, sta.cnt, sta.state});
        }
        else
            continue;
    }
    return 0;
}
