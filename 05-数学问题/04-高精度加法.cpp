#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#define NEXTLINE cout << endl;
using namespace std;

// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B) {
    if (A.size() < B.size())
        return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); ++i) {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t)
        C.push_back(t);
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string n1, n2;
    vector<int> A, B;
    cin >> n1 >> n2; //n1 = 123456

    // A = [6, 5, 4, 3, 2, 1];
    for (int i = n1.length() - 1; i >= 0; --i)
        A.push_back(n1[i] - '0');
    for (int i = n2.length() - 1; i >= 0; --i)
        B.push_back(n2[i] - '0');

    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    NEXTLINE;
    return 0;
}
