/*----------------------------------------------------------------
 *
 *   文件名称：P1596[USACO10OCT]Lake Counting.cpp
 *   创建日期：2020年11月18日 ---- 21时03分
 *   题    目：luogu
 *   算    法：深度优先搜索
 *   描    述：算法课上的代码
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
const int maxn = 101;
char water[maxn][maxn];
int puddle = 0;
vector<int> vec;
int dirx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool vis[maxn][maxn];

bool judge(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    return true;
}

void DFS(int nowX, int nowY, int &size) {
    vis[nowX][nowY] = true;
    for (int i = 0; i < 8; ++i)
        if (water[nowX+dirx[i]][nowY+diry[i]] == 'W' && judge(nowX+dirx[i], nowY+diry[i]) && !vis[nowX+dirx[i]][nowY+diry[i]])
            DFS(nowX+dirx[i], nowY+diry[i], ++size);

    return ;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    scanf("%d", &m);
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            scanf("%c", &water[i][j]);
        getchar();
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (water[i][j] == 'W' && !vis[i][j]) {
                int size = 0;
                DFS(i, j, ++size);
                ++puddle;
                vec.push_back(size);
            }
    printf("%d ", puddle);
    sort(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); ++it)
        it == vec.end() - 1 ? printf("%d", *it) : printf("%d ", *it);

    /*
     *printf("\n");
     *for (int i = 1; i <= n; ++i) {
     *    for (int j = 1; j <= m; ++j) {
     *        printf("%d", vis[i][j]);
     *    }
     *    printf("\n");
     *}
     */
    return 0;
}
