/*----------------------------------------------------------------
 * 文件名称：没有上司的舞会.cpp
 * 创建日期：2021年11月01日 星期一 21时07分35秒 
 * 题 目：AcWing 0285 没有上司的舞会 
 * 算 法：树形DP
 * 描 述：某大学有 n 个职员，编号为 [1, n]。他们之间有从属关系 
 * 也就是说他们的关系就像一棵以校长为根的树，父结点就是子结点的直接上司 
 * 现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数 ai，
 * 但是呢，如果某个职员的上司来参加舞会了，
 * 那么这个职员就无论如何也不肯来参加舞会了。
 * 所以，请你编程计算，邀请哪些职员可以使快乐指数最大，求最大的快乐指数。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 6000 + 5;
int n, happy[maxn];
int dp[maxn][2];
int h[maxn], e[maxn], ne[maxn], idx;
bool has_father[maxn];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
void DFS(int u) {
    dp[u][1] = happy[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        DFS(j);
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0];
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &happy[i]);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; ++ i) {
        int a, b; // b 是 a 的上司
        scanf("%d %d", &a, &b);
        has_father[a] = true;
        add(b, a);
    }
    int root = 1;
    while (has_father[root])
        root ++ ;
    DFS(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));
    return 0;
}
