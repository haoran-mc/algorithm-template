#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e4; //顶点比1e3少的话，就可以使用邻接矩阵
int n; //顶点的个数
//没有边权
vector<int> g[maxn];
bool inq[maxn]; //当前在队列中的顶点

void BFS(int vertex) {
    queue<int> quu;
    quu.push(vertex);
    inq[vertex] = true;
    while (!quu.empty()) {
        int vert = quu.front();
        quu.pop();
        for (int i = 0; i < (int)g[vert].size(); ++i) {
            int v = g[vert][i];
            if (inq[v] == false) {
                quu.push(v);
                inq[v] = true;
            }
        }
    }
}

int main() {
    //一般图为连通图，那么只需要一次广搜遍历就行了
    //如果为非连通图，需要检查每一个顶点
    for (int i = 0; i < n; ++i)
        if (inq[i] == false)
            BFS(i);
    return 0;
}
