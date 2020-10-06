# Data-Structure


![](https://img.shields.io/badge/Lhxone-Ds-00BFFF)
![](https://img.shields.io/badge/IMU-green)
![](https://img.shields.io/badge/Lhxone-CodeLib-red)
![](https://img.shields.io/badge/PyTorch-yellow)

*****

### This is a notebook written by `Lhxone`, which is used to daily mark the code. 

### I sincerely hope you can star this repository or point out the mistake or error.You can contact with me by <real.lhx@icloud.com>.

### Welcome, the <a href = "https://github.com/lhxone/Data-Structure"><img border="0" src="http://cc.amazingcounters.com/counter.php?i=3245838&c=9737827" alt="Visitor"></a> th Visitor.


```javascript
    function fun(){
         echo "这是一个Lhxone的数据结构代码库。";
    }
    fun();
```


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

