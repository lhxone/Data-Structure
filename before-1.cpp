#include <iostream>
#define List_Size 100
using namespace std;

struct SqList{
    int *elem;
    int len;
    int size;
};

//TODO List

bool InitList(SqList &L);

bool RandInitList(SqList &L,int n);

bool ListInsert(SqList &L,int i,int e);

bool PrintList(SqList L);

bool DeletList(SqList &L,int n);

int LocateElem(SqList L,int elem);

int comp(const void*a,const void*b);

bool IntersectionElem(SqList La,SqList Lb);

SqList *MergeList(SqList La,SqList Lb);

//TODO function

bool InitList(SqList &L){
    L.elem=(int *)malloc(List_Size*sizeof(int));
    if (!L.elem){
        exit(-2);
    }
    L.len = 0;
    L.size = List_Size;
    return 1;
}

bool RandInitList(SqList &L,int n){
    if (n>=0&&n<List_Size&&InitList(L)==1){
        for (int i = 0; i < n; ++i) {
            L.elem[i] = rand()%100;
        }
        L.len = n;
        return 1;
    }
    return 0;
}

bool ListInsert(SqList &L,int i,int e){
    if (i<1||i>L.len + 1){
        return 0;
    }
    if (L.len > L.size){
        int *newbase = (int *)realloc(L.elem,(L.size+1)*sizeof(int));
        if (!newbase)
            exit(-2);
        L.elem = newbase;
        L.size += 1;
    }
    int *q=&(L.elem[i-1]);
    for (int *p = &(L.elem[L.len - 1]); p>=q; --p) {
        *(p+1) = *p;
    }
    *q = e;
    ++L.len;
    return 1;
}

bool PrintList(SqList L){
    for (int i = 0; i < L.len; ++i) {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}

bool DeletList(SqList &L,int n){
    if (n < 1||n>L.len){
        return 0;
    } else{
        for (int i = n; i < L.len; ++i) {
            L.elem[i-1] = L.elem[i];
        }
        L.len--;
        return 1;
    }
}

int LocateElem(SqList L,int elem){
    for (int i = 0; i < L.len; ++i) {
        if (L.elem[i] == elem){
            return i+1;
        }
    }
    return 0;
}

int comp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

SqList *MergeList(SqList La,SqList Lb){
    SqList L;
    InitList(L);
    int i=0,j=0,k=0;
    while ((i < La.len)&&(j < Lb.len)){
        if (La.elem[i]<Lb.elem[j]){
            L.elem[k] = La.elem[i];
            i++;
            k++;
        } else{
            L.elem[k] = Lb.elem[j];
            j++;
            k++;
        }
    }
    if (i == La.len){
        for (int l = j; l < Lb.len; ++l) {
            L.elem[k++] = Lb.elem[l];
        }
    } else{
        for (int l = i; l < La.len; ++l) {
            L.elem[k++] = La.elem[l];
        }
    }
    L.len = La.len + Lb.len;
    return &L;
}

bool IntersectionElem(SqList La,SqList Lb){
    int Min = min(La.len,Lb.len),flag= false;
    if (Min == La.len){
        for (int i = 0; i < La.len; ++i) {
            for (int j = 0; j < Lb.len; ++j) {
                if (La.elem[i] == Lb.elem[j]){
                    if (flag){
                        printf("%d ",La.elem[i]);
                        break;
                    } else{
                        flag = true;
                        printf("交集元素为：\n");
                        printf("%d ",La.elem[i]);
                        break;
                    }
                }
            }
        }
    } else{
        for (int i = 0; i < Lb.len; ++i) {
            for (int j = 0; j < La.len; ++j) {
                if (Lb.elem[i] == La.elem[j]){
                    if (flag){
                        printf("%d ",Lb.elem[i]);
                        break;
                    } else{
                        flag = true;
                        printf("交集元素为：\n");
                        printf("%d ",Lb.elem[i]);
                        break;
                    }
                }
            }
        }
    }
    return flag;
}

//TODO Main Function

int main() {
    int n,oper,insert_loc,insert_elem,delet_loc,find_elem;
    SqList La,Lb;
    printf("开始初始化，输入元素个数：\n");
    cin>>n;
    if (RandInitList(La,n)&&(RandInitList(Lb,n))){
        printf("随机初始化成功,list为：\n");
        PrintList(La);
        PrintList(Lb);
    } else{
        printf("初始化失败\n");
    }
    do {
        printf("__________________\n"
               "输入操作：\n"
               "1:插入\n"
               "2:删除\n"
               "3:查找\n"
               "4:排序\n"
               "5:合并\n"
               "6:交集\n"
               "0:退出\n"
               "___________________\n");
        scanf("%d",&oper);
        switch (oper) {
            case 1:{
                printf("输入插入的位置以及插入的元素：");
                scanf("%d %d",&insert_loc,&insert_elem);
                if (ListInsert(La,insert_loc,insert_elem)){
                    printf("插入成功，list为：\n");
                    PrintList(La);
                } else{
                    printf("插入失败\n");
                }
                break;
            }
            case 2:{
                printf("请输入删除的位置：\n");
                scanf("%d",&delet_loc);
                if (DeletList(La,delet_loc)){
                    printf("删除成功，删除后的list为：\n");
                    PrintList(La);
                } else{
                    printf("删除失败\n");
                }
                break;
            }
            case 3:{
                printf("请输入要查找的元素：\n");
                scanf("%d",&find_elem);
                if (int i=LocateElem(La,find_elem)){
                    printf("查找成功，位置为：%d\n",i);
                } else{
                    printf("查找失败\n");
                }
                break;
            }
            case 4:{
                qsort(La.elem,La.len,sizeof(int),comp);
                qsort(Lb.elem,Lb.len,sizeof(int),comp);
                printf("排序完成\n");
                PrintList(La);
                PrintList(Lb);
                break;
            }
            case 5:{
                qsort(La.elem,La.len,sizeof(int),comp);
                qsort(Lb.elem,Lb.len,sizeof(int),comp);
                printf("排序完成\n");
                SqList *pL=MergeList(La,Lb);
                printf("合并完成，list为：\n");
                PrintList(*pL);
                break;
            }
            case 6:{
                if (IntersectionElem(La,Lb)){
                    printf("\n");
                } else{
                    printf("无交集元素\n");
                }
                break;
            }
            case 0:{
                exit(0);
            }
            default:{
                printf("无此操作\n");
                break;
            }
        }
    }while (oper != 0);
    return 0;
}
}