#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *parent,*left,*right;
}Treenode,*BiTree;

typedef struct BinaryTree{
    Treenode *root;
    int deepth;
    int num;
};

int Find(int p[],int key){
    int n=sizeof(p);
    for(int i=0;i <= n;i++)
        if (p[i] == key)
            return 1;
    return 0;
}

//11,32,45,17,90,22,14,2,97
//2 11 14 17 22 32 45 90 97
int FindB(int p[],int key){
    int n=sizeof(p)+1;
    int mid,low=0,high=n;
    while (low<=high){
        mid = (low + high)/2;
        if (key==p[mid]){
            return 1;
        } else if (key < p[mid]){
            high = mid - 1;
        } else if (key > p[mid]){
            low = mid +1;
        }
    }
    return 0;
}

int BST_Insert(BiTree &T, int k)
{
    if(T == NULL)
    {
        T = new node;
        T->data = k;
        T->left = NULL;
        T->right = NULL;
        return 1;
    }
    else if(k == T->data)
        return 0;
    else if(k < T->data)
        if (k > T->left->data){

        }
        return BST_Insert(T->left, k);
    else
        return BST_Insert(T->right, k);
}

void Create_BST(BiTree &T, int arr[], int n)
{
    T = NULL;
    for(int i=-n/2; i<n/2; ++i)
        BST_Insert(T, arr[abs(i)]);
}

void prettyPrintTree(node* node, string prefix = "", bool isLeft = true) {
    if (node == NULL) {
        cout << "Empty tree";
        return;
    }
    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
    cout << prefix + (isLeft ? "└── " : "┌── ") << node->data <<"\n";
    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

int main() {
    int arry[] = {11,32,45,17,90,22,14,2,97},key=11;
    BinaryTree t;
    t.root = NULL;
    cout<<"数组为:";
    for(int i=0;(cout<<arry[i]<<" ")&&(i<sizeof(arry)/sizeof(int)-1);i++);
    cout<<endl<<"输入要查找的key:";
    cin>>key;
    cout<<"顺序查找:";
    if (Find(arry,key)){
        cout<<"Yes"<<endl;
    } else{
        cout<<"No"<<endl;
    }
    sort(arry,arry+8);
    cout<<"排序后数组为:";
    for(int i=0;(cout<<arry[i]<<" ")&&(i<sizeof(arry)/sizeof(int)-1);i++);
    cout<<endl<<"二分查找:";
    if (FindB(arry,key)){
        cout<<"Yes"<<endl;
    } else{
        cout<<"No"<<endl;
    }
    Create_BST(t.root,arry,9);
    prettyPrintTree(t.root);
}
