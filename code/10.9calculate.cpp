#include<iostream>
#include<cstdio>
#include<cctype>
#include<stack>

#pragma GCC optimize(2)

using namespace std;

stack<char> OPTR;
stack<double> OPND;

int getIndex(char theta)        //将运算符转为下标
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

char Precede(char theta1, char theta2)          //计算优先度
{
    const char priority[][7] =
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

double calculate(double b, char theta, double a)        //根据theta计算结果
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

double getAnswer()
{
    OPTR.push('#');
    int counter = 0;
    char c = getchar();
    while (c != '#' || OPTR.top() != '#')
    {
        if (isdigit(c))         //如果是数字则进入OPND栈中
        {
            if (counter == 1)       //可能为两位数或者是更多位数，所以要先判断前一个数是否为数字
            {
                double t = OPND.top();
                OPND.pop();
                OPND.push(t * 10 + (c - '0'));
                counter = 1;
            }
            else
            {
                OPND.push(c - '0');
                counter++;
            }
            c = getchar();
        }
        else        //如果是运算符，则判断
        {
            counter = 0;
            switch (Precede(OPTR.top(), c))
            {
                case '<':
                    OPTR.push(c);
                    c = getchar();
                    break;
                case '=':
                    OPTR.pop();
                    c = getchar();
                    break;
                case '>':
                    char theta = OPTR.top();
                    OPTR.pop();
                    double a = OPND.top();          //计算a与b运算的值，并将运算得到的结果压入栈中
                    OPND.pop();
                    double b = OPND.top();
                    OPND.pop();                     //弹出a，b，并将运算结果存入
                    OPND.push(calculate(b,theta,a));
            }
        }
    }
    return OPND.top();
}

void clearstack()       //清空栈
{
    while (!OPTR.empty())
        OPTR.pop();
    while (!OPND.empty())
        OPND.pop();
}

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        clearstack();
        double ans = getAnswer();
        cout << ans << endl<< endl;
        getchar();
    }
    return 0;
}