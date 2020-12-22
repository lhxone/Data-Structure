#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *next;
}*LinkList;

typedef struct DuList{
    int data;
    DuList *prior;
    DuList *next;
}*DLinkList;

void CreatDuList(DLinkList &L,int n){
    DLinkList p,q;
    L = new (DuList);
    L->next = NULL;
    L->prior = NULL;
    q = L;
    for (int i = 0; i < n; ++i) {
        p = *new (DLinkList);
        p->data = rand()%100;
        p->prior = q;
        q->next = p;
        q = p;
    }
}

void PrintDuList1(DLinkList L){
    DLinkList p = L;
    while (p != L){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void PrintDuList2(DLinkList L){
    DLinkList p = L;
    while (p != L){
        cout<<p->data<<" ";
        p = p->prior;
    }
    cout<<endl;
}

void DuInsert(DLinkList &L,int i){
    int cnt = 0;
    DLinkList p,q;
    q = L;
    p = (DLinkList) malloc(sizeof(DLinkList));
    while (q&&(cnt<i)){
        q = q->next;
        cnt++;
    }
    p->prior = q->prior;
    q->prior->next = p;
    q->prior = p;
    p->next = q;
}

void CreatListHead(LinkList &L,int n){
    LinkList p;
    L = new (node);
    L->next = NULL;
    for (int i = 0; i < n; ++i) {
        p = (LinkList) malloc(sizeof(node));
        p->data = rand()%100;
        p->next = L->next;
        L->next = p;
    }
}

void CreatListTail(LinkList &L,int n){
    LinkList p,q;
    L = new (node);
    q =L;
    for (int i = 0; i < n; ++i) {
        p = new (node);
        p->data = rand()%100;
        q->next = p;
        q = p;
    }
    q->next =NULL;
}

void Insert(LinkList &L,int i,int e){
    int cnt=0;
    LinkList p,q;
    p = L;
    q = new (node);
    while (p&&(cnt < i-1)){
        cnt++;
        p = p->next;
    }
    q->next = p->next;
    q->data = e;
    p->next = q;
}

void Delet(LinkList &L,int i){
    int cnt=0;
    LinkList p;
    p = L;
    while (p&&(cnt < i-1)){
        cnt++;
        p = p->next;
    }
    p->next = (*(p->next)).next;
}

void PrintList(LinkList L){
    int sum=0;
    for (LinkList p=L->next;p != NULL;p = p->next){
        cout<<p->data<<" ";

        sum++;
    }
    cout<<endl<<sum<<endl;
}

void MergeList(LinkList &L1,LinkList &L2,LinkList &L3){
    int i=0;
    LinkList p1,p2;
    L3 = new (node);
    p1 = L1;p2 = L2;
    while (p1&&p2){
        if (p1->data < p2->data) {
            Insert(L3, i, p1->data);
            p1 = p1->next;
        } else {
            Insert(L3, i, p2->data);
            p2 = p2->next;
        }
        i++;
    }
}

int main()
{
    int n;
    LinkList L1,L2,L3;
    L3 = new (node);
    cin>>n;
    CreatListHead(L1,n);
//    CreatListTail(L2,n);
    PrintList(L1);
    CreatListTail(L2,n);
    PrintList(L2);
    Insert(L1,2,3);
    PrintList(L1);
    Delet(L1,2);
    PrintList(L1);
    PrintList(L3);
    MergeList(L1,L2,L3);
    PrintList(L3);
//    int n;
//    cin>>n;
//    DLinkList L1,L2;
//    CreatDuList(L1,n);
//    PrintDuList1(L1);
//    PrintDuList2(L1);
}

