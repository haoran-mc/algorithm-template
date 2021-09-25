#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define bug printf("<-->\n");
#define lowbit(x) ((x) & -(x)) //lowbit(ob0010) = 2
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
#define NEXTLINE puts("");
#define pb push_back
#define LINF LLONG_MAX
#define IOS ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define int long long
// const int maxp = 1010;    //点的数量
// const int maxn = <++>;
const int INF    = 0x3f3f3f3f;
const ll  INF_LL = 0x3f3f3f3f3f3f3f3fLL;
// const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const double PI = acos(-1.0);
const double eps = 1e-6;
const double gold = (1 + sqrt(5)) / 2; //黄金分割 = 1.61803398...
priority_queue<int, vector<int>, less<int>> pqu_int; /*默认是less，即数字大的优先级高*/

void clear(queue<int>& q) {
    queue<int> empty;
    swap(empty, q);
}

inline int sigma(char c) {return c - 'a';};

inline int sgn(double x) { //判断x是否等于0
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

inline int dcmp(double x, double y) { //比较两个浮点数：0 相等；-1 小于；1 大于
    if (fabs(x - y) < eps) return 0;
    else return x < y ? -1 : 1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}
    bool operator == (const Point _point) {return sgn(x - _point.x) == 0 && sgn(y - _point.y) == 0;}
};

inline double dis(Point p1, Point p2) {return hypot(p1.x-p2.x, p1.y-p2.y);}

template <typename T>
T Smax(T x) {return x;}
template<typename T, typename... Args>
T Smax(T a, Args... args) {
    return _max(a, Smax(args...));
}
template <typename T>
T Smin(T x) {return x;}
template<typename T, typename... Args>
T Smin(T a, Args... args) {
    return _min(a, Smin(args...));
}

void solve() {
    ;//<++>
}

int main() {
    // signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    solve();
    return 0;
}
