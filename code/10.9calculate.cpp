#include<iostream>
#include<cstdio>
#include<cctype>
#include<stack>

#pragma GCC optimize(2)

using namespace std;

stack<char> OPTR;
stack<double> OPND;

int getIndex(char theta)
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

double getAnswer()
{
    OPTR.push('#');
    int counter = 0;
    char c = getchar();
    while (c != '#' || OPTR.top() != '#')
    {
        if (isdigit(c))
        {
            if (counter == 1)
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
        else
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
                    double a = OPND.top();
                    OPND.pop();
                    double b = OPND.top();
                    OPND.pop();
                    OPND.push(calculate(b, theta, a));
            }
        }
    }
    return OPND.top();
}

void clearstack()
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