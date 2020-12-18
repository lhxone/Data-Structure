#include <iostream>
using namespace std;

#define MAXSIZE 1000//待排顺序表最大长度


typedef int KeyType;        //关键字类型为整数类型
typedef char InfoType;


typedef struct {
    KeyType key;    // 关键字项
    InfoType otherinfo;     //其它数据项
} RcdType;       // 记录类型

typedef struct {
    RcdType r[MAXSIZE+1];
    int length;     // 顺序表长度
} SqList;       // 顺序表类型

void RandInit(SqList &l,int n){
    srand(time(0));
    l.length = n;
    for (int i = 1; i <= l.length; ++i) {
        l.r[i].key=rand()%100;
    }
}

void PrintSqList(SqList l){
    for (int i = 1; i <= l.length; ++i) {
        if (i%5 == 0){
//            printf("%4d\n",l.r[i].key);
            printf("%4d",l.r[i].key);
        } else{
            printf("%4d",l.r[i].key);
        }
    }
    cout<<endl;
}

void SpecialPrint(SqList l,int n){
    cout<<"[";
    for (int i = 1; i < n ; ++i) {
        printf("%4d ",l.r[i].key);
    }
    cout<<l.r[n].key<<"]";
    for (int i = n+1; i < l.length; ++i) {
        printf("%4d ",l.r[i].key);
    }
    printf("%d\n",l.r[l.length].key);
}

void InsertSort(SqList &l){
    int temp,loc;
    for (int i = 2; i <= l.length; ++i) {
        SpecialPrint(l,i-1);
        if (l.r[i].key < l.r[i-1].key){
            temp=l.r[i].key;
            for (int j=i-1;; -- j ){
                if ((temp > l.r[j].key)||(j==0)){
                    loc = j;
                    break;
                }
                l.r[j+1] = l.r[j];
            }
            l.r[loc+1].key = temp;
        }
    }
}

void BiInsertionSort(SqList &l) {
    int high,low,mid;
    for (int i = 2; i <= l.length; ++i) {
        if (l.r[i].key <l.r[i-1].key){
            l.r[0].key = l.r[i].key;
            low=1;
            high=i-1;
            while (low<=high){
                mid=(low+high)/2;
                if (l.r[0].key < l.r[mid].key){
                    high=mid-1;
                } else{
                    low=mid+1;
                }
            }
            for (int j = i - 1; j >= high+1; --j)
                l.r[j+1] = l.r[j];
            l.r[high+1]=l.r[0];
        }
    }
}

void ShellInsert(SqList &l,int dk) {
    for (int i = dk + 1; i <= l.length; ++i) {
        if (l.r[i].key < l.r[i - dk].key) {
            l.r[0] = l.r[i];
            int j;
            for (j = i - dk; j > 0 && (l.r[0].key < l.r[j].key); j -= dk) {
                l.r[j + dk] = l.r[j];
            }
            l.r[j + dk] = l.r[0];
        }
    }
}

void ShellSort(SqList &l,int dlta[]){
    for (int i = 0; i < 3; ++i) {
        ShellInsert(l,dlta[i]);
    }
}

int main() {
    int n,arry[]={5,3,1};
    SqList l;
    cin>>n;
    if (n>1000){
        cout<<"Overflow"<<endl;
    } else{
        RandInit(l,n);
        cout<<"随机初始化后：";
        PrintSqList(l);
        cout<<endl;
//        InsertSort(l);
        BiInsertionSort(l);
//        ShellSort(l,arry);
        cout<<endl;
        cout<<"排序后：";
        PrintSqList(l);
    }
}
