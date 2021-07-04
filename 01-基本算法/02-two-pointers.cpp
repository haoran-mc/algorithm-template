#include <stdio.h>
int main() {
    int a[] = {0, 2, 4, 6, 8};
    int b[] = {1, 3, 5, 7, 9};
    int i = 0;
    int j = 0;
    int c[10];
    int index = 0;

    while (i < 5 && j < 5) {
        if (a[i] <= b[j])
            c[index++] = a[i++];
        else
            c[index++] = b[j++];
    }
    while (i < 5)
        c[index++] = a[i++];
    while (j < 5)
        c[index++] = b[j++];
    for (i = 0; i < 10; i++)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}
