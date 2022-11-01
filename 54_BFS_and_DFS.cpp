#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int> > &matrix,int v=0)
{
    int n=matrix.size();
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(v);
    visited[v]=true;

    while(!q.empty())
    {
        int cv=q.front();
        cout<<cv<<endl;
        q.pop();
        for(int j=0;j<n;j++)
        {
            if(visited[j]==false && matrix[cv][j]!=0)
            {
                visited[j]=true;
                q.push(j);
            }
        }
    }
}

void DFS(vector<vector<int> > &matrix,int s=0)
{
    int n=matrix.size();
    static vector<bool> visited(n,false);
    cout<<s<<endl;
    visited[s]=true;
    for(int i=0;i<n;i++)
    {
        if(matrix[s][i]!=0 && visited[i]==false)
            DFS(matrix,i);
    }
}

int main()
{
    vector<vector<int> > matrix={{0,1,1,1},
                                 {1,0,1,0},
                                 {1,1,0,1},
                                 {1,0,1,0}};

    BFS(matrix);

    cout<<"DFS:"<<endl;
    DFS(matrix,0);

    return 0;
}