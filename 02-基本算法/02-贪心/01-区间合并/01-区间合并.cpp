/*----------------------------------------------------------------
 * 文件名称：02-lhr.cpp
 * 创建日期：2021年10月27日 星期三 22时32分21秒
 * 题 目：AcWing 0803 区间合并
 * 算 法：区间合并
 * 描 述：<++>
 ----------------------------------------------------------------*/
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
#define bug printf("<-->\n");
const int INF = 0x3f3f3f3f;
vector<PII> segs; // pair在C++中优先以左端点排序
// segment, section, sequence
// const int maxn = 1e5 + 5;
// 将含有交集的区间合并[1, 5] [4, 8] --> [1, 8]
void merge(vector<PII> &segs) {
	// for循环无法将最后一个区间添加到结果容器中
	// 加上这一句，就可以使最后一个区间添加到结果容器中
	segs.push_back({INF, INF});
	vector<PII> res;
	sort(segs.begin(), segs.end());
	int st = segs[0].first,
			ed = segs[0].second;
	for (auto seg : segs) {
		// printf("%d %d\n", seg.first, seg.second);
		if (ed >= seg.first)
			ed = max(ed, seg.second);
		else {
			res.push_back({st, ed});
			st = seg.first,
				 ed = seg.second;
		}
	}
	segs = res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		segs.push_back({l, r});
	}
	merge(segs);
	printf("%d\n", (int)segs.size());
	/*
	 * for (auto seg : segs)
	 * printf("%d %d\n", seg.first, seg.second);
	 */
	return 0;
}
