/*----------------------------------------------------------------
 *
 *   文件名称：01-Edmonds-Karp.cpp
 *   创建日期：2021年03月26日 ---- 21时44分
 *   题    目：hdu1532 Drainage Ditches
 *   算    法：最大流Edmonds-Karp
 *   描    述：源点到终点的最大流速
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 1e9;
const int maxn = 300;
int n, m;
int g[maxn][maxn];
int pre[maxn];
// g[][]不仅记录图，还是残留网络

int bfs(int s, int t) {
    int flow[maxn];
    memset(pre, -1, sizeof pre);
    flow[s] = inf;
    pre[s] = 0;          //初始化起点
    queue<int> Q;
    Q.push(s);           //起点入栈，开始bfs
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (u == t)
            break;                  //搜到一个路径，这次bfs结束
        for (int i = 1; i <= m; ++i) {        //bfs所有的点
            if (i != s && g[u][i] > 0 && pre[i] == -1) {
                pre[i] = u;         //记录路径
                Q.push(i);
                flow[i] = min(flow[u], g[u][i]); //更新结点流量
            }
        }
    }
    if (pre[t] == -1)               //没有找到新的增广路
        return -1;
    return flow[t];                 //返回这个增广路的流量
}

int maxflow(int s, int t) {
    int Maxflow = 0;
    while (1) {
        int flow = bfs(s, t);
        //执行一次bfs，找到一条路径，返回路径的流量
        if (flow == -1)             //没有找到新的增广路，结束
            break;
        int cur = t;                //更新路径上的残留网络
        while (cur!=s) {            //一直沿路径回溯到起点
            int father = pre[cur];  //pre[]记录路径上的前一个点
            g[father][cur] -= flow; //更新残留网络：正向减
            g[cur][father] += flow; //更新残留网络：反向加
            cur = father;
        }
        Maxflow += flow;
    }
    return Maxflow;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        memset(g, 0, sizeof g);
        for (int i = 0; i < n; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] += w;            //可能有重边
        }
        printf("%d\n", maxflow(1, m));
    }
    return 0;
}
