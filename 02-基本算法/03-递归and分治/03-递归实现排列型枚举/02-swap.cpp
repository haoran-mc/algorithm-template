#include <cstdio>
#include <algorithm>
using namespace std;
int cnt;
void Perm(int* arr, int size, int n) {
    if (n == size) {
        for(int i = 0; i < size; ++i)
            printf("%d", arr[i]);
        printf("\n");
        ++cnt;
    }
    else {
        for(int i = n; i < size; ++i) {
            swap(arr[i], arr[n]);
            Perm(arr, size, n+1);
            swap(arr[i], arr[n]);
        }
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};
    Perm(arr, 5, 0);
    printf("cnt = %d\n", cnt);
    return 0;
}
