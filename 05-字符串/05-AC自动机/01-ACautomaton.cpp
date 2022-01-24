/*----------------------------------------------------------------
 *
 *   文件名称：01-ACautomaton.cpp
 *   创建日期：2021年03月19日 ---- 19时49分
 *   题    目：hdu2222 keywords search
 *   算    法：AC自动机
 *   描    述：第一行测试用例数，每个用例包括一个整数N，表示关键字个数
 *      下面有N个关键词N <= 10000，每个关键词只包括小写字母，长度不超过
 *      50，最后一行是文本，长度不大于1000000
 *      在输出的文本中能找到多少关键词
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1000005;
const int sigma_size = 26; //字符集
const int maxnode = 1000005;
int res;
bool used[maxn];
/*
 * 数组定义的字典树
 * ch[i][j]保存结点i的那个编号为j的子结点
 * ch[i][0] == 0表示结点i的子结点a不存在
 */
int ch[maxnode][sigma_size+5];
int dict[maxnode];
int idx(char c) {return c - 'a';}

/*              _
 *             |_|  root
 *             /|\
 *            / | \
 *           /  |  \
 *      [t] t   a   i [i]
 *         / \       \
 *        /   \       \
 *       /     \       \
 * [to] o       e [te]  n [in]
 *             /|\       \
 *            / | \       \
 *           /  |  \       \
 *          a   d   n       n [inn]
 *      [tea] [ted] [ten]
 */

struct Trie {
    int pos;
    Trie() { pos = 1; memset(ch[0], 0, sizeof(ch[0])); memset(used, 0, sizeof(used)); }
    void insert(char *s) {
        int p = 0; //查字典，前缀的位置pos
        int n = strlen(s);
        for(int i = 0; i < n; i++) {
            int c = idx(s[i]); //c = ch - 'a'
            if(!ch[p][c]) {
                memset(ch[pos], 0, sizeof(ch[pos]));
                dict[pos] = 0;
                ch[p][c] = pos++;
            }
            p = ch[p][c];
        }
        dict[p]++;
    }
};

/*Aho-Corasick automaton*/
int last[maxn], f[maxn];
/*递归打印以结点j结尾的所有字符串*/
void print(int j) {
    if (j && !used[j]) {
        res += dict[j];
        used[j] = 1;
        print(last[j]);
    }
}

/*
 * 计算失配函数
 * BFS顺序递推
 * 在字典树ch中添加失配边
 */
void getFail() {
    queue<int> quu;
    f[0] = 0;
    for (int c = 0; c < sigma_size; ++c) {
        int p = ch[0][c];
        if (p) {
            f[p] = 0;
            quu.push(p);
            last[p] = 0;
        }
    }
    while (!quu.empty()) {
        int r = quu.front();
        quu.pop();
        for (int c = 0; c < sigma_size; ++c) { //遍历字母
            int p = ch[r][c];
            if (!p) {
                ch[r][c] = ch[f[r]][c];
                continue;
            }
            quu.push(p);
            int v = f[r];
            while(v && !ch[v][c])
                v = f[v];
            f[p] = ch[v][c];
            last[p] = dict[f[p]] ? f[p] : last[f[p]];
        }
    }
}

/*在文本串T中找模板*/
void find_T(char* T) {
    int n = strlen(T);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int c = idx(T[i]);
        p = ch[p][c];
        if (dict[p])
            print(p);
        else if (last[p])
            print(last[p]);
    }
}

char pattern[55];
char text[1000005];
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        Trie trie;
        res = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", pattern);
            trie.insert(pattern);
        }
        getFail();
        scanf("%s", text);
        find_T(text);
        printf("%d\n", res);
    }
    return 0;
}
