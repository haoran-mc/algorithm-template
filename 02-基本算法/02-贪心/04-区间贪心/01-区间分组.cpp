/*----------------------------------------------------------------
 * 文件名称：区间分组.cpp
 * 创建日期：2021年11月02日 星期二 22时09分42秒
 * 题 目：AcWing 0906 区间分组
 * 算 法：区间贪心
 * 描 述：给定 n 个区间，请你将这些区间分成若干组，使得每组内部
 * 的区间两两之间（包括端点）没有交集，并使得组数尽可能小
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;

struct Range {
	int l, r;
	bool operator < (const Range R) const {
		return l < R.l;
	}
} range[maxn];

int main() {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; ++ i)
		scanf("%d %d", &range[i].l, &range[i].r);

	sort(range, range + n);
	// 小根堆，存放的是每组里最右端点
	priority_queue<int, vector<int>, greater<int>> heap;

	for (int i = 0; i < n; ++ i) {
		if (heap.empty() || heap.top() >= range[i].l)
			heap.push(range[i].r);
		else {
			// int t = heap.top();
			heap.pop();
			heap.push(range[i].r);
		}
	}
	printf("%d\n", heap.size());
	return 0;
}
