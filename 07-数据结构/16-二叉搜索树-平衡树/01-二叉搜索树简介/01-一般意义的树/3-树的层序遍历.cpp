void layerorder(int root) {
    queue<int> quu;
    quu.push(root);
    while (quu.empty() == false) {
        int front = quu.front();
        printf("%d ", node[front].data);
        quu.pop();
        for (int i = 0; i < n; i++)
            quu.push(node[front].child[i]);
    }
}
