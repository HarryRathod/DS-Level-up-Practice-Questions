#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > triplets(vector<int> v,int sum)
{
    int s;
    int e;
    int n=v.size();
    vector<vector<int> > ans;
    for(int i=0;i<=n-3;i++)
    {
        s=i+1;
        e=n-1;
        while(s<e){
        if(v[i]+v[s]+v[e]==sum){
            ans.push_back({v[i],v[s],v[e]});
            s++;
            e--;
        }
        else if(v[i]+v[s]+v[e]>sum)
            e--;
        else
            s++;
        }
    }

    return ans;
}

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,15};

    vector<vector<int> > ans=triplets(v,18);

    for(int i=0;i<ans.size();i++)
    {
        for(int x=0;x<ans[i].size();x++)
            cout<<ans[i][x]<<", ";
        cout<<endl;
    }

    return 0;
}