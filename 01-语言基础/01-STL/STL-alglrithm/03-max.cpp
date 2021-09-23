#include <cstdio>
#include <ctime>
#include <algorithm>
const int maxn = 1e8;
#define max_r(a, b) (a > b ? a : b)
#define min_r(a, b) (a < b ? a : b)


int main() {
    clock_t start_1, end_1;
    clock_t start_2, end_2;
    int res_1 = 0;

/*
 *     start_1 = clock();
 *     for (int i = 0; i < maxn; i++)
 *         res_1 = std::max(res_1, i);
 *     end_1   = clock();
 *
 *     start_2 = clock();
 *     for (int i = 0; i < maxn; i++)
 *         res_1 = min_r(res_1, i);
 *     end_2   = clock();
 *
 *     printf("time1 = %f\n", (double)(end_1 - start_1) / CLOCKS_PER_SEC);
 *     printf("time2 = %f\n", (double)(end_2 - start_2) / CLOCKS_PER_SEC);
 *
 */
    start_1 = clock();
    for (int i = 0; i < maxn; ++i)
        res_1 = std::max(res_1, i);
    end_1   = clock();

    start_2 = clock();
    for (int i = 0; i < maxn; ++i)
        res_1 = min_r(res_1, i);
    end_2   = clock();

    printf("time1 = %f\n", (double)(end_1 - start_1) / CLOCKS_PER_SEC);
    printf("time2 = %f\n", (double)(end_2 - start_2) / CLOCKS_PER_SEC);
    return 0;
}
