#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e4; //顶点数比1e3少的话，就可以使用邻接矩阵
int n, m;							//顶点的个数，边的个数
vector<int> g[maxn]; //邻接矩阵与邻接表都使用一个变量名，好记
bool used[maxn];		 // DFS搜索需要标记已访问过的顶点

void DFS(int vertex)
{
	used[vertex] = true;
	for (int i = 0; i < (int)g[vertex].size(); ++i) {
		int vert = g[vertex][i];
		if (used[vert] == false)
			DFS(vert);
	}
}
int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int ver1, ver2;
		scanf("%d %d", &ver1, &ver2);
		g[ver1].push_back(ver2);
	}
	for (int i = 0; i < n; ++i)
		if (used[i] == false)
			DFS(i);
	return 0;
}
