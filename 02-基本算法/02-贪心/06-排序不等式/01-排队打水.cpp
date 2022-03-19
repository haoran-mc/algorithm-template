/*----------------------------------------------------------------
 * 文件名称：排队打水.cpp
 * 创建日期：2021年11月02日 星期二 23时49分52秒
 * 题 目：AcWing 0913 排队打水
 * 算 法：排序不等式
 * 描 述：有 n 个人排队到 1 个水龙头处打水，第 i 个人装满水桶
 * 所需时间是 ti，请问如何安排他们的打水顺序才能使所有人的等待时间
 * 之和最小
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int t[maxn];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
		scanf("%d", &t[i]);
	sort(t, t + n);
	ll res = 0;
	for (int i = 0; i < n; ++ i)
		res += t[i] * (n - i - 1);
	printf("%lld\n", res);
	return 0;
}
