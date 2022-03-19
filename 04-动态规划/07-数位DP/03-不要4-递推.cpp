/*----------------------------------------------------------------
 * 文件名称：01-不要4-递推.cpp
 * 创建日期：2021年03月09日 ---- 21时57分 
 * 题 目：hdu2089 不要62
 * 算 法：数位DP
 * 描 述：一个数字如果包含‘4’或者'62'，它是不吉利的，给定m和n 
 * 0 < m < n < 1e6，统计[m, n]范围内的吉利数 
 * 只是为了理解数位DP，所以简化题目要求，只排除了'4'
 * dp[i][j]表示i位数中首位是j，符合要求的数的个数
 * 递推公式dp[i][j] = dp[i-1][k] (k From 0 To 9) && (j != 4) && (k != 2 && j != 6)
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 12; //可以更大
int dp[maxn+1][10]; //dp[i][j]表示i位数，第1位数是j时符合条件的数字数量
int digit[maxn+1]; //digit[i]存第i位数字
void init() {
    dp[0][0] = 1;
    for (int i = 1; i <= maxn; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k)
                if (j != 4) //排除数字4
                    dp[i][j] += dp[i-1][k];
}
/*计算0 ~ n区间满足条件的数字个数*/
int solve(int len) {
    int res = 0;
    for (int i = len; i >= 1; --i) { //从高位到低位处理
        for (int j = 0; j < digit[i]; ++j)
            if (j != 4)
                res += dp[i][j];
        if (digit[i] == 4) { //第i位是4，以4开头的2数都不行
            --res;
            break;
        }
    }
    return res;
}
int main() {
    int n;
    int len = 0;
    init(); //预计算dp[][]
    scanf("%d", &n);
    while (n) { //len是n的位数，例如n = 324，是3位数，len = 3
        digit[++len] = n % 10; //digit[3] = 3, digit[2] = 2, digit[1] = 4
        n /= 10;
    }
    printf("%d\n", solve(len) + 1); //求0 ~ n不含4的个数
    return 0;
}
