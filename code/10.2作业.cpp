#include <iostream>

using namespace std;

typedef struct node         //单链表
{
    int data;
    struct node *next;
} *NodeList;

typedef struct SqList {     //顺序表
    int *elem;
    int len;
    int size;
};


NodeList *createEnd(NodeList &head,int len)         //单链表创立尾插法
{
    head = (node *)malloc(sizeof(NodeList));
    head->next = NULL;
    NodeList end = head;
    for (int i = 0; i < len; i++) {
        NodeList p = (NodeList)malloc(sizeof(node));
        p->data= rand()%100;
        end->next = p;
        end = p;
    }
    end->next = NULL;
}

void Print(NodeList head)                   //单链表输出
{
    int i = 0;
    if (head == NULL)
        return;
    NodeList p = head->next;
    while (p != NULL) {
        printf("%4d",p->data);
        p = p->next;
        if ((i+1)%5 == 0){
            cout<<endl;
        }
        i++;
    }
    cout<<endl;
}

void DeletElem(NodeList &head,SqList &T)        //单链表删除
{
    int i = 0,j = 0;
    NodeList p,q;
    NodeList s = head;
    T.size = 1000;
    T.elem = (int*)malloc(T.size * sizeof(int));
    T.len = 0;
    p = s->next;
    while(p != NULL)
    {
        q = p;
        while(q->next != NULL)
        {
            if(q->next->data == p->data)
            {
                q->next = q->next->next;
                T.elem[T.len++] = p->data+(i+j+1)*100;

            }
            q = q->next;
            j++;
        }
        j = 0;
        i++;
        p = p->next;
    }
}

void CreatList(SqList &L,int n){            //顺序表创建
    L.elem  = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        L.elem[i] = rand()%100;
    }
    L.len = n;
}

void PrintList(SqList L){                   //顺序表输出
    for (int i = 0; i < L.len; ++i) {
        printf("%4d",L.elem[i]);
        if ((i+1)%5 == 0){
            cout<<endl;
        }
    }
    cout<<endl;
}

void DeletElem(SqList &L,SqList &T){        //顺序表删除
    T.len = 0;
    T.elem = (int *)malloc(L.len * sizeof(int ));
    for (int i = 0; i <L.len; ++i) {
        for (int j = i+1; j < L.len; ++j) {
            if (L.elem[j] == L.elem[i]){
                for (int k = j; k < L.len - 1; ++k) {
                    L.elem[k] = L.elem[k+1];
                }
                T.elem[T.len++] = L.elem[i]+j*100;
                L.len--;
            }
        }
    }
}

void ReverseLink(NodeList &Head)          //单链表倒置
{
    int flag=0;
    if (Head == NULL)
    {
        return;
    }
    NodeList pNode = Head->next;
    NodeList Prev = NULL;
    NodeList pNext = NULL;
    while (pNode != NULL){
        pNext = pNode->next;
        if (pNext == NULL){
            Head = pNode;
        }

        pNode->next = Prev;
        Prev = pNode;
        pNode = pNext;

    }
    NodeList p = (NodeList)malloc(sizeof(int));
    p->next = Head;
    Head = p;
}

int main()
{
    int n,*a;
    SqList T;
    cin>>n;
    //TODO:删除顺序表中的重复元素
    SqList L;
    CreatList(L,n);
    cout<<"顺序表创建完成:"<<endl;
    PrintList(L);
    DeletElem(L,T);
    cout<<"顺序表删除完成:"<<endl;
    PrintList(L);
    if (T.len != 0){
        cout<<"删除的元素为:"<<endl;
        for (int i = 0; i < T.len; ++i) {
            cout<<"原位置为:"<<T.elem[i]/100+1<<"->"<<T.elem[i]%100<<" ";
            cout<<endl;
        }
    } else{
        cout<<"无重复元素"<<endl;
    }
    //TODO:删除链表中的重复元素
    NodeList head;
    createEnd(head,n);
    cout<<"单链表创建完成:"<<endl;
    Print(head);
    DeletElem(head,T);
    cout<<"单链表删除完成:"<<endl;
    Print(head);
    if (T.len != 0){
        cout<<"删除的元素为:"<<endl;
        for (int i = 0; i < T.len; ++i) {
            cout<<"原位置为:"<<T.elem[i]/100+1<<"->"<<T.elem[i]%100<<" ";
            cout<<endl;
        }
    } else{
        cout<<"无重复元素"<<endl;
    }
    //TODO:单链表的逆置
    ReverseLink(head);
    cout<<"单链表逆置完成:"<<endl;
    Print(head);
}