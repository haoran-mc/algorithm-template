/*----------------------------------------------------------------
 * 文件名称：电路维修.cpp
 * 创建日期：2021年11月24日 星期三 21时23分48秒 
 * 题 目：AcWing 0175 电路维修 
 * 算 法：双端队列宽度优先搜索 
 * 描 述：
 * \\/\\
 * \\///
 * /\\\\
 *
 * 对于上面这个电路，电从左上角进入，转动最少的电线能使电从右下角
 * 离开
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
const int maxn = 505;
int n, m;
char g[maxn][maxn];
typedef pair<int, int> PII;
int dist[maxn][maxn];
bool used[maxn][maxn];
const int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
const int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1};
#define x first
#define y second

int BFS() {
    deque<PII> q;
    memset(used, 0, sizeof used);
    memset(dist, 0x3f, sizeof dist);
    char cs[5] = "\\/\\/";
    dist[0][0] = 0;
    q.push_back({0, 0});
    while (q.size()) {
        auto t = q.front(); q.pop_front();
        if (t.x == n && t.y == m)
            return dist[t.x][t.y];
        if (used[t.x][t.y])
            continue;
        used[t.x][t.y] = true;
        for (int i = 0; i < 4; ++ i) {
            int x = t.x + dx[i],
            y = t.y + dy[i];
            if (x < 0 || x > n || y < 0 || y > m) continue;
            int ga = t.x + ix[i], gb = t.y + iy[i];
            int w = (g[ga][gb] != cs[i]);
            int d = dist[t.x][t.y] + w;
            if (d <= dist[x][y]) {
                dist[x][y] = d;
                if (!w)
                    q.push_front({x, y});
                else
                    q.push_back({x, y});
            }
        }
    }
    return -1;
}

int main() {
    int t; scanf("%d", &t);
    while (t -- ) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++ i)
            scanf("%s", g[i]);
        if ((n + m) & 1)
            puts("NO SOLUTION");
        else
            printf("%d\n", BFS());
    }
    return 0;
}
