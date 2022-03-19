/*----------------------------------------------------------------
 * 文件名称：池塘计数.cpp
 * 创建日期：2021年11月22日 星期一 21时47分37秒 
 * 题 目：AcWing 1097 池塘计数 
 * 算 法：洪泛法 
 * 描 述：雨水是 'W'，'.' 是土地，每个单元格与相邻的八个格子相连 
 * 问共有多少片相连的 'W' 块。
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <utility>
using namespace std;
int n, m;
const int maxn = 1e3 + 5;
const int maxm = maxn * maxn;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
bool used[maxn][maxn];
#define x first
#define y second
typedef pair<int, int> PII;
PII q[maxm];
char g[maxn][maxn];
void BFS(int x, int y) {
    int hh = 0, tt = -1;
    q[ ++ tt] = {x, y};
    used[x][y] = true;
    while (hh <= tt) {
        PII t = q[hh ++ ];
        for (int i = t.x - 1; i <= t.x + 1; ++ i)
            for (int j = t.y - 1; j <= t.y + 1; ++ j) {
                if (i == t.x && j == t.y) // 把一个 3 * 3 的矩阵中间挖掉
                    continue;
                if (i < 0 || i >= n || j < 0 || j >= m)
                    continue;
                if (g[i][j] == '.' || used[i][j])
                    continue;
                q[ ++ tt] = {i, j};
                used[i][j] = true;
            }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i)
        scanf("%s", g[i]);
    int cnt = 0;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            if (g[i][j] == 'W' && !used[i][j]) {
                BFS(i, j);
                cnt ++ ;
            }
    printf("%d\n", cnt);
    return 0;
}
