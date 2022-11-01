#include<bits/stdc++.h>
using namespace std;

int countTrianles(vector<vector<int> > v)
{
    int ans=0;
    unordered_map<int,int> lm,rm;

    for(int i=0;i<v.size();i++)
    {
        lm[v[i][0]]++;
        rm[v[i][1]]++;
    }

    for(int i=0;i<v.size();i++)
    {
        ans+=((lm[v[i][0]]-1)*(rm[v[i][1]]-1));
    }
    return ans;
}

int main()
{
    vector<vector<int> > v={{1,2},
                            {2,0},
                            {2,2},
                            {2,3},
                            {4,2}};

    cout<<countTrianles(v)<<endl;

    return 0;
}