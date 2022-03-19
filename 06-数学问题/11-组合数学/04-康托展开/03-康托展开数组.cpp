#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 10;
#define NEXTLINE puts("");
int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; // 阶乘 89 
/*
* 返回长度为 n 的这个序列在这 n 个数的全排列中是第几位
* 1, 2, 3, 4, 5, ..., n 是第一位
* n, n - 1, ..., 3, 2, 1 是最后一位，也是第 A_n^n 位
* 康托展开公式：res = a[n] * (n - 1)! + a[n - 1] * (n - 2)! + ... + a[1] * 0!;
* 这里的 a[i] 表示的是第 i 个位置上的数在 i 后面的数中排第几
*/
int Contor(int* sequ, int n) {
    int res = 0;
    for (int i = 0; i < n; ++ i) {
        int cnt = 0;
        for (int j = i + 1; j < n; ++ j)
            if (sequ[i] > sequ[j])
                cnt ++ ;
        res += cnt * fact[n - i - 1];
    }
    return res + 1;
}
// 只能返回 [1, n] 的排列，也容易转换为指定的集合
int* revContor(int ranking, int n) {
    ranking = ranking - 1; // 有 ranking - 1 个排列比目标序列要小
    bool used[maxn];
    static int permutation[maxn];
    memset(used, false, sizeof used);
    memset(permutation, -1, sizeof permutation);
    for (int i = 0; i < n; ++ i) {
        int r = ranking / fact[n - i - 1];
        ranking = ranking % fact[n - i - 1];
        for (int j = 1; j <= n; ++ j)
            if (!used[j] && !(r -- )) {
                used[j] = true;
                permutation[i] = j;
                break;
            }
    }
    // sequ 排个序
    // 如果 permutaion[i] = 1，需要指定集合的话，就输出 sequ[permutation[i] - 1];
    return permutation;
}
int main() {
    int a[maxn], n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i)
        scanf("%d", &a[i]);
    int ranking = Contor(a, n);
    printf("%d\n", ranking);
    int *rank_sequ;
    rank_sequ = revContor(ranking, n);
    for (int i = 0; i < n; ++ i)
        printf("%d ", rank_sequ[i]);
    NEXTLINE;
    return 0;
}
