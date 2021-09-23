#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define NEXTLINE cout << endl;

// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); ++i) {
        t = A[i] - t;
        if (i < B.size()) 
            t -= B[i];
        C.push_back((t + 10) % 10);
        t < 0 ? t = 1 : t = 0;
    }

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string n1, n2;
    cin >> n1 >> n2;
    vector<int> A, B;

    for (int i = n1.length() - 1; i >= 0; --i)
        A.push_back(n1[i] - '0');
    for (int i = n2.length() - 1; i >= 0; --i)
        B.push_back(n2[i] - '0');

    //判断A < B, 则swap
    if (n1.length() < n2.length() || (n1.length() == n2.length() && n1 < n2)) 
        swap(A, B);

    auto C = sub(A, B);

    if (n1.length() < n2.length() || (n1.length() == n2.length() && n1 < n2)) 
        cout << "-";
    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    NEXTLINE;
    return 0;
}
