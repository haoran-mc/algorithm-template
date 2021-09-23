#include <cstdio>
#include <vector>
using namespace std;
#define NEXTLINE puts("");
vector<int> path;
int n;

void DFS(int u, int state) {
    if (u == n) {
        for (auto _ : path)
            printf("%d ", _);
        NEXTLINE;
        return ;
    }
    for (int i = 0; i < n; ++i) 
        if (!(state >> i & 1)) {
            path.push_back(i + 1);
            DFS(u + 1, state | 1 << i);
            path.pop_back();
        }
}

int main() {
    scanf("%d", &n);
    DFS(0, 0);
    return 0;
}
