/*----------------------------------------------------------------
 *
 *   文件名称：二叉堆向上调整.cpp
 *   创建日期：2021年03月02日 ---- 23时13分
 *   算    法：堆
 *   描    述：建堆有两种方式，当前程序是使用向上调整建堆
 *   1. 输入heap[i]后，up(i)
 *   2. 从当前结点开始往上，父亲比自己小就交换
 *   3. 排序：需要把将第一位与最后一位交换，然后删除最后一位，或者--n
 *   4. 然后第一位可能不满足堆性质，需要向下调整
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100;
int n = 10;
int heap[maxn];
#define bug printf("<------>\n");

void up(int idx) {
    while (idx > 1 && heap[idx] > heap[idx/2]) {
        swap(heap[idx], heap[idx/2]);
        idx /= 2;
    }
}

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
    for (int i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
        up(i);
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
