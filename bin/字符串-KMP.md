<!-- -------------------------2020年11月17日 ---- 17时11分------------------------- -->

### KMP-search

```cpp
void prefix_table(char pattern[], int prefix[], int n) {
    prefix[0] = 0;
    int len   = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        }
        else {
            if (len > 0)
                len = prefix[len-1];
            else {
                prefix[i] = 0;
                i++;
            }
        }
    }
}
void move_prefix_table(int prefix[], int n) {
    for (int i = n-1; i > 0; i--)
        prefix[i] = prefix[i-1];
    prefix[0] = -1;
}
void kmp_search(char text[], char pattern[]) {
    int n = strlen(pattern);
    int m = strlen(text);
    int* prefix = (int *)malloc(sizeof(int) * n);
    prefix_table(pattern, prefix, n);
    move_prefix_table(prefix, n);
    int j = 0;
    int i = 0;
    while (i < m) {
        if (j == n-1 && text[i] == pattern[j]) {
            printf("Found pattern at %d\n", i - j);
            j = prefix[j];
        }
        if (text[i] == pattern[j])
            i++, j++;
        else {
            j = prefix[j];
            if (j == -1)
                i++, j++;
        }
    }
    free(prefix);
}
```

```cpp
void prefix_table(string pattern, int prefix[]) {
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while (i < (int)pattern.length()) {
        if (pattern[i] == pattern[len]) {
            ++len;
            prefix[i] = len;
            ++i;
        }
        else {
            if (len > 0) len = prefix[len - 1];
            else prefix[i++] = 0;
        }
    }
}
void move_prefix_table(int prefix[], int n) {
    for (int i = n - 1; i > 0; --i)
        prefix[i] = prefix[i-1];
    prefix[0] = -1;
}
void kmp_search(string text, string pattern) {
    int n = pattern.length();
    int m = text.length();
    int* prefix = (int *)malloc(sizeof(int) * n);
    prefix_table(pattern, prefix);
    move_prefix_table(prefix, n);
    // pattern[j] , len(pattern) = n
    // text[i]    , len(text)    = m
    int j = 0;
    int i = 0;
    while (i < m) {
        if (j == n-1 && text[i] == pattern[j]) {
            printf("Found pattern at %d\n", i - j);
            j = prefix[j];
        }
        if (text[i] == pattern[j])
            ++i, ++j;
        else {
            j = prefix[j];
            if (j == -1)
                ++i, ++j;
        }
    }
    free(prefix);
}
```
