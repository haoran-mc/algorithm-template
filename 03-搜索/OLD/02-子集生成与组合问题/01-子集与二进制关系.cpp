#include <cstdio>
void print_subset(int n) {
    // 0~2^n, 每个i的二进制数代表一个子集，比如3的二进制为101，子集是{0, 2}
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                printf("%d ", j);
        printf("\n");
    }
}

int main() {
    int n = 3;
    // scanf("%d", &n);
    print_subset(n);
    return 0;
}
