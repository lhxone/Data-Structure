#include <iostream>
//#include <stack>
//#include <queue>
#include <iomanip>

#pragma GCC optimize(2)

using namespace std;

typedef struct node {
    int data;
    node *next;
}Qnode,Snode;

typedef struct{
    Qnode *rear,*front;
}Qlink;

typedef struct{
    Snode *base,*top;
}Slink;

void InitStack(Slink &s){
    s.top = s.base = NULL;
}

void push(Slink &s,int n){
    Snode *p;
    p = new (Snode);
    p->data = n;
    p->next = NULL;
    if (s.base == NULL){
        s.top = s.base = p;
    } else{
        s.top->next = p;
        s.top = p;
    }
}

void pop(Slink &s){
    Snode *p;
    p = s.base;
    if (s.base == s.top)
        return;
    while (p->next != s.top) p = p->next;
    s.top = p;
    free(p->next);
    p->next =NULL;
}

int top(Slink s){
    return s.top->data;
}

void InitQue(Qlink &q){
    Qnode *p = new (node);
    p->next = NULL;
    q.rear = q.front = p;
}

void InsertQue(Qlink &q,int n){
    Qnode *p = new (node);
    p->data = n;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;
}

void DelQue(Qlink &q,int &e){
    if (q.front == q.rear){
        return;
    }
    Qnode *p;
    p = q.front;
    e = q.front->next->data;
    q.front = q.front->next;
    free(p);
}

void PrintQue(Qlink q){
    Qnode *p;
    p = q.front->next;
    while (p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main() {
    int temp;
    Qlink q;
    InitQue(q);
    cin>>temp;
    for (int i = 0; i < temp; ++i) {
        InsertQue(q,rand()%100);
    }
    PrintQue(q);
    DelQue(q,temp);
    cout<<endl;
    cout<<temp<<endl;
    PrintQue(q);
    cout<<endl;
    //TODO:
    Slink s;
    InitStack(s);
    cin>>temp;
    for (int i = 0; i < temp; ++i) {
        push(s,rand()%100);
    }
    for (int i = 0; i < temp; ++i) {
        int t = top(s);
        cout<<t<<" ";
        pop(s);
    }
    cout<<endl;
}


/*
 * //TODO:进制转换
 *     int n,d,r;
    std::stack<int>(s);
    std::cin>>n>>r;
    while (n!=0){
        d = n%r;
        n = n/r;
        s.push(d);
    }
    while (!s.empty()){
        std::cout<<s.top();
        s.pop();
    }
*/

/*
 * //TODO:括号匹配
 * char a[20];
    stack<char>(s);
    cin>>a;
    for (int i = 0; a[i] != '\0'; ++i) {
        if (s.empty()){
            s.push(a[i]);
        } else if (((s.top() == '(')&&(a[i] == ')'))||((s.top() == '[')&&(a[i] == ']'))||((s.top() == '{')&&(a[i] == '}'))){
            s.pop();
        } else if (a[i] == '('||a[i] == '['||a[i] == '{'){
            s.push(a[i]);
        }
    }
    if (s.empty()){
        cout<<"YES";
    } else{
        cout<<"NO";
    }
*/
