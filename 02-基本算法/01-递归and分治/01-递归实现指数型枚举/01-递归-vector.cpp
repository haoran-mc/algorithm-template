/*----------------------------------------------------------------
 * 文件名称：01.cpp
 * 创建日期：2021年05月11日 ---- 15时10分
 * 题 目：AcWing 92 递归实现指数型枚举
 * 算 法：递归
 * 描 述：从 [1, n]这n（n < 20）个整数中随机选取任意多个
 * 输出所有可能的选择方案，每个方案的数按升序输出
 ----------------------------------------------------------------*/
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> vec;

void DFS(int x) {
    if (x == n + 1) {
        for (auto i : vec)
            printf("%d ", i);
        puts("");
        return;
    }
    DFS(x + 1);       // 不选择 x
    vec.push_back(x); // 选择 x
    DFS(x + 1);       // 选择 x
    vec.pop_back();   // 回溯
}

int main() {
    scanf("%d", &n);
    DFS(1); // 决策数字1
    return 0;
}
