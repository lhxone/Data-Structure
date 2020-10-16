#include <iostream>

#define MAXSIZE 12500  //非0元的最大个数

using namespace std;

typedef struct {
    int  i , j ;
    int e;
} Triple;

typedef struct{
    Triple data[MAXSIZE+1];
    int mu , nu , tu ;   //矩阵行数,列数,非零元个数
} TSMatrix;

void ReserveMatrix1(TSMatrix m,TSMatrix &n){        //O(nu*tu)
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

void  FastTransSMatrix(TSMatrix  M , TSMatrix &T)
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

int main() {
    int temp,p =0;
    TSMatrix m,n,t;
    m.nu = 5;
    m.mu = 5;
    for (int i = 0; i < m.mu ; ++i) {
        for (int j = 0; j < m.nu; ++j) {
            cin>>temp;
            if (temp != 0){
                m.data[p].i = i;
                m.data[p].j = j;
                m.data[p].e = temp;
                p++;
            }
        }
    }
    m.tu = p;
    cout<<"位置："<<endl;
    for (int i = 0; i < m.tu; ++i) {
        cout<<"("<<m.data[i].i<<","<<m.data[i].j<<")->"<<m.data[i].e<<endl;
    }
    cout<<"矩阵为："<<endl;
    PrintMatrix(m);
    cout<<"转置矩阵为："<<endl;
    ReserveMatrix1(m,n);
    PrintMatrix(n);
    cout<<"第二次转置矩阵为："<<endl;
    FastTransSMatrix(m,t);
    PrintMatrix(t);
}
//
//0 0 0 0 0
//1 2 0 0 3
//0 0 2 0 0
//0 0 0 0 0
//1 2 3 4 5