#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e4; //顶点比1e3少的话，就可以使用邻接矩阵
int n, m; //顶点的个数
int vert[maxn], edge[maxn], nxet[maxn], head[maxn], tot;
bool used[maxn];

//加入有向边(x, y)，权值为z
void add(int x, int y, int z) {
    vert[++tot] = y;
    edge[tot]   = z;
    nxet[tot]   = head[x];
    head[x] = tot;
}

void BFS() {
    queue<int> quu;
    quu.push(0);
    used[0] = true;
    while (!quu.empty()) {
        int x = quu.front();
        printf("%d\n", x);
        quu.pop();
        for (int i = head[x]; i; i = nxet[i]) {
            int y = vert[i];
            if (used[y]) continue;
            quu.push(y);
            used[y] = true;
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    BFS();
    return 0;
}
