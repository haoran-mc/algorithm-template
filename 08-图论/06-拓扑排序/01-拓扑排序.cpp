/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年07月29日 星期四 00时43分56秒
 *   题    目：AcWing 0848 有向图的拓扑序列
 *   算    法：拓扑
 *   描    述：拓扑序在队列中，
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;

int n, m;
int h[maxn], ve[maxn], ne[maxn], tot;
int quu[maxn], degree[maxn];   // 一个点的入度数

// ve[]存储结点，ne[]存储下一个结点，是一个指针，h[]是头结点
void add(int a, int b) {
    ve[tot] = b, ne[tot] = h[a], h[a] = tot++;
}
/*
 * 把当前入度为0的点加入到队列，并把这个点指向的点入度减一
 * 因为我们把这个点放入队列了，自然要把这个点的所有连线删除，故指向的点入度减一
 * 这时又会生成入度为0的点，继续上述操作
 */
bool topsort() {
    int hh = 0, tt = 0;
    // 遍历每个点的入度，因为题目规定了点是[1, n]，所以for循环遍历[1, n]
    // 把入度为0的点添加到队列中
    for (int i = 1; i <= n; ++i)
        if (!degree[i])
            quu[tt++] = i;

    while (hh < tt) {
        int x = quu[hh++];  // 将已找到的入度为0的点指向的点入度减一

        for (int i = h[x]; i != -1; i = ne[i]) {
            int j = ve[i];
            degree[j]--;
            if (degree[j] == 0)
                quu[tt++] = j;
        }
    }
    return tt == n;   // 如果队列中添加过n个点，说明是拓扑图
}

int main() {
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);   // 这条链表的最后一个是-1
    for (int i = 0; i < m; ++i) {
        int ve1, ve2;
        scanf("%d %d", &ve1, &ve2);
        add(ve1, ve2);
        degree[ve2]++;
    }
    if (topsort()) {  // 队列中的点还在数组中
        for (int i = 0; i < n; ++i)
            printf("%d ", quu[i]);
        puts("");
    }
    else
        puts("-1\n");
    return 0;
}
