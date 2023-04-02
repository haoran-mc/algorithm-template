/*----------------------------------------------------------------
 *
 *   文件名称：拉链法.cpp
 *   创建日期：2021年08月10日 星期二 10时57分04秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：数学上可以证明，mod一个素数，产生的冲突概率较小
 *      所以我们需要先寻找一个素数，而且这里把最大值设为N，而不是maxn了
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
const int N = 1e5 + 3;
int ha[N];
int e[N], ne[N], idx;

// 运行之后发现大于1e5的最小的素数是1e5 + 3，所以N = 1e5 + 3;
void get_prime() {
    for (int i = 100000; ; ++i) {
        bool flag = true;
        for (int j = 2; j * j <= i; ++j)
            if (i % j == 0) {
                flag = false;
                break;
            }
        if (flag) {
            printf("%d\n", i);
            return;
        }
    }
}

/**
 * 我们另k = (x % N + N) % N = 2;
 *   0   1   2   3   4   5   6     ha[maxn];
 *  ---------------------------
 * |   |   |   |   |   |   |   |   ha[maxn];   // 里面存的是指针(idx)
 *  ---------------------------
 *           |  <- 往这里插入一个值x(头插法)
 *          ---
 *         |   |
 *          ---
 *                   idx |
 *                       v
 *  ---------------------------
 * | - | - | - | - | - | x |   |   e[maxn];
 *  ---------------------------
 *
 */

void insert(int x) {
    int k = (x % N + N) % N;   // k就是哈希值
    e[idx] = x;       // e数组存储数据
    ne[idx] = ha[k];  // ne数组存储指针，因为ha[k]中就是指针，是上一个数的idx，
    ha[k] = idx++;     // 存储指针，当前的idx
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = ha[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}

int main() {
    // get_prime();
    int n; scanf("%d", &n);
    memset(ha, -1, sizeof ha);
    while (n--) {
        char op[2];
        int x;
        scanf("%s %d", op, &x);
        if (*op == 'I') 
            insert(x);
        else {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
