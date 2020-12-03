#include <iostream>
#include <stack>
#include <queue>
#pragma optmize(o2)
#define MAX_VERTEX_NUM 20
#define infoType int
#define VertexType char

using namespace std;

typedef struct ArcNode //表结点
{	VertexType adjvex;
	struct ArcNode *nextarc = NULL;
	infoType info;
}ArcNode;     //体现边的信息

typedef struct Vnode//头结点
{	VertexType data;
	ArcNode *firstarc = NULL;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{	AdjList vertices; //顶点数组
	int vexnum,arcnum; //顶点数，弧的条数
	int kind; //图的种类
}ALGraph;

int visited[10];

void Init(ALGraph &g){
    ArcNode* temp = NULL,*p = NULL;
    cin>>g.vexnum;
    for (int i = 0; i < g.vexnum; ++i) {
        cin>>g.vertices[i].data;
        temp = new (ArcNode);
        while ((cin>>temp->adjvex)&&(temp->adjvex != '*')){
            if (g.vertices[i].firstarc == NULL){
                g.vertices[i].firstarc = temp;
                p = temp;
            } else{
                p->nextarc = temp;
                temp->nextarc = NULL;
                p = temp;
            }
            temp = new (ArcNode);
        }
    }
}

void Print(ALGraph g){
    for (int i = 1; i <= g.vexnum; ++i) {
        cout<<g.vertices[i].data;
        for (ArcNode *p = g.vertices[i].firstarc;  p != NULL; p = p->nextarc) {
            cout<<"->"<<p->adjvex;
        }
        cout<<endl;
    }
}

/*
void DFS(ALGraph g,int v){
    visited[v] = 1;
    cout<<"->"<<g.vertices[v].data;
    for (ArcNode *p = g.vertices[v].firstarc;p;p = p->nextarc){
        if (!visited[p->adjvex-'0']){
            DFS(g,p->adjvex-'0');
        }
    }
}

void DFSTraverse(ALGraph g,int &count){
    for (int i = 1; i <= g.vexnum; ++i) {
        if (!visited[i]){
            DFS(g,i);
            visited[i] = 1;
        }
    }
    cout<<endl;
}

void BFS(ALGraph g,int v){
    if (!visited[v]) cout<<"->"<<v;
    visited[v] = 1;
    queue<int>(q);
    for (ArcNode *p = g.vertices[v].firstarc;p;p = p->nextarc){
        if (!visited[p->adjvex-'0']){
            cout<<"->"<<p->adjvex;
            visited[p->adjvex-'0'] = 1;
            q.push(p->adjvex - '0');
        }
    }
    while (!q.empty()){
        BFS(g,q.front());
        q.pop();
    }
}

void BFSTraverse(ALGraph g,int &count){
    for (int i = 1; i <= g.vexnum; ++i) {
        if (!visited[i]){
            BFS(g,i);
            visited[i] = 1;
        }
    }
    cout<<endl;
}
*/

void FindInDegree(ALGraph g,int *indegree){
    for (int i = 0; i < g.vexnum; ++i) {
        for (ArcNode *p = g.vertices[i].firstarc;  p ; p = p->nextarc) {
            indegree[p->adjvex - '0']++;
        }
    }
}

int TopologicalSortQ(ALGraph g){
    int *indegree;
    indegree = (int*)malloc(g.arcnum*sizeof(int));
    queue<int>(q);
    FindInDegree(g,indegree);//求各顶点入度的数组indegree
    for(int i=0 ; i <g.vexnum ; ++i ){
        if(indegree[i]==0){
            q.push(i);//入度为0的顶点入栈
        }
    }
    int count=0,i;
    while(!q.empty()){
        i = q.front();
        q.pop();
        cout<<"->"<<i;
        count++;//输出栈顶i顶点并计数
        for(ArcNode *p=g.vertices[i].firstarc; p; p = p->nextarc){
            int k=p->adjvex - '0';
            indegree[k]--;//将此顶点的所有邻接点入度减1
            if(indegree[k]==0)
                q.push(k);//如果入度为零时入栈
        }
    }
    if(count<g.vexnum)
        return 0; //有向图有回路报错
    else
        return 1;
}

int TopologicalSortS(ALGraph g){
    int *indegree;
    indegree = (int*)malloc(g.arcnum*sizeof(int));
    stack<int>(s);
    FindInDegree(g,indegree);//求各顶点入度的数组indegree
    for(int i=0 ; i <g.vexnum ; ++i ){
        if(indegree[i]==0){
            s.push(i);//入度为0的顶点入栈
        }
    }
    int count=0,i;
    while(!s.empty()){
        i = s.top();
        s.pop();
        cout<<"->"<<i;
        count++;//输出栈顶i顶点并计数
        for(ArcNode *p=g.vertices[i].firstarc; p; p = p->nextarc){
            int k=p->adjvex - '0';
            indegree[k]--;//将此顶点的所有邻接点入度减1
            if(indegree[k]==0)
                s.push(k);//如果入度为零时入栈
        }
    }
    if(count<g.vexnum)
        return 0; //有向图有回路报错
    else
        return 1;
}


int main() {
    freopen("../Matrix.txt", "r", stdin);
    ALGraph g;
    int count = 0;
    int *indegree;
    Init(g);
    indegree = (int *) malloc(g.arcnum * sizeof(int));
    Print(g);
    int flag;
    cout<<"拓扑排序Q：";
    flag = TopologicalSortQ(g);

    cout << endl ;
    cout<<"拓扑排序S：";
    flag = TopologicalSortS(g);
}