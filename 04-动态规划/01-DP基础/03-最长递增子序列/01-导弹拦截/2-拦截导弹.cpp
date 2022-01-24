#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 25;
const int inf  = 0x3f3f3f3f;
int bomb[maxn];
int dp[maxn]; /*当前导弹作为结尾时能拦截的导弹数*/
int link[maxn];
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    ++n;
    bomb[0] = inf; /*必须设置第一个是最大的，保证之后的最大的能被link在这次之后，否则之后的最大的link是它自己，而最后的输出条件是到达-1才停止输出*/
    for (int i = 1; i <= n; ++i)
        scanf("%d", &bomb[i]);
    memset(link, -1, sizeof(link));
    int maxi;
    int idx;
    int res = 1;
    int start = -1;
    dp[0] = 1; /*第一个导弹一定能被拦截*/
    /*dp[1]不需要预先设定，如果程序中没有找到前面比它高的导弹，会自动设定1*/
    /*而dp[0]通过循环自己设定1，因为会同时改变idx的值*/
    for (int i = 1; i < n-1; ++i) {
        maxi = dp[i]; /*首先认为当前的dp是最大的，如果能发现更大的，那就更改为更大的*/
        idx  = i; /*idx寻找前面比当前导弹高的，且dp更大的导弹的下标*/
        /*一定要倒着寻找，找到最近的*/
        for (int j = i-1; j >= 0; --j)
            if (bomb[j] >= bomb[i] && dp[j] > maxi) {
                maxi = dp[j];
                idx  = j;
            }
        dp[i] = ++maxi;
        link[i] = idx;
        if (dp[i] > res) { /*最多的能拦截的导弹数*/
            res = dp[i];
            start = i;
        }
    }
    printf("%d\n", res);
    vector<int> vec;
    for (int i = start; i != -1; i = link[i])
        if (i != 0)
            vec.push_back(bomb[i]);
    for (auto it = vec.begin(); it != vec.end(); ++it)
        printf("%d ", *it);
    return 0;
}

