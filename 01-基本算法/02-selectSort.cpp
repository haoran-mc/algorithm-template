#include <stdio.h>
int num[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int n = 10;

void selectSort() {
    int mini, idx;
    bool flag;

    for (int i = 0; i < n; i++) {
        flag = false;
        mini = num[i];
        idx  = i;
        for (int j = i; j < n; j++)
            if (num[j] < mini) {
                flag = true;
                mini = num[j];
                idx  = j;
            }
        if (flag) {
            num[i]  += num[idx];
            num[idx] = num[i] - num[idx];
            num[i]  -= num[idx];
        }
    }
}

int main() {
    selectSort();
    for (int i = 0; i < 10; i++)
        printf("%d ", num[i]);

    printf("\n");
    return 0;
}
