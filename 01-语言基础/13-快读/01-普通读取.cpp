#include <cstdio>
#include <ctime>
int main() {
    clock_t start;
    clock_t end;
    start = clock();

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int num;
    for (int i = 0; i < 1e7; ++i) {
        scanf("%d", &num);
        printf("%d\n", num);
    }

    end   = clock();
    printf("time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
