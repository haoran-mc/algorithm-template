struct Node {
    int data;
    vector<int> child;
}node[maxn];


int index = 0;
int newNode(int value) {
    node[index].data = value;
    node[index].child.clear();
    return index++;
}
