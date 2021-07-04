#include <cstdio>

int Joseph(int n,int m) {
	int J = 0;
	for(int i = 2; i <= n; i++)
		J = (J + m) % i;
    /*树组中的下标*/
	return J;
}

int main() {
    char car[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    printf("%c\n", car[Joseph(11, 3)]);
    return 0;
}
