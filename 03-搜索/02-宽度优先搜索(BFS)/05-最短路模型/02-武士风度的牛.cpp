/*----------------------------------------------------------------
 * 文件名称：武士风度的牛.cpp
 * 创建日期：2021年11月23日 星期二 22时19分20秒 
 * 题 目：AcWing 0188 武士风度的牛 
 * 算 法：最短路模型 
 * 描 述：马走日 
 * . . . . . . . . . . 
 * . . . . * . . . . .
 * . . . . . . . . . .
 * . . . * . * . . . .
 * . . . . . . . * . .
 * . . * . . * . . . H
 * * . . . . . . . . .
 * . . . * . . . * . .
 * . K . . . . . . . .
 * . . . * . . . . . *
 * . . * . . . . * . .
 *
 * 从 K 到 H，* 是障碍，没有别马腿
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 155;
int n, m;
char g[maxn][maxn];
int dist[maxn][maxn];
const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
#define x first
#define y second
int BFS(PII start, PII end) {
    queue<PII> q;
    memset(dist, -1, sizeof dist);
    dist[start.x][start.y] = 0;
    q.push(start);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; ++ i)
            for (int j = 0; j < 8; ++ j) {
                int x = t.x + dx[i],
                y = t.y + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (g[x][y] == '*') continue;
                if (dist[x][y] != -1) continue;
                dist[x][y] = dist[t.x][t.y] + 1;
                if (make_pair(x, y) == end)
                    return dist[x][y];
                q.push({x, y});
            }
    }
    return -1; // 本题保证有解
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++ i)
        scanf("%s", g[i]);
    PII start, end;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) {
            if (g[i][j] == 'K')
                start = {i, j};
            if (g[i][j] == 'H')
                end = {i, j};
        }
    printf("%d\n", BFS(start, end));
    return 0;
}
