/*----------------------------------------------------------------
 *
 *   文件名称：二叉堆向下调整.cpp
 *   创建日期：2021年03月03日 ---- 10时06分
 *   算    法：堆
 *   描    述：建堆有两种方式，当前程序是使用向下调整建堆
 *   1. 输入是从第n位到第1位的
 *   2. 每输入一位就向下调整，down(i)
 *   3. 判断当前结点与两个儿子结点最大的放在当前位置
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100;
int n = 10;
int heap[maxn];
#define bug printf("<------>\n");

void down(int idx) {
    while (idx * 2 <= n) {
        int newidx = idx * 2;
        if (newidx + 1 <= n && heap[newidx + 1] > heap[newidx])
            newidx++;
        if (heap[newidx] <= heap[idx])
            break;
        swap(heap[idx], heap[newidx]);
        idx = newidx;
    }
}

void buildHeap() {
    for (int i = n; i >= 1; i--) {
        scanf("%d", &heap[i]);
        down(i);
    }
}

void getTop() {
    printf("%d\n", heap[1]);
}

void del() {
    printf("%d ", heap[1]);
    swap(heap[1], heap[n]);
    --n;
    down(1);
}

void preorder(int idx) {
    if (idx <= n) {
        printf("%d ", heap[idx]);
        preorder(2 * idx);
        preorder(2 * idx + 1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    buildHeap();
    for (int i = 0; i < 10; ++i)
        del();
    return 0;
}

