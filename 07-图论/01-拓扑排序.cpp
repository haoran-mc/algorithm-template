#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e6 + 5;
vector<int> g[maxn];
int n, m;
int indegree[maxn];

bool topSort() {
    int cnt = 0; /*记录加入拓扑排序的顶点数*/
    queue<int> quu;
    for (int i = 0; i < n; ++i)
        if (!indegree[i])
            quu.push(i);
    while (!quu.empty()) {
        int vert = quu.front();
        ++cnt;
        printf("%d ", vert);
        quu.pop();
        for (int i = 0; i < (int)g[vert].size(); ++i) {
            int j = g[vert][i];
            --indegree[j];
            if (!indegree[j])
                quu.push(j);
        }
    }
    return cnt == n ? true : false;
}

int main() {
    printf("%d\n", topSort());
    return 0;
}
