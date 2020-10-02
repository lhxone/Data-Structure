#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *next;
}*LinkList;

typedef struct SqList {
    int *elem;
    int len;
    int size;
}*SList;

void CreatList(LinkList &L,int n){
    LinkList p;
    L = new (node);
    L->next = NULL;
    for (int i = 0; i < n; ++i) {
        p = (LinkList) malloc(sizeof(node));
        p->data = abs(n/2-i);
        p->next = L->next;
        L->next = p;
    }
}

void CreatList(SqList &L,int n){
    L.elem  = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        L.elem[i] = rand()%100;
    }
    L.len = n;
}

void PrintList(LinkList L){
    int sum=0;
    for (LinkList p=L->next;p != NULL;p = p->next){
        cout<<p->data<<" ";
        sum++;
    }
    cout<<endl;
//    cout<<endl<<sum<<endl;
}

void PrintList(SqList L){
    for (int i = 0; i < L.len; ++i) {
        cout<<L.elem[i]<<" ";
        if ((i+1)%5 == 0){
            cout<<endl;
        }
    }
    cout<<endl;
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

void DeletElem(LinkList &L){
    int i=0,j=0;
    LinkList head = L;
    LinkList p,q;
    for(p = head;p->next != NULL;p = p->next,i++){
        for(q = p;q->next != NULL;q = q->next,j++){
            if (p->data == q->next->data){
                Delet(L,i+j);
            }
        }
        j=0;
    }
    return;
}

void DeletElem(SqList &L,SqList &T){
    T.len = 0;
    T.elem = (int *)malloc(L.len * sizeof(int ));
    for (int i = 0; i <L.len; ++i) {
        for (int j = i+1; j < L.len; ++j) {
            if (L.elem[j] == L.elem[i]){
                for (int k = j; k < L.len - 1; ++k) {
                    L.elem[k] = L.elem[k+1];
                }
                T.elem[T.len++] = L.elem[i]+i*100;
                L.len--;
            }
        }
    }
}

int main()
{
    int n;
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
    
}