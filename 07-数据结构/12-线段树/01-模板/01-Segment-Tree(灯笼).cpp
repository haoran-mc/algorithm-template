/*----------------------------------------------------------------
 * 文件名称：Segment_Tree.cpp
 * 创建日期：2021年04月23日 ---- 21时06分 
 * 题 目：<++>
 * 算 法：线段树 
 * 描 述：线段树结点中没有存储区间，但由于build, update, query
 * 操作的参数都包含了start与end，所以相当于存储了区间 
 *
 ----------------------------------------------------------------*/
#include <cstdio>
using namespace std;
const int maxn = 1000;
int arr[] = {1, 3, 5, 7, 9, 11};
int tree[maxn];
int n = 6; //数组中元素的个数
// build(0, 0, n-1)，从根节点开始建树，从arr数组的start到end，node是树的结点
void build(int node, int start, int end) {
    if (start == end)
        tree[node] = arr[start];
    else {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build(left_node, start, mid);
        build(right_node, mid+1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}
// update(0, 0, n-1, idx, val)，arr[idx] = val
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
    }
    else {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (idx <= mid)
            update(left_node, start, mid, idx, val);
        else
            update(right_node, mid+1, end, idx, val);
        tree[node] = tree[left_node] + tree[right_node];
    }
}
// query(0, 0, n-1, L, R)，求arr[L], arr[L+1], ... arr[R]之间的和
int query(int node, int start, int end, int L, int R) {
    printf("start = %d\n", start);
    printf("end = %d\n", end);
    if (R < start || L > end)
        return 0;
    else if (L <= start && R >= end)
        return tree[node];
    else if (start == end)
        return tree[node];
    else {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        int sum_left = query(left_node, start, mid, L, R);
        int sum_right = query(right_node, mid+1, end, L, R);
        return sum_left + sum_right;
    }
}
int main() {
    build(0, 0, n-1);
    for (int i = 0; i <= 2*n+2; ++i)
        printf("tree[%d] = %d\n", i, tree[i]);
    printf("\n");
    update(0, 0, n-1, 4, 6);
    for (int i = 0; i <= 2*n+2; ++i)
        printf("tree[%d] = %d\n", i, tree[i]);
    printf("\n");
    int s = query(0, 0, n-1, 2, 5);
    printf("%d\n", s);
    return 0;
}
