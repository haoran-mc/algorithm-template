#include <cstdio>
#include <vector>
using namespace std;
int main() {
    vector<int> vec1;
    vector<int> vec2;
    for (int i = 0; i < 25; i++)
        vec1.push_back(i);

    vec2 = vec1;
    for (auto it = vec2.begin(); it != vec2.end(); it++)
        printf("%d ", *it);

    printf("\n");
    return 0;
}
