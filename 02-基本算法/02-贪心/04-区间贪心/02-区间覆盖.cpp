/*----------------------------------------------------------------
 * 文件名称：区间覆盖.cpp
 * 创建日期：2021年11月02日 星期二 20时32分26秒
 * 题 目：AcWing 0907 区间覆盖
 * 算 法：区间贪心
 * 描 述：给定 n 个区间 [li, ri]，以及一个线段区间 [st, ed]，请你
 * 选择尽量少的区间，将指定线段区间完全覆盖，输出最少区间数，如果
 * 无法完全覆盖则输出 -1
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct Range {
	int l, r;
	bool operator < (const Range &R) const {
		return l < R.l;
	}
} range[maxn];
int main() {
	int st, ed;
	scanf("%d %d", &st, &ed);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
		scanf("%d %d", &range[i].l, &range[i].r);
	sort(range, range + n);
	int res = 0;
	bool success = false;
	for (int i = 0; i < n; ++ i) {
		int j = i, r = -INF;
		// 左端点小于 st，右端点最大是 r
		while (j < n && range[j].l <= st) {
			r = max(r, range[j].r);
			j ++ ;
		}
		if (r < st)
			break;
		res ++ ;
		if (r >= ed) {
			success = true;
			break;
		}
		st = r;
		i = j - 1;
	}
	if (!success)
		res = -1;
	printf("%d\n", res);
	return 0;
}
