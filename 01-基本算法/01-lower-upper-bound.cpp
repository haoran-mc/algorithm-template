#include <cstdio>
#define bug printf("<-->\n");
#define NEXTLINE puts("");
int n = 9;
int arr[] = {1, 2, 2, 3, 3, 3, 3, 4, 5};

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
void lowerBound(int l, int r, int val) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= val) {
            r = mid;
        }
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}

// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
void upperBound(int l, int r, int val) {
    while (l < r) {
        //这里要加一
        int mid = (l + r + 1) >> 1;
        if (arr[mid] <= val)
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
}

int main() {
    int val = 3;
    lowerBound(0, n - 1, val);
    upperBound(0, n - 1, val);
    return 0;
}
