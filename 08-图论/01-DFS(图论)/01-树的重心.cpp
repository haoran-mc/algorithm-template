/*----------------------------------------------------------------
 * 文件名称：树的重心.cpp
 * 创建日期：2021年10月07日 星期四 15时58分34秒 
 * 题 目：AcWing 0846 树的重心
 * 算 法：图论 DFS
 * 描 述：
 * 重心定义：重心是指树中的一个结点，
 * 重心是指树中的一个结点如果将这个点删除后，
 * 剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。
 *
 ----------------------------------------------------------------*/
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 5; // 无向图，所以乘2
int h[maxn], e[maxn], ne[maxn], idx;
int n;
bool used[maxn];
int res = maxn;
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
// 以u为根的子树中点的数量
int DFS(int u)
{
	used[u] = true;
	int self = 1, max_part = 0;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!used[j]) {
			int s = DFS(j);
			max_part = max(max_part, s);
			self += s;
		}
	}
	max_part = max(max_part, n - self);
	res = min(res, max_part);
	return self;
}
int main()
{
	memset(h, -1, sizeof h);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		add(a, b), add(b, a);
	}
	DFS(1);
	printf("%d\n", res);
	return 0;
}
