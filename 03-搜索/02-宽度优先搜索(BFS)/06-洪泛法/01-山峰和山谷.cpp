/*----------------------------------------------------------------
 * 文件名称：山峰和山谷.cpp
 * 创建日期：2021年11月23日 星期二 09时14分20秒 5 * 题 目：AcWing 1106 山峰和山谷 6 * 算 法：洪泛法 7 * 描 述：就是找山峰山谷 8 * 9 * 8 8 8 7 7
 * 7 7 8 8 7
 * 7 7 7 7 7
 * 7 8 8 7 8
 * 7 8 8 8 8
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
const int maxn = 1e3 + 5, maxm = maxn * maxn;
int n;
int h[maxn][maxn];
PII q[maxm];
bool used[maxn][maxn];
void BFS(int x, int y, bool &has_lower, bool &has_higher) {
    int hh = 0, tt = -1;
    q[ ++ tt] = {x, y};
    used[x][y] = true;
    while (hh <= tt) {
        PII t = q[hh ++ ];
        for (int i = t.x - 1; i <= t.x + 1; ++ i)
            for (int j = t.y - 1; j <= t.y + 1; ++ j) {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (h[i][j] != h[t.x][t.y]) {
                    if (h[i][j] > h[t.x][t.y])
                        has_higher = true;
                    else
                        has_lower = true;
                }
                else if (!used[i][j]) {
                    q[ ++ tt] = {i, j};
                    used[i][j] = true;
                }
            }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            scanf("%d", &h[i][j]);
    // 山峰，山谷
    int peak = 0, valley = 0;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            if (!used[i][j]) {
                bool has_higher = false, has_lower = false;
                BFS(i, j, has_lower, has_higher);
                if (!has_lower)
                    valley ++ ;
                if (!has_higher)
                    peak ++ ;
            }
    printf("%d %d\n", peak, valley);
    return 0;
}
