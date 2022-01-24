/*----------------------------------------------------------------
 * 文件名称：01-全排列.cpp
 * 创建日期：2021年05月12日 星期三 13时44分31秒
 * 题 目：AcWing 0094 递归实现排列型枚举
 * 算 法：递归
 * 描 述：输出 [1, n] 这 n 个数所有可能的排列，不同排列按字典序
 * 较小的先输出
 *
 * 不是很理解
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10;
int n, cnt, arr[maxn];
void DFS(int idx) {
	if (idx == n) {
		for (int i = 0; i < n; ++ i)
			printf("%d ", arr[i]);
		puts("");
		return;
	}
	for (int i = idx; i < n; ++ i) {
		swap(arr[i], arr[idx]);
		DFS(idx + 1);
		swap(arr[i], arr[idx]);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
		arr[i] = i + 1;
	DFS(0);
	return 0;
}
