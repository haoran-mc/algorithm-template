/*----------------------------------------------------------------
 *   
 *   文件名称：模拟堆.cpp
 *   创建日期：2021年08月09日 星期一 10时41分38秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int he[maxn], tot;
int ph[maxn], hp[maxn];

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(he[a], he[b]);
}

void down(int u) {
    int minidx = u;
    if (u * 2 <= tot && he[u * 2] < he[minidx])
        minidx = u * 2;
    if (u * 2 + 1 <= tot && he[u * 2 + 1] < he[minidx])
        minidx = u * 2 + 1;
    if (u != minidx) {
        heap_swap(u, minidx);
        down(minidx);
    }
}

void up(int u) {
    while (u / 2 && he[u / 2] > he[u]) {
        heap_swap(u / 2, u);
        u /= 2;
    }
}

int main() {
    int n; scanf("%d", &n);
    int m = 0;
    while (n--) {
        char op[10];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            tot++;
            m++;
            ph[m] = tot, hp[tot] = m;
            he[tot] = x;
            up(tot);
        }
        else if (!strcmp(op, "PM"))
            printf("%d\n", he[1]);
        else if (!strcmp(op, "DM")) {
            heap_swap(1, tot);
            tot--;
            down(1);
        }
        else if (!strcmp(op, "D")) {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, tot);
            tot--;
            down(k), up(k);
        }
        else {
            scanf("%d %d", &k, &x);
            k = ph[k];
            he[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}
