#include <cstdio>
#include <cstring>
#include <cstdlib>

/*前缀和*/
void prefix_table(char pattern[], int prefix[]) {
    int len = strlen(pattern);
    prefix[0] = 0;
    int ptr   = 0;

    int i = 1;
    while (i < len) {
        if (pattern[i] == pattern[ptr]) {
            ++ptr;
            prefix[i] = ptr;
            ++i;
        }
        else {
            if (ptr > 0)
                ptr = prefix[ptr-1];
            else {
                prefix[i] = 0;
                ++i;
            }
        }
    }
}

/*对前缀和操作*/
void move_prefix_table(int prefix[], int n) {
    for (int i = n-1; i > 0; --i)
        prefix[i] = prefix[i-1];
    prefix[0] = -1;
}

void kmp(char pattern[], char text[]) {
    int n = strlen(pattern);
    int m = strlen(text);
    int* prefix = (int *)malloc(sizeof(int) * n);

    prefix_table(pattern, prefix);
    move_prefix_table(prefix, n);

    // pattern[j] , len(pattern) = n
    // text[i]    , len(text)    = m

    int i = 0;
    int j = 0;
    while (i < m) {
        if (j == n-1 && text[i] == pattern[j]) {
            printf("Found pattern at %d\n", i-j);
            j = prefix[j];
        }
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        }
        else {
            j = prefix[j];
            if (j == -1) {
                ++i;
                ++j;
            }
        }
    }
}

int main() {
    char pattern[] = "ABABCABAA";
    char text[]    = "ABABABCABAABABAABAB";
    kmp(pattern, text);
    return 0;
}
