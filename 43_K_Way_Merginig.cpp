#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int parent;
    int idx;
};

class compare
{
    public:
    bool operator()(node a,node b)
    {
        return a.data>b.data;
    }
};

void kWayMerging(vector<vector<int> > v)
{
    int k=v.size();
    priority_queue<node,vector<node>,compare> q;
    for(int i=0;i<k;i++)
    {
        q.push({v[i][0],i,1});
    }
    while (!q.empty())
    {
        node temp=q.top();
        q.pop();
        cout<<temp.data<<", ";
        if(temp.idx<v[temp.parent].size())
        {
            q.push({v[temp.parent][temp.idx],temp.parent,temp.idx+1});
        }
    }
}

int main()
{
    vector<vector<int> > v={{1,3,15},
                            {2,4,6},
                            {0,9,10,11}};

    kWayMerging(v);

    return 0;
}