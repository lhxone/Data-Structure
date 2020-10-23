#include <iostream>
#include <queue>

using namespace std;

typedef struct node{
    char data;
    node *parent,*left,*right;
}Treenode,*BiTree;

typedef struct BinaryTree{
    Treenode *root;
    int deepth;
    int num;
};

void CreatTree(BiTree &t){
    char c;
    cin>>c;
    if (c == '*'){
        t = NULL;
    } else{
        t = new (node);
        t->data = c;
        CreatTree(t->left);
        CreatTree(t->right);
    }
    return;
}

void BFS(node *pRoot)
{
    if (pRoot==NULL)
        return;

    queue<node*>Q;
    Q.push(pRoot);

    while(!Q.empty())
    {

        node *p = Q.front();

        cout<<p->data<<"->";
        if (p->left!=NULL)
        {
            Q.push(p->left);
        }

        if (p->right!=NULL)
        {
            Q.push(p->right);
        }

        Q.pop();
    }

    cout<<endl;
}

void DFS(node* pRoot)
{
    if (pRoot==NULL){
        return;;
    }
    cout<<pRoot->data<<"->";
    if (pRoot->left!=NULL)
        DFS(pRoot->left);
    if (pRoot->right!=NULL)
        DFS(pRoot->right);
}

void prettyPrintTree(node* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + node->data + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

int TreeDepth(Treenode * pRoot){
    if(pRoot==NULL)
        return 0;
    int left=TreeDepth(pRoot->left)+1;
    int right=TreeDepth(pRoot->right)+1;
    return left>right?left:right;
}

int leaf(Treenode *pRoot,int &sum){
    if (pRoot==NULL){
        return 0;
    }
    if (pRoot->left == NULL){
        sum++;
    }
    if (pRoot->left!=NULL)
        leaf(pRoot->left,sum);
    if (pRoot->right!=NULL)
        leaf(pRoot->right,sum);
    return sum;
}

int main() {
    int sum=0;      //叶子数量
    BinaryTree t;
    CreatTree(t.root);
    DFS(t.root);
    cout<<endl;
    prettyPrintTree(t.root);
    leaf(t.root,sum);
    cout<<"叶子个数为："<<sum<<endl;
    cout<<"深度为："<<TreeDepth(t.root)<<endl;
    return 0;
}
//ABD*F***CE***