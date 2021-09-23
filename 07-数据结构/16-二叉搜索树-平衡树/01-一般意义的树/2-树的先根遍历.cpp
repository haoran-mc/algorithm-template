void preorder(int root) {
    printf("%d ", node[root].data);
    for (int i = 0; i < node[root].child.size(); i++)
        preorder(node[root].child[i]);
}
