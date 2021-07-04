#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200005;
char text[maxn];
int sa[maxn];
int rk[maxn];
int cnt[maxn];
int t1[maxn];
int t2[maxn];
int height[maxn];
int n;

void calc_sa() {
    int m = 127;
    int *x = t1;
    int *y = t2;
    for (int i = 0; i < m; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) cnt[x[i] = text[i]]++;
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i-1];
    for (int i = n-1; i >= 0; --i) sa[--cnt[x[i]]] = i;
    for (int k = 1; k <= n; k *= 2) {
        int p = 0;
        for (int i = n-k; i < n; ++i) y[p++] = i;
        for (int i = 0; i < n; ++i)
            if (sa[i] >= k)
                y[p++] = sa[i] - k;
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) cnt[x[y[i]]]++;
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; --i) sa[--cnt[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            x[sa[i]] =
                y[sa[i-1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i] + k] ? p-1 : p++;
        if (p >= n) break;
        m = p;
    }
}

/*求辅助数组height[]*/
/*定义height[]为sa[i-1]和sa[i]也就是排名相邻的两个后缀的最长公共前缀长度*/
void getheight(int n) {
    int k = 0;
    for (int i = 0; i < n; ++i)
        rk[sa[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (k)
            k--;
        int j = sa[rk[i]-1];
        while (text[i+k] == text[j+k])
            k++;
        height[rk[i]] = k;
    }
}

int main() {
    int len1;
    int res;
    while (scanf("%s", text) != EOF) {
        n = strlen(text);
        len1 = n;
        text[n] = '$'; //用$分割两个字符串
        scanf("%s", text + n + 1); //将第2个字符串和第1个字符串合并
        n = strlen(text);
        calc_sa();
        getheight(n);
        res = 0;
        for (int i = 0; i < n; ++i)
            //找最大的height[i]，并且它对应的sa[i-1]和sa[i]分别属于前后两个字符串
            if (height[i] > res &&
                    ((sa[i-1] < len1 && sa[i] >= len1) || (sa[i-1] >= len1 && sa[i] < len1)))
                res = height[i];
        printf("%d\n", res);
    }
}
