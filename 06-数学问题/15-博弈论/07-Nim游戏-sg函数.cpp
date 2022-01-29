/*----------------------------------------------------------------
 * 文件名称：集合-Nim游戏-sg函数.cpp
 * 创建日期：2021年10月15日 星期五 12时47分50秒 
 * 题 目：AcWing 0893 集合-Nim游戏 
 * 算 法：博弈论 sg函数 
 * 描 述：
 * 给定 n 堆石子以及一个由 k 个不同正整数构成的数字集合 S。 
 * 现在有两位玩家轮流操作，每次操作可以从任意一堆石子中拿取石子，
 * 每次拿取的石子数量必须包含于集合 S，最后无法进行操作的人视为失败。
 * 问如果两人都采用最优策略，先手是否必胜。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
#include <unordered_set>
using namespace std;
const int maxn = 105, maxm = 1e4 + 5;
int n, m;
int s[maxn];
int used[maxm];
int sg(int x) {
    if (used[x] != -1)
        return used[x];
    // 哈希表存储所有能到的局面
    unordered_set<int> S;
    for (int i = 0; i < m; ++ i) {
        int sum = s[i];
        if (x >= sum)
            S.insert(sg(x - sum));
    }
    for (int i = 0; ; ++ i)
        if (!S.count(i))
            return used[x] = i;
}
int main() {
    // 集合 S 中的数的个数
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i)
        scanf("%d", &s[i]);
    memset(used, -1, sizeof used);
    scanf("%d", &n);
    int res = 0;
    for (int i = 0; i < n; ++ i) {
        int x; scanf("%d", &x);
        res ^= sg(x);
    }
    if (res == 0)
        puts("No");
    else
        puts("Yes");
    return 0;
}
