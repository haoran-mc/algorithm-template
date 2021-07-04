#include <cstdio>
const double eps = 1e-8;

bool judge(double mid, double n) {
    if (mid * mid * mid < n)
        return true;
    else
        return false;
}

// 0.001
double bsearch_3(double n) {
    double l = -10000, r = 10000;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (judge(mid, n))
            l = mid;
        else
            r = mid;
    }
    return r;
}

int main() {
    double n;
    scanf("%lf", &n);
    double res = bsearch_3(n);
    printf("%.6f\n", res);
    return 0;
}
