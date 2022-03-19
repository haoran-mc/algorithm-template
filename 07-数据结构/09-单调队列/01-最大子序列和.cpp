/*----------------------------------------------------------------
 *
 *   文件名称：02-最大子序列和.cpp
 *   创建日期：2021年04月08日 ---- 21时02分
 *   题    目：ch1201
 *   算    法：单调队列
 *   描    述：给定一个长度为N的整数序列(可能有负数)，从中找出一段
 *      长度不超过M的连续子序列，使得所有子序列中所有数的和最大
 *
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 5;
int sum[maxn];
int quu[maxn];
int head = 0;
int tail = 0;
int res;

int main() {
    // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sum[i]);
        if (i)
            sum[i] += sum[i-1];
    }
    for (int i = 0; i < n; ++i) {
        while (head <= tail && i-quu[i] > m) //超出M的范围
            ++head;
        res = max(res, sum[i] - sum[quu[head]]);
        //为了保证队列单调，要使quu[tail]的位置的前缀和小于sum[i]才行
        while (head <= tail && sum[i] <= sum[quu[tail]])
            --tail;
        quu[++tail] = i;
    }
    printf("%d\n", res);
    return 0;
}
