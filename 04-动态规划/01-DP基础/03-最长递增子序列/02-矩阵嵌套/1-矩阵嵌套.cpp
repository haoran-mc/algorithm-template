#include <stdio.h>
#include <string.h>
#include <algorithm>
const int maxn = 1005;
using namespace std;

struct Matrix {
	int x;
	int y;
} matrix[maxn];
int dp[maxn]; /*表示以当前矩阵结束可以嵌套的矩阵最多是多少*/
bool cmp(Matrix a, Matrix b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int main() {
	int n;
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    int tempx;
    int tempy;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tempx, &tempy);
        /*将长存在y中，宽存在x中*/
        if (tempx < tempy) {
            matrix[i].x = tempx;
            matrix[i].y = tempy;
        }
        else {
            matrix[i].x = tempy;
            matrix[i].y = tempx;
        }
    }
    sort(matrix, matrix+n, cmp);
    for(int i = 0; i < n; i++)
        dp[i] = 1; /*显然最少也是一个都不能嵌套*/
    int res = 0;
    for (int i = 1; i < n; i++)
        for (int j = i-1; j >= 0; j--)
            if (matrix[i].x > matrix[j].x && matrix[i].y > matrix[j].y && dp[j] > dp[i])
                dp[i] = max(dp[i], dp[j] + 1),
                res = max(res, dp[i]);
    printf("%d\n", res);
}
