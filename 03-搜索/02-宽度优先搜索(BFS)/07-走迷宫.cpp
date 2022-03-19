/*----------------------------------------------------------------
 * 文件名称：走迷宫.cpp
 * 创建日期：2021年10月07日 星期四 10时44分54秒 
 * 题 目：AcWing 0844 走迷宫 
 * 算 法：宽度优先搜索，泛洪法 
 * 描 述：
 * 起点：(1, 1) 终点：(n, m) 1 为障碍物 求到终点最少移动距离 
 * 题目保证有解
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
// 上 右 下 左 上左 上右 下右 下左
const int dirx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int diry[] = {0, 1, 0, -1, -1, 1, 1, -1};
typedef pair<int, int> PII;
int n, m;
int g[maxn][maxn];
int d[maxn][maxn];
PII quu[maxn * maxn]; // 考试时使用 q 就好
int hh = 0, tt = -1;
// 插入 quu[++ tt] = x;
// 弹出 hh ++ ;
void BFS() {
    quu[++ tt] = {0, 0}; // 起点
    memset(d, -1, sizeof d); // 有 used 的作用
    d[0][0] = 0;
    while (hh <= tt) {
        auto t = quu[hh ++ ];
        // printf("%d %d\n", t.first, t.second);
        for (int i = 0; i < 4; ++ i) {
            int newx = t.first + dirx[i]; // 考试时使用 x, y 就好
            int newy = t.second + diry[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && g[newx][newy] == 0 && d[newx][newy] == -1)
            {
                d[newx][newy] = d[t.first][t.second] + 1;
                quu[ ++ tt] = {newx, newy};
            }
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            scanf("%d", &g[i][j]);
    BFS();
    printf("%d\n", d[n - 1][m - 1]);
    return 0;
}
