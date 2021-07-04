/*----------------------------------------------------------------
 *
 *   文件名称：02-不要4-记忆化.cpp
 *   创建日期：2021年03月10日 ---- 08时12分
 *   题    目：hdu2089 不要62
 *   算    法：数位DP
 *   描    述：一个数字如果包含‘4’或者'62'，它是不吉利的，给定m和n
 *      0 < m < n < 1e6，统计[m, n]范围内的吉利数
 *      只是为了理解数位DP，所以简化题目要求，只排除了'4'
 *      记忆化搜索的思路就是在递归dfs()中搜索所有可能的情况，遇到已
 *      经算过的记录在dp[]中的结果就直接使用，不再重复计算
 *      dp[i]表示i位数中符合条件的数字个数
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int maxn = 12;
int dp[maxn]; //dp[i]表示i位数符合要求的个数，dp[2]表示00 ~ 99内符合要求的个数
int digit[maxn];
int dfs(int len, int ismax) { //如果ismax == 1，
    int res = 0;
    int maxx;
    if (!len) //已经递归到0位数，返回
        return 1;
    if (!ismax && dp[len] != -1) //记忆化搜索，如果已经计算过，就直接使用
        return dp[len];
    maxx = (ismax ? digit[len] : 9); //用来判断搜索到什么位置，比如324在十位只用搜索到2
    for (int i = 0; i <= maxx; ++i) {
        if (i == 4) //排除4
            continue;
        res += dfs(len-1, ismax && i == maxx);
    }
    if (!ismax)
        dp[len] = res;
    return res;
}

int main() {
    int n;
    int len = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    while(n) {
        digit[++len] = n % 10;
        n /= 10;
    }
    printf("%d\n", dfs(len, 1));
    return 0;
}
