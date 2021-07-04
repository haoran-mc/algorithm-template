#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
int n, m;
int source;
int tot;
int head[N];
int vert[M];
int edge[M];
int nxet[M];
int dist[N];
bool used[N];
queue<int> quu;

void add(int x, int y, int z) {
    /*输入的第tot条边的入边是y，权重为z*/
    vert[++tot] = y;
    edge[tot] = z;
    /*nxet数组中存放上一次输入x时的tot值*/
    /*第一次输入x时，nxet[tot] == 0，也是下面循环结束的依据*/
    nxet[tot] = head[x];
    head[x] = tot;
}

void spfa() {
    memset(dist, 0x3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    dist[source] = 0;
    used[source] = true;
    quu.push(source);
    while (quu.size()) {
        /*取出队首元素*/
        int x = quu.front();
        quu.pop();
        used[x] = 0;
        /*扫描所有出边*/
        for (int i = head[x]; i; i = nxet[i]) {
            int y = vert[i];
            int z = edge[i];
            if (dist[y] > dist[x] + z) {
                dist[y] = dist[x] + z;
                if (used[y] == false)
                    quu.push(y),
                    used[y] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
    }
    spfa();
    for (int i = 0; i < n; ++i)
        printf("%d\n", dist[i]);
    return 0;
}
