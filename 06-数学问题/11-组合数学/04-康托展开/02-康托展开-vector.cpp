#include <cstdio>
#include <vector>
using namespace std;
#define NEXTLINE puts("");
const int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int Contor(const vector<int>& permutation) {
    int num = 0;
    int len = permutation.size();
    for (int i = 0; i < len; ++ i) {
        int cnt = 0;
        for (int j = i + 1; j < len; ++ j)
            if (permutation[i] > permutation[j])
                cnt ++ ;
        num += cnt * fact[len - i - 1];
    }
    return num + 1;
}
vector<int> revContor(int ranking, int n) {
    ranking = ranking - 1; // 有 ranking - 1 个排列比目标序列要小
    vector<bool> used(n + 1, false);
    vector<int> permutation(n, -1);
    for (int i = 0; i < n; ++ i) {
        int r = ranking / (fact[n - i - 1]);
        ranking = ranking % (fact[n - i - 1]);
        for (int j = 1; j <= n; ++ j)
            if (!used[j] && !(r -- )) {
                used[j] = true;
                permutation[i] = j;
                break;
            }
    }
    // sequ 排个序
    // 如果 permutaion[i] = 1，需要指定集合的话，就输出 sequ[permutation[i] - 1];
    return permutation;
}
int main() {
    vector<int> vec;
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        int _; scanf("%d", &_);
        vec.push_back(_);
    }
    int ranking = Contor(vec);
    printf("%d\n", ranking);
    vector<int> res = revContor(ranking, n);
    for (auto i : res)
        printf("%d ", i);
    NEXTLINE;
    return 0;
}
