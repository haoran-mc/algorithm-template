int factor(int n, int p) {
    if (n < p)
        return 0;

    return n / p + factor(n / p , p);
}
