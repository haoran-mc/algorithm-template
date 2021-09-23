/*----------------------------------------------------------------
 *
 *   文件名称：01-边双连通分量.cpp
 *   创建日期：2021年03月26日 ---- 15时13分
 *   题    目：poj3352 Road Construction
 *   算    法：边双连通分量
 *   描    述：给定一个无向图，图中没有重边，问添加几条边才能使无
 *      向图变成边双连通分量
 *
 ----------------------------------------------------------------*/

#include<cstring>
#include<vector>
#include<stdio.h>
using namespace std;
const int maxn = 1005;
int n, m, low[maxn], dfn;
vector<int> g[maxn];

void dfs(int u, int fa) {  //计算每个点的low值
    low[u] = ++dfn;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa)
            continue;
        if (!low[v])
            dfs(v, u);
        low[u] = min(low[u], low[v]);
    }
}

int tarjan() {
    int degree[maxn];  //计算每个缩点的度数
    memset(degree, 0, sizeof(degree));
    for (int i = 1; i <= n; ++i)  //把有相同low值的点看成一个缩点
        for (int j = 0; j < g[i].size(); ++j)
            if (low[i] != low[g[i][j]])
                degree[low[i]]++;
    int res = 0;
    for(int i = 1; i <= n; ++i)  //统计度数为1的缩点个数
        if (degree[i] == 1)
            ++res;
    return res;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(low, 0, sizeof(low));
        for (int i = 0; i <= n; ++i)
            g[i].clear();
        for (int i = 1; i <= m; ++i) {
            int ver1, ver2;
            scanf("%d%d", &ver1, &ver2);
            g[ver1].push_back(ver2);
            g[ver2].push_back(ver1);
        }
        dfn = 0;
        dfs(1, -1);
        int ans = tarjan();
        printf("%d\n", (ans+1)/2);
    }
    return 0;
}
