#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1000;
const int inf  = 0x3f3f3f3f;
int g[maxn][maxn];
int n, m;
int source = 1;
int dist[maxn]; /*d数组，存放源点到各顶点的距离*/
bool used[maxn];
vector<int> pre[maxn]; /*记录路径*/

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[source] = 0; /*源点到源点的距离为0，可更改*/
    for (int i = 0; i < n; ++i) { /*每次仅开放一个顶点，所以需要重复访问n-1次(源点不需重复访问)*/
        int vert = -1; /*特判源点*/
        for (int j = 0; j <= n; ++j) /*找到未访问过的顶点中有路径可以到达的距离源点最短的顶点*/
            if (used[j] == false && (vert == -1 || dist[j] < dist[vert])) /*特判源点*/
                vert = j;
        used[vert] = true; /*标记已被访问*/
        for (int j = 0; j < n; ++j) { /*更新能够被更新的顶点与距源点的最短距离*/
            if (used[j] == false && g[vert][j] != inf) {
                /*以vert为中介点可以使dist[j]更优，那么j的前驱变成vert，而且需要先清空pre[j]，因为pre[j]中存储的是之前j的最短路径中，j的前驱结点*/
                if (dist[vert] + g[vert][j] < dist[j]) {
                    dist[j] = dist[vert] + g[vert][j];
                    pre[j].clear();
                    pre[j].push_back(vert);
                }
                /*以vert为中介点找到j的另一条最短路径，那么添加j的前驱vert*/
                else if (dist[vert] + g[vert][j] == dist[j])
                    pre[j].push_back(vert);
            }
        }
    }
}

int optval = inf;
vector<int> optPath;
vector<int> temPath;
void seekopt(int vert) {
    if (vert == source) {
        temPath.push_back(vert);
        int val = 0;
        // 使用第二标尺计算temPath上的val
        /*
         * 边权之和
         *for (int i = temPath.size() - 1; i > 0; --i) {
         *    int ver = temPath[i];
         *    int nxtver = temPath[i-1];
         *    val += Edge[ver][nxtver];
         *}
         */
        /*
         * 点权之和
         *for (int i = temPath.size() - 1; i >= 0; --i) {
         *    int ver = temPath[i];
         *    val += Dot[ver];
         *}
         */
        if (val /*优于 optval*/) {
            optval = val;
            optPath = temPath;
        }
        temPath.pop_back();
        return ;
    }
    temPath.push_back(vert);
    for (int i = 0; i < (int)pre[vert].size(); ++i)
        seekopt(pre[vert][i]);
    temPath.pop_back();
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    source = 1; /*源点为1*/
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; ++i) /*没有0顶点*/
        g[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        int vert;
        int edge;
        int weig;
        scanf("%d", &vert);
        scanf("%d", &edge);
        scanf("%d", &weig);
        g[vert][edge] = min(g[vert][edge], weig);
    }
    dijkstra();
    seekopt(6); /*寻找结点6的最优解*/
    /*打印出最优解路径(因为输入是倒着输入的)*/
    for (int i = optPath.size() - 1; i >= 0; --i)
        printf("%d ", optPath[i]);
    printf("\n%d\n", optval);
    return 0;
}
