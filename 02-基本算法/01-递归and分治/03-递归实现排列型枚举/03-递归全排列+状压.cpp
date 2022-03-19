/*----------------------------------------------------------------
 * 文件名称：01-全排列.cpp
 * 创建日期：2021年05月12日 星期三 13时44分31秒
 * 题 目：AcWing 0094 递归实现排列型枚举
 * 算 法：递归
 * 描 述：输出 [1, n] 这 n 个数所有可能的排列，不同排列按字典序
 *     较小的先输出
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> vec;
void DFS(int idx, int state) {
	if (idx == n) {
		for (auto i : vec)
			printf("%d ", i);
		puts("");
		return;
	}
	for (int i = 0; i < n; ++ i)
		if (!(state >> i & 1)) {
			vec.push_back(i + 1);
			DFS(idx + 1, state | 1 << i);
			vec.pop_back();
		}
}
int main() {
	scanf("%d", &n);
	DFS(0, 0);
	return 0;
}
