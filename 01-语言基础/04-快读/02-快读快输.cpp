#include <cstdio>
#include <ctime>
inline int read() {
	int x = 0; bool flag = 1; char ch = getchar();
	while ((ch<'0' || ch>'9') && ch == '-')
        flag = 0, ch = getchar();
	while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    return flag ? x : ~(x-1);
}

inline void write(int x) {
	if (x<0)
        x = ~(x-1), putchar('-');
    else if
        (x > 9) write(x/10);
	putchar(x%10+'0');
}

/*
 *inline int rwrite(int x)
 *{
 *    if(x<0) {putchar('-'); x=~(x-1);}
 *    int s[20],top=0;
 *    while(x) {s[++top]=x%10; x/=10;}
 *    if(!top) s[++top]=0;
 *    while(top) putchar(s[top--]+'0');
 *}
 */

int main() {
    clock_t start;
    clock_t end;
    start = clock();

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int num;
    for (int i = 0; i < 1e7; ++i) {
        num = read();
        write(num);
        putchar('\n');
    }

    end   = clock();
    printf("time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
