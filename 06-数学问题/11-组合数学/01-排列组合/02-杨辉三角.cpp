#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 20;
/*杨辉三角：第n行有n个数，如果要得到20行杨辉三角，需要数组宽度为21*/
int triangle[maxn+1][maxn+1];
/*如果要得到5行杨辉三角，需要数组宽度为6*/
/**
 * 0 1
 * 0 1 1
 * 0 1 2 1
 * 0 1 3 3 1
 * 0 1 4 6 4 1
 * 第一列都是0，第五行有6列
 */
void YHtriangle(int border) {
    triangle[0][1] = 1;
    for (int i = 1; i < border; ++i)
        for (int j = 1; j <= i; ++j)
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
}

/*仅生成第n行的杨辉三角*/
vector<int> angle(20, 0);
void lineAngle(int n) {
    angle[0] = angle[n-1] = 1;
    for (int i = 1; i < n; ++i)
        angle[i] = angle[n-i-1] = (n-i) * angle[i-1] / i;
}

int main() {
    YHtriangle(20);
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j <= maxn; ++j)
            if (triangle[i][j] != 0)
                printf("%6d ", triangle[i][j]);
        printf("\n");
    }

    lineAngle(10);
    for (int i = 0; i < (int)angle.size(); ++i)
        if (angle[i])
            printf("%d ", angle[i]);
    printf("\n");
    return 0;
}
