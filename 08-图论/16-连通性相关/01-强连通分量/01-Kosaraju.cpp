/*----------------------------------------------------------------
 *
 *   文件名称：01-Kosaraju.cpp
 *   创建日期：2021年03月26日 ---- 19时39分
 *   题    目：hdu1269 迷宫城堡
 *   算    法：Kosaraju
 *   描    述：一个有向图，有n个点(n <= 10000)和m条边(m <= 100000)
 *      判断整个图是否强连通，如果是，输出Yes，否则输出No
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 10005;
vector<int> g[maxn], rg[maxn];
vector<int> S; //存第一次dfs1的结果：标记点的先后顺序
int vis[maxn]; //在dfs1()中，用vis[i]记录点i是否被访问
int sccno[maxn]; //sccno[i]是第i个点所属的SCC，在dfs2()中，sccno[i]也被用于记录点i是否被访问
int cnt; // cnt：强连通分量的个数

void dfs1(int u) {
    if (vis[u])
        return;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); ++i)
        dfs1(g[u][i]);
    S.push_back(u);  //记录点的先后顺序，标记大的放在S的后面
}

void dfs2(int u) {
    if (sccno[u])
        return;
    sccno[u] = cnt;
    for (int i=0; i < rg[u].size(); ++i)
        dfs2(rg[u][i]);
}

void Kosaraju(int n) {
    cnt = 0;
    S.clear();
    memset(sccno, 0, sizeof(sccno));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        dfs1(i);  //点的编号：1~n。递归所有点
    for (int i = n-1; i >= 0; --i)
        if (!sccno[S[i]]) {
            cnt++;
            dfs2(S[i]);
        }
}

int main() {
    int n, m, u, v;
    while (scanf("%d %d", &n, &m), n != 0 || m != 0) {
        for(int i = 0; i < n; ++i) {
            g[i].clear();
            rg[i].clear();
        }
        for(int i = 0; i < m; ++i){
            scanf("%d %d", &u, &v);
            g[u].push_back(v);    //原图
            rg[v].push_back(u);   //反图
        }
        Kosaraju(n);
        printf("%s\n", cnt == 1 ? "Yes" : "No");
    }
    return 0;
}
