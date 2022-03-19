/*----------------------------------------------------------------
 * 文件名称：06-高精度乘法.cpp
 * 创建日期：2021年08月06日 星期五 16时25分58秒 
 * 题 目：AcWing 0793 高精度乘法 
 * 算 法：高精度乘法
 * 描 述：给定两个非负整数(不含前导 0) A 和 B，计算 A * B 
 * 使用了string输入乘数，其实也可以使用数组存储，代码改一下就可以了 
 *
 * 模板化就模板化吧，挺简洁的
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define NEXTLINE cout << endl;
// C = A * b, A >= 0, b >= 0
vector<int> mul(vector<int>& A, int b) {
	vector<int> C;
	// 太模板化了，可以拆开写，结束条件是 i < A.size()
	// 这时 t 可能不为0，那就写一个while (t) {c.pb(t % 10); t /= 10}
	for (int i = 0, t = 0; i < A.size() || t; ++i) {
		if (i < A.size()) // 这句要要相应的改
			t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	// 去除前导零
	while (C.size() > 1 && C.back() == 0)
		C.pop_back();
	return C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string n1;
	int b;
	cin >> n1 >> b;
	vector<int> A;
	// vector 推入的第一个位置是个位
	for (int i = n1.length() - 1; i >= 0; --i)
		A.push_back(n1[i] - '0');
	auto C = mul(A, b);
	for (int i = C.size() - 1; i >= 0; --i)
		cout << C[i];
	NEXTLINE;
	return 0;
}
