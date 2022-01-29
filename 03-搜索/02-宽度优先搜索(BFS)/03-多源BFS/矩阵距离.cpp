/*----------------------------------------------------------------
 * 文件名称：矩阵距离.cpp
 * 创建日期：2021年11月24日 星期三 13时03分49秒 
 * 题 目：AcWing 0173 矩阵距离 
 * 算 法：多源BFS
 * 描 述：输入一个01矩阵，输出每个0到达最近的1的曼哈顿距离 
 * 
 * 3 4
 * 0001
 * 0011
 * 0110
 *
 * 3 2 1 0
 * 2 1 0 0
 * 1 0 0 1
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
char g[maxn][maxn];
int dist[maxn][maxn];
typedef pair<int, int> PII;
#define NEXTLINE puts("");
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

void BFS() {
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            if (g[i][j] == '1') {
                q.push({i, j});
                dist[i][j] = 0;
            }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++ i) {
            int x = t.first + dx[i],
            y = t.second + dy[i];
            if (0 <= x && x < n && 0 <= y && y < m && dist[x][y] == -1) {
                dist[x][y] = dist[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i)
        scanf("%s", g[i]);
    BFS();
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j)
            printf("%d ", dist[i][j]);
        NEXTLINE;
    }
    return 0;
}
