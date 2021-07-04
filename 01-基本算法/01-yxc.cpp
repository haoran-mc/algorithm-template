// 舍不得丢，用下面lhr的代码
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> PII;
vector<PII> segs;  // pair在C++中优先以左端点排序
// segment, section, sequence
// const int maxn = 1e5 + 5;

// 将含有交集的区间合并[1, 5] [4, 8] --> [1, 8]
void merge(vector<PII> &segs) {
    sort(segs.begin(), segs.end());
    vector<PII> res;
    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if (st != -2e9)
                res.push_back({st, ed});
            st = seg.first;
            ed = seg.second;
        }
        else
            ed = max(ed, seg.second);
    }

    if (st != -2e9)
        res.push_back({st, ed});
    segs = res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        segs.push_back({l, r});
    }
    merge(segs);
    printf("%d\n", (int)segs.size());
    return 0;
}
