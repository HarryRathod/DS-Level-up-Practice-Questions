#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int> > &grid,vector<vector<bool> > &visited,int i,int j,int m,int n)
{
    if(i<0 || i>=m || j<0 || j>=n)
        return 0;
    if(grid[i][j]==1 && visited[i][j]==false)
    {
        visited[i][j]=true;
        return 1+helper(grid,visited,i,j+1,m,n)+helper(grid,visited,i,j-1,m,n)+helper(grid,visited,i+1,j,m,n)+helper(grid,visited,i-1,j,m,n);
    }
    return 0;
}

int helper2(vector<vector<int> > &grid,vector<vector<bool> > &visited,int i,int j,int m,int n)
{
    visited[i][j]=true;

    int cs=1;

    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    for(int k=0;k<4;k++)
    {
        int nx=i+dx[k];
        int ny=j+dy[k];

        if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && visited[nx][ny]==false)
        {
            int subComponent=helper2(grid,visited,nx,ny,m,n);
            cs+=subComponent;
        }
    }
    return cs;
}

int largestIsland(vector<vector<int> > &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool> > visited(m,vector<bool>(n,false));
    int ans=INT_MIN;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==false && grid[i][j]==1)
            {
                int smallAns=helper(grid,visited,i,j,m,n);
                ans=max(ans,smallAns);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int> > grid={{1,0,0,1,0},
                               {1,0,1,0,0},
                               {0,0,1,0,1},
                               {1,0,1,1,1},
                               {1,0,1,1,0}};
    
    cout<<largestIsland(grid)<<endl;

    return 0;
}