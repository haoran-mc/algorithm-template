/*----------------------------------------------------------------
 *
 *   文件名称：01-Anniversary-Party.cpp
 *   创建日期：2021年03月09日 ---- 18时08分
 *   题    目：hdu1520 Anniversary Party
 *   算    法：树形DP
 *   描    述：一颗有根树上每个结点有一个权值，相邻的父结点和子结点只能选择一个
 *      问如何选择使得总权值之和最大(邀请员工参加宴会，为了避免员工和直属上司发
 *      生尴尬，规定员工和直属上司不能同时出席)
 *   输    入：(规定结点编号从1到N)，输入第一行是一个数字N，后续N行中的每一行都
 *      包含结点的权值，范围是 -128 ~ 127，下面T行分别输入两个结点，后一个结点
 *      是前一个结点的父亲，读到0 0结束
 *      5
 *      1 1 1 1 1
 *      1 3
 *      2 3
 *      4 5
 *      3 5
 *      0 0
 *   输    出：总的最大权值
 *      3
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 6005;
int n;
int value[maxn];
int dp[maxn][2];
int fa[maxn];
vector<int> tree[maxn];

void dfs(int node) {
    dp[node][0] = 0; //每次都初始化，不参加宴会(不选择当前结点)
    dp[node][1] = value[node]; //参加宴会(选择当前结点)
    for (int i = 0; i < tree[node].size(); ++i) {
        int son = tree[node][i];
        dfs(son);
        dp[node][0] += max(dp[son][1], dp[son][0]); //父结点不选，那么子结点可选可不选
        dp[node][1] += dp[son][0]; //选择父结点，子结点不能选
    }
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &value[i]);
            tree[i].clear();
            fa[i] = -1;
        }
        while (1) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a == 0 && b == 0)
                break;
            tree[b].push_back(a); //邻接表建树
            fa[a] = b;
        }
        int t = 1;
        while (fa[t] != -1)
            t = fa[t]; //找到根结点
        dfs(t);
        printf("%d\n", max(dp[t][1], dp[t][0]));
    }
    return 0;
}
