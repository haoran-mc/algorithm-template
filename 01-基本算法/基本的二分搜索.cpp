#include <cstdio>

int binarySearch(int num[], int n, int val) {
    int left  = 0;
    int right = n - 1;
    //最后一次改变查找范围使得left==right，所以需要继续循环最后一次
    //0, 1, 2, 3, 4, 5如果需要查找的数就是5呢?需要最后一次循环
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (num[mid] == val)
            return mid;
        else if (num[mid] < val)
            left  = mid + 1;
        else if (num[mid] > val)
            right = mid - 1;
    }
    return -1;
}

int main() {
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int val = 0; val <= 9; val++)
        printf("%d\n", binarySearch(num, 10, val));
    return 0;
}
