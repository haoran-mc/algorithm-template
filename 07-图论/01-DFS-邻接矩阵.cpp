#include <cstdio>
#include <cstring>
const int maxn = 1000; /*顶点数再多就不再建议使用邻接矩阵了*/
int n, m; /*分别是顶点个数，边的个数*/
int g[maxn][maxn];
bool used[maxn]; /*DFS搜索需要标记已访问过的顶点*/

void DFS(int vert, int depth) {
    printf("%d ", vert);
    used[vert] = true; /*将已访问过的顶点标记为已被访问*/
    for (int i = 0; i < n; ++i)
        /*邻接矩阵初始化时就需要初始化为无穷大*/
        /*所以也就是在这里判断是否是未输入的边*/
        if (used[i] == false && g[vert][i])
            DFS(i, depth + 1);
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; ++i) {
        int ver1;
        int ver2;
        scanf("%d %d", &ver1, &ver2);
        g[ver1][ver2] = 1;
        g[ver2][ver1] = 1;
    }
    /*遍历图需要搜索每个顶点，首先需要判断是否已经访问*/
    for (int i = 0; i < n; ++i)
        if (used[i] == false)
            DFS(i, 1); /*1表示第一层*/
    return 0;
}
