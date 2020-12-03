#include <iostream>
#include <queue>
#define MAX_N 8

using namespace std;

typedef struct {
    int arcs[MAX_N][MAX_N];
    int vexnum;
}MGraph;

int visited[MAX_N];

void DFS(MGraph g,int v){
    visited[v] = 1;
    cout<<"->"<<v+1;
    for (int i = 0; i < MAX_N; ++i) {
        if ((g.arcs[v][i] == 1)&&(visited[i] != 1)){
            DFS(g,i);
            visited[i] = 1;
        }
    }
}

void DFSTraverse(MGraph g,int &count){
    for (int i = 0; i < MAX_N; ++i) {
        if (!visited[i]){
            DFS(g,i);
            count++;
        }
        cout<<endl;
    }
    cout<<endl;
}

void BFS(MGraph g,int v){
    if (!visited[v]) cout<<"->"<<v+1;
    visited[v] = 1;
    queue<int>(q);
    for (int i = 0; i < MAX_N; ++i) {
        if ((g.arcs[v][i] == 1)&&(visited[i] != 1)){
            cout<<"->"<<i+1;
            visited[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()){
        BFS(g,q.front());
        q.pop();
    }
}

void BFSTraverse(MGraph g,int &count){
    for (int i = 0; i < MAX_N; ++i) {
        if (!visited[i]){
            BFS(g,i);
            count++;
        }
        cout<<endl;
    }
    cout<<endl;
}

void PrintGraph(MGraph g){
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            cout<<g.arcs[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int count = 0;
    MGraph g;
    freopen("../arcs.txt","r",stdin);
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            cin>>g.arcs[i][j];
        }
    }
    cout<<"DFS:";
    DFSTraverse(g,count);
    if (count == 1){
        cout<<"是连通图"<<endl;
    } else{
        cout<<"连通分量为："<<count<<endl;
    }

    memset(visited,0,sizeof(visited));
    count = 0;

    cout<<"BFS:";
    BFSTraverse(g,count);
    if (count == 1){
        cout<<"是连通图"<<endl;
    } else{
        cout<<"连通分量为："<<count<<endl;
    }
    PrintGraph(g);
}