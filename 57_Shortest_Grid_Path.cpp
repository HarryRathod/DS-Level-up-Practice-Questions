#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int x;
    int y;
    int dist;

    node(int x,int y,int dist)
    {
        this->x=x;
        this->y=y;
        this->dist=dist;
    }
};

class cmp
{
public:
    bool operator()(const node &a,const node &b)
    {
        return a.dist<=b.dist;
    }
};

int  shortestPath(vector<vector<int> > &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    set<node,cmp> s;
    vector<vector<int> > dist(m+1,vector<int>(n+1,INT_MAX));
    dist[0][0]=grid[0][0];

    s.insert(node(0,0,dist[0][0]));

    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};

    while(!s.empty())
    {
        auto f=s.begin();
        int cy=f->y;
        int cd=f->dist;
        int cx=f->x;
        s.erase(f);

        for(int k=0;k<4;k++)
        {
            int nx=cx+dx[k];
            int ny=cy+dy[k];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && cd+grid[nx][ny]<dist[nx][ny])
            {
                int fd=cd+grid[nx][ny];
                node fn(nx,ny,fd);
                if(s.find(fn)!=s.end())
                {
                    s.erase(s.find(fn));
                }
                dist[nx][ny]=fd;
                s.insert(node(nx,ny,fd));
            }
        }
    }
    return dist[m-1][n-1];
}

int main()
{
    vector<vector<int> > grid={{31,100,65,12,18},
                               {10,13,47,157,6},
                               {100,113,174,11,33},
                               {88,124,41,20,140},
                               {99,32,111,41,20}};

    cout<<shortestPath(grid)<<endl;

    return 0;
}