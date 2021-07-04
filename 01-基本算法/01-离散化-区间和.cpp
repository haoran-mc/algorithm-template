/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年06月01日 星期二 13时25分21秒
 *   题    目：AcWing 0802 区间和
 *   算    法：离散化
 *   描    述：这个代码质量更高一点
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
// typedef pair<int, int> PII;
using PII = pair<int, int>;
#define pb push_back
#define fi first
#define se second
#define bug printf("<-->\n");
#define NEXTLINE puts("");
const int maxn = 3e5 + 5;
int n, m;
vector<PII> op, query;
vector<int> alls;  //存储所有待离散化的值
int I[maxn], preS[maxn];

int find(int x) {  //二分求出x对应的离散化的值
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;  //映射到1, 2, 3, ..., n
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x, c;
        scanf("%d %d", &x, &c);
        op.pb({x, c});
        alls.pb(x);
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        query.pb({l, r});
        alls.pb(l);
        alls.pb(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto item : op) {  //离散化成功
        int idx = find(item.fi);
        I[idx] += item.se;
    }

    for (int i = 1; i <= alls.size(); ++i)  //前缀和
        preS[i] = preS[i-1] + I[i];

    /*
     * for (int i = 0; i <= alls.size(); ++i)
     *     printf("%d ", preS[i]);
     * NEXTLINE;
     */

    for (auto item : query) {
        int l = find(item.fi),
            r = find(item.se);
        int res = preS[r] - preS[l-1];
        printf("%d\n", res);
    }
    return 0;
}
