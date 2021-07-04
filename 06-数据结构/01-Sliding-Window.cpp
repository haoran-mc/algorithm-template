/*----------------------------------------------------------------
 *
 *   文件名称：01-单调队列.cpp
 *   创建日期：2021年04月01日 ---- 19时33分
 *   题    目：poj2823 Sliding Window
 *   算    法：单调队列
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e6 + 5;
int arr[maxn];
int quu[maxn];
int n, k;

/*
 * 所以队列是递增的，队头是最小值
 * 队列中存储的是下标
 * 如果下一个元素比队列中的小或者相等，那么队尾出队，也就是--tail
 */
void getmin() {
    int head = 0;
    int tail = 0;
    // 先处理前k-1个
    for (int i = 1; i < k; ++i) {
        while (tail >= head && arr[i] <= arr[quu[tail]])
            --tail;
        quu[++tail] = i;
    }
    for (int i = k; i <= n; ++i) {
        while (tail >= head && arr[i] <= arr[quu[tail]])
            --tail;
        quu[++tail] = i;
        while (quu[head] <= i - k)
            ++head;
        printf("%d ", arr[quu[head]]);
    }
    printf("\n");
}

/*与上一个函数一个板子，只是这个队列是递减的*/
void getmax() {
    int head = 0;
    int tail = 0;
    for (int i = 1; i < k; ++i) {
        while (tail >= head && arr[i] >= arr[quu[tail]])
            --tail;
        quu[++tail] = i;
    }
    for (int i = k; i <= n; ++i) {
        while (tail >= head && arr[i] >= arr[quu[tail]])
            --tail;
        quu[++tail] = i;
        while (quu[head] <= i - k)
            ++head;
        printf("%d ", arr[quu[head]]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    getmin();
    getmax();
    return 0;
}
