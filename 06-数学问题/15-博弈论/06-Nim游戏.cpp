/*----------------------------------------------------------------
 * 文件名称：拆分-Nim游戏.cpp
 * 创建日期：2021年10月15日 星期五 21时42分41秒 
 * 题 目：AcWing 0894 拆分-Nim游戏 
 * 算 法：博弈论 sg函数 
 * 描 述：
 * 给定 n 堆石子，两位玩家轮流操作，每次操作可以取走其中的一堆石子 
 * 然后放入两堆规模更小的石子（新堆规模可以为 0
 * 且两个新堆的石子总数可以大于取走的那堆石子数）
 * 最后无法进行操作的人视为失败。
 * 问如果两人都采用最优策略，先手是否必胜。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
#include <unordered_set>
using namespace std;
const int maxn = 100 + 5;
int f[maxn];
int sg(int x) {
    if (f[x] != -1)
        return f[x];
    unordered_set<int> S;
    // 分成两堆
    for (int i = 0; i < x; ++ i)
        for (int j = 0; j <= i; ++ j)
            S.insert(sg(i) ^ sg(j));
    // mex
    for (int i = 0; ; ++ i)
        if (S.count(i) == 0)
            return f[x] = i;
}
int main() {
    memset(f, -1, sizeof f);
    int n; scanf("%d", &n);
    int res = 0;
    for (int i = 0; i < n; ++ i) {
        int _; scanf("%d", &_);
        res ^= sg(_);
    }
    if (res == 0)
        puts("No");
    else
        puts("Yes");
    return 0;
}
