#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct Tree {
    Node* root;
};

void layerOrder(Node* root) {
    queue<Node*> quu;
    quu.push(root);
    while (quu.empty() == false) {
        Node* first = quu.front();
        quu.pop();
        printf("%d\n", first -> data);
        if (first -> left  != NULL)
            quu.push(first -> left);
        if (first -> right != NULL)
            quu.push(first -> right);
    }
}

int main() {
    return 0;
}
