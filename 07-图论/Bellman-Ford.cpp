#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1000;
int n, m;
/*目标点、到目标点的距离*/
struct Info {int aim, dis;};
vector<Info> g[maxn];
int dist[maxn];
int source = 0;

bool Bellman() {
    memset(dist, 0x3f, sizeof(dist));
    dist[source] = 0;
    /*Bellman算法的松弛操作不会超过n-1轮*/
    for (int i = 0; i < n-1; ++i)
        /*对每条边进行松弛操作n-1次*/
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < (int)g[j].size(); ++k) {
                int vert = g[j][k].aim;
                int edge = g[j][k].dis;
                if (dist[j] + edge < dist[vert])
                    dist[vert] = dist[j] + edge;
            }
    /*再松弛最后一次，如果还能被松弛，说明有负环*/
    for (int j = 0; j < n; ++j)
        for (int k = 0; k < (int)g[j].size(); ++k) {
            int vert = g[j][k].aim;
            int edge = g[j][k].dis;
            if (dist[j] + edge < dist[vert])
                return false;
        }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        Info info;
        info.aim = y;
        info.dis = z;
        g[x].push_back(info);
    }
    //输出0表示有负环，反之没有
    printf("%d\n", Bellman());
    return 0;
}
