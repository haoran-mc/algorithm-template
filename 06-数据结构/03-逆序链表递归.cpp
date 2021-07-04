#include <cstdio>
struct node {
    int data;
    node* next;
};
typedef node* pNode;

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

void Reverse(pNode &p) {
    if (p == NULL)
        return;

    pNode nxt = p -> next;    //p   -> {0, 1, 2, 3, 4}
    if (nxt == NULL)          //nxt -> {1, 2, 3, 4}
        return;

    Reverse(nxt);             //nxt -> {4, 3, 2, 1}
    p -> next -> next = p;    //1 -> 0   {4, 3, 2, 1, 0}
    //后一个元素指向当前元素
    p -> next = NULL;
    //0 -> NULL，为了第一个数据能指向NULL，后面的数据能指向NULL也无所谓
    //因为递归后还要修改它指向正确的位置
    p = nxt;
    //看似此句无用，实则在引用下，控制p不断向后移
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
    Reverse(head);
    outputList(head);
    return 0;
}
