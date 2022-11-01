#include<bits/stdc++.h>
using namespace std;

int countRectangles(vector<vector<int> > v)
{
    int n=v.size();
    unordered_set<int> sl,sr;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sl.insert(v[i][0]);
        sr.insert(v[i][1]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[i][0]!=v[j][0] && v[i][1]!=v[j][1])
            {
                if(sl.count(v[j][0]) && sr.count(v[i][1]) && sl.count(v[i][0]) && sr.count(v[j][1]))
                {
                    ans++;
                }
            }
        }
    }
    return ans/2;
}

int main()
{
    vector<vector<int> > v={{0,0},
                            {0,1},
                            {1,1},
                            {3,1},
                            {1,0},
                            {2,1},
                            {2,0},
                            {3,0}};

    cout<<countRectangles(v)<<endl;

    return 0;
}