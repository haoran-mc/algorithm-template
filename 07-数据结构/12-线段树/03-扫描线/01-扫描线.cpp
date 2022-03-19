/*----------------------------------------------------------------
 * 文件名称：扫描线.cpp
 * 创建日期：2021年11月10日 星期三 17时41分18秒 
 * 题 目：AcWing 0247 亚特兰蒂斯 
 * 算 法：扫描线 
 * 描 述：n个矩形，每个输入为 x1, y1, x2, y2，矩形左上，右下 
 * 坐标，输出总面积 
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
struct Segment {
    double x, y1, y2;
    int k; // 权值 +1, -1
    bool operator< (const Segment &a) const {
        return x < a.x;
    }
} seg[maxn * 2];
struct Node {
    int l, r;
    int cnt;

    double len;
} tr[maxn * 2 * 4];
vector<double> ys; // 对纵坐标离散化
// 离散化后通过这个函数找到位置
int find(double y) {
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}
void pushup(int u) {
    if (tr[u].cnt)
        tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    else if (tr[u].l != tr[u].r) {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    }
    else
        tr[u].len = 0;
}
void build(int u, int l, int r) {
    tr[u] = {l, r, 0, 0};
    if (l != r) {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}
void modify(int u, int l, int r, int k) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].cnt += k;
        pushup(u);
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, k);
        if (r > mid)
            modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}
int main() {
    int n, t = 1;
    while (scanf("%d", &n), n) {
        ys.clear();
        for (int i = 0, idx = 0; i < n; ++ i) {
            double x1, y1, x2, y2;
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            seg[idx ++ ] = {x1, y1, y2, 1};
            seg[idx ++ ] = {x2, y1, y2, -1};
            ys.push_back(y1), ys.push_back(y2);
        }
        // 去重模板
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        build(1, 0, ys.size() - 2);
        sort(seg, seg + n * 2);
        double res = 0;
        for (int i = 0; i < n * 2; ++ i) {
            if (i > 0) // 从第二条线开始加
                res += tr[1].len * (seg[i].x - seg[i - 1].x);
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        }
        printf("Test case #%d\n", t ++ );
        printf("Total explored area: %.2lf\n\n", res);
    }

    return 0;
}
