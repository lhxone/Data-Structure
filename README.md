# Data-Structure


![](https://img.shields.io/badge/Lhxone-Ds-00BFFF)
![](https://img.shields.io/badge/IMU-green)
![](https://img.shields.io/badge/Lhxone-CodeLib-red)
![](https://img.shields.io/badge/PyTorch-yellow)

*****



### This is a notebook written by `Lhxone`, which is used to daily mark the code. 

### I sincerely hope you can star this repository or point out the mistake or error.You can contact with me by <real.lhx@icloud.com>.



```javascript
    function fun(){
         echo: "这是一个Lhxone的数据结构代码库。";
    }
    fun();
```

*****


> 友情链接⬇️
>> 点一下图片就能进入

<div align="center">
    <a href="https://github.com/zhaoolee/ChineseBQB"><img src="https://ss0.bdstatic.com/70cFuHSh_Q1YnxGkpoWK1HF6hhy/it/u=2163258382,1029266130&fm=26&gp=0.jpg"></a>
    <br>
    <small>滑稽表情包</small>
</div>

*****

<div align="center">
    <a href="https://www.bilibili.com/video/BV1fc41187xA"><img src="https://ss3.bdstatic.com/70cFv8Sh_Q1YnxGkpoWK1HF6hhy/it/u=2001773072,2240352109&fm=26&gp=0.jpg" width=""></a>
    <br>
    <small>开哥语录</small>
</div>


*****

#### [自己写的网站，哭着也要改完BUG](https://lhxone.github.io)

*****


### Before — 10.2

#### 源代码点一下右侧➡️[SourceCode1](https://github.com/lhxone/Data-Structure/blob/master/code/before-1.cpp)	[SourceCode2](https://github.com/lhxone/Data-Structure/blob/master/code/before-2.cpp)


1. Before-1
	* 顺序表的创立
	* 顺序表的随机初始化（头插法以及尾插法）
	* 顺序表的定位
	* 顺序表插入删除以及定位元素
	* 求顺序表的交集与并集

2. Before-2
	* 双链表的建立
	* 双链表的随机初始化
	* 双链表的插入删除与合并

*****

### 10.2上机作业：

#### 源代码点一下右侧➡️[SourceCode](https://github.com/lhxone/Data-Structure/blob/master/code/10.2作业.cpp)

1. 
	* 顺序表中删除重复元素
	* 单链表中删除重复元素
2. 单链表的逆置

<img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.2.4.png" width="50%">

*****

### 10.6栈与队列

#### 栈

<img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.6.1.jpeg" width="50%" align="center">

> 栈不存在的条件：base == NULL;
>栈为空的条件： base == top;
>栈满的条件：top-base == stacksize;

1. 初始化栈

	<img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.6.2.png" width="50%" align="center">


2. 获取栈顶元素 top()

	<img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.6.3.jpeg" width="50%" align="center">


3. 入栈 push()

	<img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.6.4.jpeg" width="50%" align="center">


4. 出栈 pop()

	<img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.6.5.jpeg" width="50%" align="center">


#### 练习一：十进制n转为r进制数

```cpp
    int n,d,r;
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
```

#### 练习二：括号匹配

```cpp
    char a[20];
    std::stack<char>(s);
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
```

*****

### 10.9 队列

#### 队列

> 空队列：front == rear
> 满队列：(rear + 1) % max == front

1. 循环队列的初始化

    <img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.9.1.png" width="50%">


2. 入队

    <img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.9.2.png" width="50%">


3. 出队

    <img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.9.3.png" width="50%">


*****

### 10.9 上机

#### 栈与队列的基本操作（内含进制转换与括号匹配[STL模版]）➡️[Sourcecode](https://github.com/lhxone/Data-Structure/blob/master/code/10.9stack&que.cpp)

#### 栈实现计算表达式的值➡️[Sourcecode](https://github.com/lhxone/Data-Structure/blob/master/code/10.9calculate.cpp)

<small><a href="https://www.jianshu.com/p/649c12a80fe8">逆波兰表达式、波兰表达式</a></small>


*****

### 10.13数组，矩阵（稀疏矩阵，特殊矩阵）

#### 稀疏矩阵存储

```cpp
typedef struct {
    int  i , j ;
    int e;
} Triple;

typedef struct{
    Triple data[MAXSIZE+1];
    int mu , nu , tu ;   //矩阵行数,列数,非零元个数
} TSMatrix;

void ReserveMatrix1(TSMatrix m,TSMatrix &n){        //一般转置，O(nu*tu)
    int q;
    n.tu = m.tu;
    n.mu = m.nu;
    n.nu = m.mu;
    if (m.tu){
        q = 1;
        for (int col = 0; col < m.nu; ++col) {        //列遍历
            for (int j = 0; j < m.tu; ++j) {
                if (m.data[j].j == col){
                    n.data[q].i = m.data[j].j;
                    n.data[q].j = m.data[j].i;
                    n.data[q].e = m.data[j].e;
                    q++;
                }
            }
        }
    }
}

void  FastTransSMatrix(TSMatrix  M , TSMatrix &T)       //快速转置，O(nu+tu)
{
    int col,t,p,q,cpot[100],num[100];
    T.mu = M.nu;  T.nu = M.mu ;  T.tu = M.tu;
    if(T.tu) {//num[col]表示矩阵M中第col列中非0元的个数
        for(col=0 ; col<M.nu ; col++)
            num[col]=0;
        for(t=0 ; t<M.tu ; t++)
            ++num[ M.data[t].j ];
        cpot[0]=0;
        for(col=1 ; col<M.nu ; col++)
            cpot[col] = cpot[col-1] + num[col-1];
        for(p=0;p<M.tu;p++) {
            col= M.data[p].j ;  q=cpot[ col ] ;
            T.data[q].i=M.data[p].j ;
            T.data[q].j=M.data[p].i ;
            T.data[q].e=M.data[p].e ;
            ++cpot[col] ; //cpot[col]表示M中col列下一个非0元在T.data中的位置
        }//endfor
    }//endif
}


void PrintMatrix(TSMatrix m){
    int pp=0;
    for (int i = 0; i < m.mu; ++i) {
        for (int j = 0; j < m.nu; ++j) {
            if ((m.data[pp].i == i)&&(m.data[pp].j == j)){
                cout<<m.data[pp].e<<" ";
                pp++;
            } else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}
```

```text
    稀疏矩阵在转置时不能直接交换i，j的值，因为要考虑转置之后的顺序
```

*****

### 10.23 二叉树BinaryTree

#### 上机任务⬇️


!()[https://github.com/lhxone/Data-Structure/raw/master/img/10.23.1.png]


<img src="https://github.com/lhxone/Data-Structure/raw/master/img/10.23.1.png" width="50%">

*****


<div align="center">
    <img src="https://github.com/lhxone/Data-Structure/raw/master/img/git.png" alt="静如止水，动如GitHub">
    <h2>别看了，到底了，一滴都不剩了</h2>
</div>
