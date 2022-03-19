/*----------------------------------------------------------------
 * 文件名称：迷宫问题.cpp
 * 创建日期：2021年11月23日 星期二 19时50分36秒 
 * 题 目：AcWing 1076 迷宫问题 
 * 算 法：最短路模型 
 * 描 述：输出从左上角到右下角的最短路线，0表示可以走，1表示 
 * 不可以走 
 * 0 1 0 0 0
 * 0 1 0 1 0
 * 0 0 0 0 0
 * 0 1 1 1 0
 * 0 0 0 1 0
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
const int maxn = 1e3 + 5;
const int maxm = maxn * maxn;
typedef pair<int, int> PII;
int n, g[maxn][maxn];
PII q[maxm];
PII pre[maxn][maxn];
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
#define x first
#define y second
void BFS(int x, int y) {
    int hh = 0, tt = -1;
    q[ ++ tt] = {x, y};
    memset(pre, -1, sizeof pre);
    pre[x][y] = {0, 0};
    while (hh <= tt) {
        PII t = q[hh ++ ];
        for (int i = 0; i < 4; ++ i) {
            int nx = t.x + dx[i],
            ny = t.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (g[nx][ny]) continue;
            if (pre[nx][ny].x != -1) continue;
            q[ ++ tt] = {nx, ny};
            pre[nx][ny] = t;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            scanf("%d", &g[i][j]);
    BFS(n - 1, n - 1);
    // pre 中存储的是结果路线中每个位置的前一个位置
    PII end(0, 0);
    while (true) {
        printf("%d %d\n", end.x, end.y);
        if (end.x == n - 1 && end.y == n - 1)
            break;
        end = pre[end.x][end.y];
    }
    return 0;
}
