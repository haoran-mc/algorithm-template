#include <stdio.h>
int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6};
    int M = 8;
    int i = 1;
    int j = 6;
    while (i < j) {
        if (a[i] + a[j] == M)
            printf("%d %d\n", i++, j--);
        else if (a[i] + a[j] < M)
            i++;
        else
            j--;
    }
    return 0;
}
