#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 10005;
int cnt; // 强连通分量的个数
int low[maxn];
int num[maxn];
int dfn;
int sccno[maxn];
int stack[maxn];
int top; // 用stack[]处理栈，top是栈顶
vector<int> g[maxn];

void dfs (int u) {
    stack[top++] = u; //u进栈
    low[u] = num[u] = ++dfn;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!num[v]) {            //未访问过的点，继续dfs
            dfs(v);               //dfs的最底层，是最后一个SCC
            low[u] = min(low[v], low[u]);
        }
        else if (!sccno[v])       //处理回退边
            low[u]= min(low[u], num[v]);
    }
    if (low[u] == num[u]) {       //栈底的点是SCC的祖先，它的low = num
        cnt++;
        while (1) {
            int v = stack[--top]; //v弹出栈
            sccno[v] = cnt;
            if (u == v)           //栈底的点是SCC的祖先
                break;
        }
    }
}

void Tarjan (int n) {
        cnt = top = dfn = 0;
        memset(sccno, 0, sizeof(sccno));
        memset(num, 0, sizeof(num));
        memset(low, 0, sizeof(low));
        for (int i = 1; i <= n; ++i)
            if (!num[i])
                dfs(i);
}

int main() {
    int n, m, u, v;
    while(scanf("%d %d", &n, &m), n != 0 || m != 0) {
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
        }
        Tarjan(n);
        printf("%s\n", cnt == 1 ? "Yes" : "No" );
    }
    return 0;
}
