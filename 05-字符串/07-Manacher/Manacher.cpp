#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int maxn = 2e7 + 5;

int n;
char a[maxn], b[maxn]; // 原串，新串
int p[maxn]; // 以 i 位置为中心，最长的回文串半径多大

void init() {
    int k = 0;
    b[k ++ ] = '^';
    b[k ++ ] = '#';
    for (int i = 0; i < n; i++) {
        b[k ++ ] = a[i];
        b[k ++ ] = '#';
    }
    b[k ++ ] = '$';
    n = k;
}

void manacher() {
    int mr = 0, mid;

    for (int i = 1; i < n; i++) {
        int j = 2 * mid - i;
        if (i <= mr) {
            p[i] = min(p[j], mr - i);
        } else {
            p[i] = 1;
        }
        while (b[i - p[i]] == b[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > mr) {
            mr = i + p[i];
            mid = i;
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%s", a);
    // a = "DDDDBBDBA|BCBAAABBAAABCB|DB";
    n = strlen(a);

    init();
    manacher();

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, p[i]);
    }
    printf("%d\n", res - 1);
    return 0;
}
