/*----------------------------------------------------------------
 *
 *   文件名称：1-创建链表.cpp
 *   创建日期：2020年09月02日 ---- 23时42分
 *   算    法：链表
 *   描    述：数据结构
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstdlib>

typedef int Status;
#define ElemType  int
#define MAXSIZE   255
#define LISTSIZE  100
#define INCREAMENTLIST 10
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define bug printf("******\n");

//链式存储结构
typedef struct Node {
    ElemType data;
    Node *next;
}Node, *LinkList;
//链式结点间的指针都是LinkList类型的

//基于链式存储结构的初始化
void InitList(LinkList &pNode) {
    //只开辟了一个空间
    pNode = (LinkList)malloc(sizeof(Node));
    /*
     * TMD，初始化就是将这个头指针指向一个随意的地方
     *pNode = (LinkList)malloc(sizeof(pNode));
     *pNode = (LinkList)malloc(1);
     *printf("pNode  = %d\n", (int)sizeof(pNode));
     *printf("Node   = %d\n", (int)sizeof(Node));
     *printf("*pNode = %d\n", (int)sizeof(*pNode));
     */
    if (pNode == NULL)
        exit(OVERFLOW);
    pNode -> data = OVERFLOW;
    pNode -> next = NULL;
}

//基于链式存储结构的插入操作(头插法)
void InsertList(LinkList &pNode, ElemType elem) {
    LinkList node = (LinkList)malloc(sizeof(Node));
    if (node == NULL)
        exit(OVERFLOW);
    node -> data = elem;
    node -> next = pNode -> next;
    pNode -> next = node;
}

//基于链式存储结构的插入操作(尾插法)
void InsertListEnd(const LinkList &pNode, ElemType elem) {
    //这里不需要使用malloc，仔细想
    LinkList Find = pNode;
    //LinkList Find = (LinkList)malloc(sizeof(Node));
    if (Find == NULL)
        exit(OVERFLOW);
    while (Find -> next != NULL)
        Find = Find -> next;

    Find -> next = (LinkList)malloc(sizeof(Node));
    Find = Find -> next;
    Find -> data = elem;
    Find -> next = NULL;
}

//基于链式存储结构的插入操作(在某个位置之前插入)
void InsertListMid(const LinkList &pNode, int position, ElemType elem) {
    if (pNode == NULL)
        exit(OVERFLOW);

    LinkList Find = pNode;
    int i = 0;
    //是1还是2
    while (i < position-1) {
        if (Find -> next == NULL)
            exit(OVERFLOW);
        i++;
        Find = Find -> next;
    }
    LinkList node = (LinkList)malloc(sizeof(Node));
    node -> data = elem;
    node -> next = Find -> next -> next;
    Find -> next -> next = node;
}

//基于链式存储结构的求长度操作
int ListLength(const LinkList &pNode) {
    LinkList trave = pNode -> next;
    int length = 0;
    while (trave != NULL) {
        ++length;
        trave = trave -> next;
    }
    return length;
}

void ListDelete(const LinkList &pNode, int position, int &Del) {
    int i = 0;
    LinkList Find = pNode;
    while (i < position) {
        if (Find -> next != NULL) {
            i++;
            Find = Find -> next;
        }
        else
            printf("This position is not exist!\n");
    }
    Del = Find -> next -> data;
    Find -> next = Find -> next -> next;
}

//输出链表data元素
void outputList(const LinkList &pNode) {
    LinkList print = pNode -> next;
    while (print != NULL) {
        printf("%d ", print -> data);
        print = print -> next;
    }
}

/*合并两个有序链表*/
void unionList(const LinkList &list1, const LinkList &list2, LinkList &list3) {
    LinkList pNode1 = list1 -> next;
    LinkList pNode2 = list2 -> next;
    while (pNode1 != NULL && pNode2 != NULL) {
        if (pNode1 -> data <= pNode2 -> data) {
            InsertListEnd(list3, pNode1 -> data);
            pNode1 = pNode1 -> next;
        }
        else {
            InsertListEnd(list3, pNode2 -> data);
            pNode2 = pNode2 -> next;
        }
    }

    while (pNode1 != NULL) {
        InsertListEnd(list3, pNode1 -> data);
        pNode1 = pNode1 -> next;
    }

    while (pNode2 != NULL) {
        InsertListEnd(list3, pNode2 -> data);
        pNode2 = pNode2 -> next;
    }
}

int main() {
    /*头结点*/
    LinkList pNode;
    InitList(pNode);
    for (int i = 0; i < 10; ++i)
        InsertList(pNode, i);
    outputList(pNode);

    printf("\n");
    for (int i = 0; i < 10; ++i)
        InsertListEnd(pNode, i);
    outputList(pNode);
    printf("  ---- insert 10 numbers on the list's end.\n");

    InsertListMid(pNode, 10, 3);
    outputList(pNode);
    printf("---- insert 3 on the position 10.\n");

    printf("%d\n", ListLength(pNode));

    ElemType Del;
    ListDelete(pNode, 10, Del);
    outputList(pNode);
    printf("  ---- delete the number on the position 10.\n");
    printf("%d  ---- the deleted number.\n", Del);

    printf("\nUnion List\n");
    LinkList list1;
    InitList(list1);
    InsertListEnd(list1, 2);
    InsertListEnd(list1, 8);
    InsertListEnd(list1, 16);
    InsertListEnd(list1, 27);
    InsertListEnd(list1, 39);
    InsertListEnd(list1, 43);
    outputList(list1);
    printf("   ---- list1\n");

    LinkList list2;
    InitList(list2);
    InsertListEnd(list2, 3);
    InsertListEnd(list2, 12);
    InsertListEnd(list2, 21);
    InsertListEnd(list2, 30);
    InsertListEnd(list2, 42);
    InsertListEnd(list2, 56);
    outputList(list2);
    printf("  ---- list2\n");
    LinkList list3;
    InitList(list3);
    unionList(list1, list2, list3);
    outputList(list3);
    printf("  ----- the union list\n");

    return 0;
}
