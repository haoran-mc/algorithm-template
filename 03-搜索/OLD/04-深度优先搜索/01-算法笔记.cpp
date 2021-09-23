/*----------------------------------------------------------------
 *
 *   文件名称：First.cpp
 *   创建日期：2020年09月09日 ---- 16时35分
 *   题    目：算法笔记
 *             给定N(N < 1e6)个整数(可能有负数)，从中选择K个数，使得这K个数
 *             之和恰好等于一个给定的整数X，如果有多种方案，选择它
 *             们中元素平方和最大的一个，题目保证这样的方案唯一
 *   输    入：N K X
 *             1 2 3 ... N
 *   输    出：i i+1 i+2 i+3 ... i+k
 *   例      ：
 *             输入：4 2 6
 *                   2 3 3 4
 *             输出：2 4
 *   算    法：深度优先搜索
 *   描    述：void DFS(int index, int count, int sum, int sumSquare)
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1e6;
int N;              // 输入的数个数
int K;              // 选择的数个数
int X;              // 选择的数总和
int count = 0;      // 目前已选择的数个数
int idx = 0;        // 存储下标
int sum = 0;        // 目前已选择的数总和
int sumSquare = 0;  // 目前已选择的数平方和
int maxSumSquare;   // 已知最大平方和
int num[maxn];      // 存储输入的数
vector<int> tem;    // 存储当前K个数
vector<int> ans;    // 存储答案

void DFS(int index, int count, int sum, int sumSquare) {
    if (count == K && sum == X) {
        if (sumSquare > maxSumSquare) {
            maxSumSquare = sumSquare;
            ans = tem;
        }
        return ;
    }
    //if (index == N || count == K || sum == X)
    if (index == N || count > K || sum > X)
        return ;
    tem.push_back(num[index]);
    DFS(index + 1, count + 1, sum + num[index], sumSquare + num[index] * num[index]);
    tem.pop_back();
    DFS(index + 1, count, sum, sumSquare);
}

int main() {
    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &X);
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    DFS(idx, count, sum, sumSquare);
    for (auto it = ans.begin(); it != ans.end(); it++)
        printf("%d ", *it);

    printf("\n");
    return 0;
}
