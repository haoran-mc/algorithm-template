#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 362880;  //状态共9! = 362880种
struct node {
    int state[9];
    int dis;
};
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int used[maxn];
int start[9];
int goal[9];
int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

bool cantor(int str[], int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int counted = 0;
        for (int j = i+1; j < n; ++j)
            if (str[i] > str[j])
                ++counted;
        res += counted * fact[n-1-1];
    }

    if (!used[res]) {
        used[res] = 1;
        return 1;
    }
    return 0;
}

int BFS() {
    node head;
    memcpy(head.state, start, sizeof(head.state));
    head.dis = 0;
    queue<node> quu;
    cantor(head.state, 9);
    quu.push(head);
    while (!quu.empty()) {
        head = quu.front();
        if (memcmp(head.state, goal, sizeof(goal)) == 0)
            return head.dis;
        quu.pop();
        int coord;
        for (coord = 0; coord < 9; ++coord)
            if (head.state[coord] == 0)
                break;
        int x = coord % 3;
        int y = coord / 3;
        for (int i = 0; i < 4; ++i) {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            int ncoord = newx + 3*newy;
            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
                node newnode;
                memcpy(&newnode, & head, sizeof(node));
                swap(newnode.state[coord], newnode.state[ncoord]);
                ++newnode.dis;
                if (cantor(newnode.state, 9))
                    quu.push(newnode);
            }
        }
    }
    return -1;
}

int main() {
    for (int i = 0; i < 9; ++i)
        scanf("%d", &start[i]);
    for (int i = 0; i < 9; ++i)
        scanf("%d", &goal[i]);
    int num = BFS();
    num != -1 ? printf("%d\n", num) : printf("Impossible");
    return 0;
}
