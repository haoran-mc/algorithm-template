#include <stdio.h>

int binSearch(int num[], int left, int right, int val) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        // 可能溢出，mid = left + (right - left) / 2;
        if (num[mid] == val)
            return mid;
        else {
            if (num[mid] > val)
                right = mid - 1;
            else
                left  = mid + 1;
        }
    }
    return -1;
}

int main() {
    int num[10] = {1, 3, 4, 6, 7, 8, 10, 11, 12, 15};
    printf("%d %d\n", binSearch(num, 0, 9, 6), binSearch(num, 0, 9, 9));
    return 0;
}
