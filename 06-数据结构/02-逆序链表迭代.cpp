#include <cstdio>    //NULL在cstdio头文件中被定义
struct node {
    int data;
    struct node* next;
};
typedef struct node* pNode;

pNode creatList() {
    int n;
    scanf("%d", &n);

    pNode cursor = new node;
    pNode head = cursor;
    scanf("%d", &cursor -> data);
    n--;

    while (n--) {
        pNode chains = new node;
        chains -> next = NULL;
        scanf("%d", &chains -> data);
        cursor -> next = chains;
        cursor = chains;
    }
    return head;
}

pNode reverse(pNode head) {
    pNode current = head;
    pNode next = NULL, result = NULL;
    while (current != NULL) {
        next = current -> next;
        current -> next = result;
        result = current;
        current = next;
    }
    return result;
}

pNode Reverse(pNode head) {
    pNode succ = NULL;
    pNode tail = NULL;
    while (head != NULL) {
        succ = head -> next;
        head -> next = tail;    //pNode = pNode
        tail = head;
        head = succ;
    }
    return tail;
}

void outputList(pNode head) {
    pNode cursor = head;
    while (cursor -> next != NULL) {
        printf("%d ", cursor -> data);
        cursor = cursor -> next;
    }
    printf("%d", cursor -> data);
}

int main() {
    printf("%d", (int)sizeof(pNode));
    printf("%d", (int)sizeof(node));
    pNode head = creatList();
    //pNode result = reverse(head);
    pNode result = Reverse(head);
    outputList(result);
    return 0;
}
