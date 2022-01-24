#include <cstdio>
void print_set(int n, int m) {
    for (int i = 0; i < (1 << n); ++i) {
        int num = 0;
        int kk = i;
        while (kk) {
            kk = kk & (kk-1);
            ++num;
        }
        if (num == m) {
            for (int j = 0; j < n; ++j)
                if (i & (1 << j))
                    printf("%d ", j);
            printf("\n");
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    print_set(n, m);
    return 0;
}
