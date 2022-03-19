#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 1001
using namespace std;

struct Data {
	int x;
	int y;
} data[MAX];
int ans[MAX];
bool cmp(Data a, Data b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int main() {
	int t, n, i, j, max, tempx, tempy;
	scanf("%d", &t);
	while(t--) {
		memset(ans, 0, sizeof(ans));
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d%d", &tempx, &tempy);
			if(tempx < tempy) {
				data[i].x = tempx;           //录入时确保x为宽y为长
				data[i].y = tempy;
			}
			else {
				data[i].x = tempy;
				data[i].y = tempx;
			}
		}
		sort(data, data+n, cmp);
		for(i = 0; i < n; i++)
			ans[i] = 1;
		for(i = 1; i < n; i++) {
			max = 0;
			for(j = i-1; j >= 0; j--)
				if(data[i].x > data[j].x && data[i].y > data[j].y  && ans[j] > max)
					max = ans[j];
			ans[i] = max + 1;
		}
		max = 0;
		for(i = 0; i < n; i++)
			if(ans[i] > max)
				max = ans[i];                //遍历结果数组找最长子序列（长度）
		printf("%d\n", max);
	}
}
