/*----------------------------------------------------------------
 * 3 * 文件名称：区间选点.cpp
 * 创建日期：2021年11月02日 星期二 14时16分53秒
 * 题 目：AcWing 0905 区间选点
 * 算 法：贪心 区间问题
 * 描 述：给定 n 个区间 li, ri，请你在数轴上选择尽量少的点，使得
 * 每个区间内至少包含一个选出的点，输出选择的点的最小数量。
 * 位于区间端点上的点也算作区间内。
 *
 ----------------------------------------------------------------*/

/**
 * |-----------| |------------------|
 * ---------------x--------------------x---------------------------->
 * |----------------| |--------|
 * |------|
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Range {
	int l, r;
	bool operator < (const Range &R) const {
		return r < R.r;
	}
} range[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		int l, r;
		scanf("%d %d", &l, &r);
		range[i] = {l, r};
	}
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
