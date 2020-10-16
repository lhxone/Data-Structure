#include<iostream>
#include<cstdio>
#include<cctype>
#include<stack>

#pragma GCC optimize(2)

using namespace std;

//stack<char> OPTR;
//stack<double> OPND;

typedef struct node {
    char data;
    node *next;
}Qnode,Snode;

typedef struct Cnode {
    int data;
    Cnode *next;
}SnodeC;

typedef struct{
    Qnode *rear,*front;
}Qlink;

typedef struct{
    SnodeC *base,*top;
}SlinkC;

typedef struct {
    Snode *base, *top;
}Slink;

template<class T>
void InitStack(T &s){
    s.top = s.base = NULL;
}

//void InitStack(Slink &s){
//    s.top = s.base = NULL;
//}
//
//void InitStack(SlinkC &s){
//    s.top = s.base = NULL;
//}

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

void push(SlinkC &s,char n){
    SnodeC *p;
    p = new (SnodeC);
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
    if ((s.base == s.top)&&(s.base != NULL)){
        free(s.base);
        s.base = s.top = NULL;
        return;
    }
    while (p->next != s.top) p = p->next;
    s.top = p;
    free(p->next);
    p->next =NULL;
}

void pop(SlinkC &s){
    SnodeC *p;
    p = s.base;
    if ((s.base == s.top)&&(s.base != NULL)){
        free(s.base);
        s.base = s.top = NULL;
        return;
    }
    while (p->next != s.top) p = p->next;
    s.top = p;
    free(p->next);
    p->next =NULL;
}

int top(Slink s){
    return s.top->data;
}

char top(SlinkC s){
    return s.top->data;
}

template<class T>
int empty(T s){
    if (s.base == NULL)
        return 1;
    else
        return 0;
}

int getIndex(char theta)        //中文"（"与"）"不可用
{
    int index = 0;
    switch (theta)
    {
        case '+':
            index = 0;
            break;
        case '-':
            index = 1;
            break;
        case '*':
            index = 2;
            break;
        case '/':
            index = 3;
            break;
        case '(':
            index = 4;
            break;
        case ')':
            index = 5;
            break;
        case '#':
            index = 6;
        default:break;
    }
    return index;
}

char Precede(char theta1, char theta2)
{
    const char priority[][7] =          //优先度
            {
                    { '>','>','<','<','<','>','>' },
                    { '>','>','<','<','<','>','>' },
                    { '>','>','>','>','<','>','>' },
                    { '>','>','>','>','<','>','>' },
                    { '<','<','<','<','<','=','0' },
                    { '>','>','>','>','0','>','>' },
                    { '<','<','<','<','<','0','=' },
            };

    int index1 = getIndex(theta1);
    int index2 = getIndex(theta2);
    return priority[index1][index2];
}

double calculate(double b, char theta, double a)
{
    switch (theta)
    {
        case '+':
            return b + a;
        case '-':
            return b - a;
        case '*':
            return b * a;
        case '/':
            return b / a;
        default:
            break;
    }
}

double getAnswer(SlinkC &OPTR,Slink &OPND)
{
    push(OPTR,'#');
    int counter = 0;            //用来记录数字的位数
    char c = getchar();
    while (c != '#' || top(OPTR) != '#')
    {
        if (isdigit(c))     //判断是否是数字
        {
            if (counter == 1)
            {
                double t = top(OPND);      //保留栈顶
                pop(OPND);
                push(OPND,t * 10 + (c - '0'));
                counter = 1;
            }
            else
            {
                push(OPND,c - '0');
                counter++;          //第二位也是数字，则counter变为1，弹出原有数字并压入新的数字
            }
            c = getchar();
        }
        else
        {
            counter = 0;        //数字结束
            switch (Precede(top(OPTR), c))
            {
                case '<':
                    push(OPTR,c);
                    c = getchar();
                    break;
                case '=':
                    pop(OPTR);
                    c = getchar();
                    break;
                case '>':
                    char theta = top(OPTR);
                    pop(OPTR);
                    double a = top(OPND);
                    pop(OPND);
                    double b = top(OPND);
                    pop(OPND);
                    push(OPND,calculate(b, theta, a));
            }
        }
    }
    return top(OPND);
}

template<class T>
void clearstack(T s)      //清空栈
{
    while (!empty(s))
        pop(s);
}


int main()
{
    Slink OPND;
    SlinkC OPTR;
    InitStack(OPND);
    InitStack(OPTR);
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        clearstack(OPND);
        clearstack(OPTR);
        double ans = getAnswer(OPTR,OPND);
        cout << ans << endl<< endl;
        getchar();
    }
    return 0;
}