/*----------------------------------------------------------------
 * 文件名称：最大不相交区间数量.cpp
 * 创建日期：2021年11月02日 星期二 19时46分23秒
 * 题 目：AcWing 0908 最大不相交区间数量
 * 算 法：区间贪心
 * 描 述：给定 n 个区间 li, ri，请你在数轴上选择若干个区间，
 * 使得选中的区间之间互不相交（包括端点）。输出可选区间的最大数量。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Range {
	int l, r;
	bool operator < (const Range & R) const {
		return r < R.r;
	}
} range[maxn];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
		scanf("%d %d", &range[i].l, &range[i].r);
	sort(range, range + n);
	int res = 0, ed = -INF;
	for (int i = 0; i < n; ++ i)
		if (range[i].l > ed) {
			res ++ ;
			ed = range[i].r;
		}
	printf("%d\n", res);
	return 0;
}
