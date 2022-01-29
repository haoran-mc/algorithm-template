/*----------------------------------------------------------------
 * 文件名称：02-图的深度优先搜索.cpp
 * 创建日期：2021年04月14日 ---- 19时30分 
 * 题 目：算法竞赛 
 * 算 法：图论，链式前向星 
 * 描 述：<++> 
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
int n, m;
int used[maxn];
int head[maxn], edge[maxn], nxet[maxn], vert[maxn];
int cnt, tot;
//加入有向边(x, y)，权值为z
void add(int x, int y, int z)
{
	vert[++tot] = y;
	edge[tot] = z;
	nxet[tot] = head[x];
	head[x] = tot;
}
void DFS(int x)
{
	used[x] = true;
	for (int i = head[x]; i; i = nxet[i]) {
		int y = vert[i];
		if (used[y])
			continue;
		printf("%d\n", y);
		DFS(y);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			++cnt;
			DFS(i);
		}
	return 0;
}
