#include <iostream>
using namespace std;
const int maxn = 1000010;
int num[maxn];

int quickSort(int l, int r, int k) {
    if (l >= r) return num[l];

    int i = l - 1, j = r + 1, x = num[l + r >> 1];
    while (i < j) {
        do i ++ ; while (num[i] < x);
        do j -- ; while (num[j] > x);
        if (i < j) swap(num[i], num[j]);
    }

    if (j - l + 1 >= k) 
        return quickSort(l, j, k);
    else 
        return quickSort(j + 1, r, k - (j - l + 1));
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ )
        scanf("%d", &num[i]);
    printf("%d\n", quickSort(0, n-1, k));
    return 0;
}
