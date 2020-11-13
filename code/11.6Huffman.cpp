#include <iostream>
#include <string.h>
#pragma optimize(O2)

using namespace std;


typedef  struct {
    int  weight ;
    int  parent , lchild , rchild ;
}HTNode , * HuffmanTree ;

typedef  char **HuffmanCode;

void SelectTMin(HuffmanTree HT,int i,int &s1,int &s2){
    int min=30000;
    for (int j = 1; j < i; ++j) {
        if (HT[j].weight<min && HT[j].parent==0){
            min = HT[j].weight;
            s1 = j;
        }
    }
    min = 30000;
    for (int j = 1; j < i; ++j) {
        if (j == s1)
            continue;
        else{
            if (HT[j].weight <min && HT[j].parent==0){
                min = HT[j].weight;
                s2 = j;
            }
        }
    }
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
    if (n<=1)
        return;
    int m = 2*n - 1;
    HT = ( HuffmanTree )malloc((m+1)*sizeof(HTNode));
    int i;
    HuffmanTree p;
    for (i = 1,p = HT+1; i <= n  ; ++i,++ p,++w)
        *p = {*w , 0 ,0 , 0} ;
    int s1,s2;
    for ( i = n+1 ; i<=m ; ++i) {
        SelectTMin( HT , i , s1 ,s2 );//从HT[ 1.. i-1 ]中选两个weight最小的结点s1,s2
        HT[s1].parent = i ;
        HT[s2].parent = i ; //链接父结点
        if (s1>s2)
            swap(s1,s2);
        HT[i].lchild = s1 ;
        HT[i].rchild = s2 ;  //左最小，右次小链接
        HT[i].weight = HT[s1].weight + HT[s2].weight ;
        //修改结点权值
    }
    HC=(HuffmanCode)malloc((n+1)*sizeof(char *)) ;
    char a[]={'a','b','c','d','e','f','g','h'};
    for (i=1 ; i<=n ;++i) {//对n个字符分别求Huffman编码
        int start = n-1 ;
        char *cd =(char *) malloc( n*sizeof(char)); //字符的编码指针
        cd[n-1] = '\0';
        for(int c=i, f=HT[ i ].parent ; f !=0 ; c=f,f= HT[ f ].parent){
            if(HT[f].lchild == c)
                cd[--start] ='0';
            else
                cd[--start] = '1'; //左分支标记0，右分支标记1
        }
        HC[i]=(char *)malloc((n-start)*sizeof(char)) ;
        strcpy(HC[i] , &cd[start]) ; //将cd编码串复制到HC
        printf("%c->%s\n",a[i-1],HC[i]);
        free(cd);
    }
}

void Print(HuffmanTree HT,int n){
    printf("Huffman\tweight\tparent\tlchild\trchild\n");
    for (int i = 1; i < 2*n; ++i) {
        printf("    %2d\t%4d\t%4d\t%4d\t%4d\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
    }
}

int main() {
    int n=8;
    int w[]={5,29,7,8,14,23,3,11};
    HuffmanTree HT;
    HuffmanCode HC;
    HuffmanCoding(HT,HC,w,n);
    Print(HT,8);
    return 0;
}