#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1000; /*如果顶点数大于1000，就不再建议使用邻接矩阵*/
int n, m; /*分别是顶点个数，边的个数*/
bool g[maxn][maxn];
bool inq[maxn]; /*当前在队列中的顶点*/

void BFS(int vert) {
    queue<int> quu;
    quu.push(vert);
    inq[vert] = true;
    while (!quu.empty()) {
        int vert = quu.front();
        printf("%d ", vert);
        quu.pop();
        for (int i = 0; i < n; ++i)
            if (inq[i] == false && g[vert][i]) {
                quu.push(i);
                inq[i] = true;
            }
    }
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
    /*一般图为连通图，那么只需要一次广搜遍历就行了*/
    /*如果为非连通图，需要检查每一个顶点*/
    for (int i = 0; i < n; ++i)
        if (inq[i] == false)
            BFS(i);
    return 0;
}
