#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 110;

struct Interval {
    int x;
    int y;
} interval[N];

bool cmp(Interval a, Interval b) {
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y < b.y;
}

int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &interval[i].x, &interval[i].y);

        sort(interval, interval + n, cmp);

        int ans   = 1;
        int lastx = interval[0].x;

        for (int i = 1; i < n; i++)
            if (interval[i].y <= lastx) {
                lastx = interval[i].x;
                ans++;
            }
        printf("%d\n", ans);
    }
    return 0;
}
