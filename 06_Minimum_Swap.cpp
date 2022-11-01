#include<bits/stdc++.h>
using namespace std;

int minSwap(vector<int> &v)
{
    int n=v.size();
    int ans=0;

    pair<int,int> a[n];
    for(int i=0;i<n;i++)
    {
        a[i].first=v[i];
        a[i].second=i;
    }

    sort(a,a+n);

    vector<bool> visited(n,false);

    for(int i=0;i<n;i++)
    {
        int old_node=a[i].second;
        if(visited[i]==true || old_node==i)
            continue;
        
        int node=i;
        int cycle=0;
        while (visited[node]!=true)
        {
            visited[node]=true;
            int new_node=a[node].second;
            node=new_node;
            cycle+=1;
        }
        ans+=(cycle-1);
    }
    return ans;
}

int main()
{
    vector<int> v{10,11,5,4,3,2,1};

    cout<<minSwap(v)<<endl;

    return 0;
}