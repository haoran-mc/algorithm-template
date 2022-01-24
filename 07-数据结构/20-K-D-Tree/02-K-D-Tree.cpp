/*----------------------------------------------------------------
 *
 *   文件名称：01-K-D-Tree.cpp
 *   创建日期：2021年04月24日 ---- 12时05分
 *   题    目：luogu p4357 k远点对
 *   算    法：K-D tree  对顶堆
 *   描    述：k远点对问题
 *      堆中有k个元素，最小的就是第k远的
 *      缺点，起始下标是1
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <queue>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int inf  = 0x3f3f3f3f;
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
bool opt;
int n, k;
int lc[maxn<<1], rc[maxn<<1], cnt;
int L[maxn], R[maxn], D[maxn], U[maxn];
priority_queue<ll> pqu; //默认数字大的优先级高

inline ll squ(int x) {return 1ll * x * x;}
struct Point{int x, y;} p[maxn], d[maxn << 1];
inline bool cmp(Point a, Point b) {return opt ? a.x < b.x : a.y < b.y;}
inline ll dist(Point a, Point b) {return squ(a.x-b.x) + squ(a.y-b.y);}
inline ll f(Point a, int b) {
    return _max(squ(a.x-L[b]), squ(a.x-R[b])) + _max(squ(a.y-D[b]), squ(a.y-U[b]));
}

void maintain(int idx) {
    L[idx] = R[idx] = d[idx].x;
    D[idx] = U[idx] = d[idx].y;
    if (lc[idx])
        L[idx] = min(L[idx], L[lc[idx]]), R[idx] = max(R[idx], R[lc[idx]]),
            D[idx] = min(D[idx], D[lc[idx]]), U[idx] = max(U[idx], U[lc[idx]]);
    if (rc[idx])
        L[idx] = min(L[idx], L[rc[idx]]), R[idx] = max(R[idx], R[rc[idx]]),
            D[idx] = min(D[idx], D[rc[idx]]), U[idx] = max(U[idx], U[rc[idx]]);
}

/*方差*/
bool va(int l, int r) {
    double avx = 0, avy = 0, vax = 0, vay = 0;  // average variance
    for (int i = l; i < r; ++i)
        avx += p[i].x, avy += p[i].y;
    avx /= (double)(r - l);  //横坐标平均值
    avy /= (double)(r - l);  //纵坐标平均值
    for (int i = l; i < r; ++i)
        vax += (p[i].x - avx) * (p[i].x - avx),  // 方差(x) = vax / (r - l + 1);
            vay += (p[i].y - avy) * (p[i].y - avy);  // 方差(y) = vay / (r - l + 1);
    return vax >= vay;
}

/*d数组是输入的点的dfs序*/
void build(int L, int R, int &x) {
    if (L > R) return;
    x = ++cnt;
    int mid = (L+R) >> 1;
    opt = va(L, R);//或者opt=rand()%2,或者轮换维度切割也好
    nth_element(p+L, p+mid, p+R+1, cmp);
    d[x] = p[mid];
    build(L, mid-1, lc[x]);
    build(mid+1, R, rc[x]);
    maintain(x);
}

/*查找离下标idx最近的点*/
void query(int i, int idx) {
    ll distl = -inf, distr = -inf;
    if (lc[i]) distl = f(p[idx], lc[i]);
    if (rc[i]) distr = f(p[idx], rc[i]);
    ll di = dist(p[idx], d[i]);
    if (-pqu.top() < di) {
        pqu.pop();
        pqu.push(-di);
    }
    if (distl > distr) {
        if (-pqu.top() < distl) query(lc[i], idx);
        if (-pqu.top() < distr) query(rc[i], idx);
    }
    else {
        if (-pqu.top() < distr) query(rc[i], idx);
        if (-pqu.top() < distl) query(lc[i], idx);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    srand(time(NULL));
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &p[i].x, &p[i].y);
    //距离是相对的，对于两个点会有两个同样的距离
    //所有距离都比较一遍，则会出现第k大的距离
    for (int i = 0; i < 2*k; ++i)
        pqu.push(0);
    build(1, n, lc[0]);
    for (int i = 1; i <= n; ++i)
        query(1, i);
    printf("%lld\n", -pqu.top());
    return 0;
}
