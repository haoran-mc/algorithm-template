/*----------------------------------------------------------------
 * 文件名称：货仓选址.cpp
 * 创建日期：2021年11月03日 星期三 20时29分32秒
 * 题 目：AcWing 0104 货仓选址
 * 算 法：贪心
 * 描 述：在一条数轴上有 n 家商店，它们的坐标是 ai
 * 现在需要在数轴上建立一家货仓，货仓建在哪里可以使得货仓到每家
 * 商店的距离之和最小
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int res = 0;
	for (int i = 0; i < n; ++ i)
		res += abs(a[i] - a[n / 2]);
	printf("%d\n", res);
	return 0;
}
