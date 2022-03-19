/*----------------------------------------------------------------
 * 文件名称：合并果子.cpp
 * 创建日期：2021年11月02日 星期二 22时37分15秒 
 * 题 目：AcWing 00148 合并果子 
 * 算 法：哈夫曼编码 
 * 描 述：把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和 
 * 输出最小消耗的体力。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; ++ i) {
        int weight; scanf("%d", &weight);
        heap.push(weight);
    }
    int res = 0;
    while (heap.size() > 1) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    printf("%d\n", res);
    return 0;
}
