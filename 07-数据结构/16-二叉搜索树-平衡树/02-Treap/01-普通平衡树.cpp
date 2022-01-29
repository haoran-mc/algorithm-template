/*----------------------------------------------------------------
 * 文件名称：普通平衡树.cpp
 * 创建日期：2021年11月18日 星期四 11时16分53秒 
 * 题 目：AcWing 0253 普通平衡树 
 * 算 法：Treap
 * 描 述：
 * 维护一些数：
 * 1. 插入一个数x
 * 2. 删除数值x（若有多个相同的x，只删除一个）
 * 3. 查询数值x的排名（若有多个相同的数，只输出最小的排名）
 * 4. 查询排名为x的数值
 * 5. 求数值x的前驱（前驱定义为小于x的最大的数）
 * 6. 求数值x的后继（后继定义为大于x的最小的数）
 *
 ----------------------------------------------------------------*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct Node {
    int l, r;
    int key;
    int val; // priority
    int cnt; // 结点重复，使用一个结点表示cnt个权值相同的结点
    int size; // 下面子树中有多少个结点，用于计算排名
} tr[maxn];
int root, idx; // 根结点和链表
void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}
/** 右旋
 * x y
 * / \ / \
 * y + -> - x
 * / \ / \
 * - z z +
 */
void zig(int &p) {
    int q = tr[p].l; // 也就是y
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
    pushup(tr[p].r), pushup(p);
}
// 左旋
void zag(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
    pushup(tr[p].l), pushup(p);
}
int get_node(int key) {
    tr[ ++ idx].key = key;

    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}
void build() {
    // 初始化时需要两个哨兵
    get_node(-INF), get_node(INF);
    // 手动创建
    root = 1, tr[1].r = 2;
    pushup(root);
    if (tr[1].val < tr[2].val)
        zag(root);
}
void insert(int &p, int key) {
    if (!p)
        p = get_node(key);
    else if (key == tr[p].key)
        tr[p].cnt ++ ;
    else if (key < tr[p].key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val)
            zig(p);
    }
    else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val)
            zag(p);
    }
    pushup(p);
}
void remove(int &p, int key) {
    if (!p)
        return;
    if (key == tr[p].key) {
        if (tr[p].cnt > 1)
            tr[p].cnt -- ;
        else if (tr[p].l || tr[p].r) {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                zig(p);
                remove(tr[p].r, key);
            }
            else {
                zag(p);
                remove(tr[p].l, key);
            }
        }
        else
            p = 0;
    }
    else if (key < tr[p].key)
        remove(tr[p].l, key);
    else
        remove(tr[p].r, key);
    pushup(p);
}
// 通过数值找排名
int get_rank_by_key(int p, int key) {
    if (!p)
        return 0;
    if (tr[p].key == key)
        return tr[tr[p].l].size + 1;
    else if (key < tr[p].key) {
        return get_rank_by_key(tr[p].l, key);
    }
    else {
        return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key);

    }
}
// 通过排名找数值
int get_key_by_rank(int p, int rank) {
    if (!p)
        return INF;
    if (tr[tr[p].l].size >= rank)
        return get_key_by_rank(tr[p].l, rank);
    else if (tr[tr[p].l].size + tr[p].cnt >= rank)
        return tr[p].key;
    else
        return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}
// 前驱
int get_prev(int p, int key) {
    if (!p)
        return -INF;
    if (key <= tr[p].key)
        return get_prev(tr[p].l, key);
    else
        return max(tr[p].key, get_prev(tr[p].r, key));
}
// 后继
int get_next(int &p, int key) {
    if (!p)
        return INF;
    if (key >= tr[p].key)
        return get_next(tr[p].r, key);
    else
        return min(tr[p].key, get_next(tr[p].l, key));
}
int main() {
    build();
    int n; scanf("%d", &n);
    while (n -- ) {
        int opt, x;
        scanf("%d %d", &opt, &x);
        if (opt == 1) insert(root, x);
        else if (opt == 2) remove(root, x);
        else if (opt == 3) printf("%d\n", get_rank_by_key(root, x) - 1);
        else if (opt == 4) printf("%d\n", get_key_by_rank(root, x + 1));
        else if (opt == 5) printf("%d\n", get_prev(root, x));
        else if (opt == 6) printf("%d\n", get_next(root, x));
    }
    return 0;
}
