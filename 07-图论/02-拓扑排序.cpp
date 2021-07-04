#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
int head[maxn], vert[maxn], nxet[maxn], edge[maxn], tot;
int deg[maxn];
int sequ[maxn], cnt;

void add(int x, int y) {
    vert[++tot] = y;
    nxet[tot] = head[x];
    head[x] = tot;
    ++deg[y];
}

void topSort() {
    queue<int> quu;
    for (int i = 0; i < n; ++i)
        if (!deg[i])
            quu.push(i);
    while (!quu.empty()) {
        int x = quu.front();
        quu.pop();
        sequ[cnt++] = x;
        for (int i = head[x]; i; i = nxet[i]) {
            int y = vert[i];
            if (!--deg[y])
                quu.push(y);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        add(x, y);
    }
    topSort();
    for (int i = 0; i < cnt; ++i)
        printf("%d ", sequ[i]);
    cnt == n ? printf("无环\n") : printf("无环\n");
    return 0;
}
