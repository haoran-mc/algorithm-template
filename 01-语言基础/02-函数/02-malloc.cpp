#include <cstdio>
#include <cstdlib>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    Node* next;
}Node, *LinkList;

struct stackList {
    Node* top;
    Node* base;
};

int main() {
    LinkList node1 = (LinkList)malloc(sizeof(Node));
    LinkList node2 = (LinkList)malloc(sizeof(LinkList));
    node1 -> data = 1;
    node2 -> data = 2;
    printf("sizeof(Node) = %d\n", (int)sizeof(Node));
    printf("sizeof(LinkList) = %d\n", (int)sizeof(LinkList));
    printf("sizeof(node1) = %d\n", (int)sizeof(node1));
    printf("sizeof(node2) = %d\n", (int)sizeof(node2));
    return 0;
}
