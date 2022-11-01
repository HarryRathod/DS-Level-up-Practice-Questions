#include<bits/stdc++.h>
using namespace std;

int longestBand(vector<int> &v)
{
    int n=v.size();
    int maxLength=1;
    unordered_set<int> s;

    for(auto x:v)
        s.insert(x);

    for(int i=0;i<n;i++)
    {
        int parent=v[i]-1;
        if(s.find(parent)==s.end())
        {
            int nextEle=v[i]+1;
            int count=1;
            while(s.find(nextEle)!=s.end())
            {
                count++;
                nextEle++;
            }
            maxLength=max(maxLength,count);
        }
    }
    return maxLength;
}

int main()
{
    vector<int> v{1,9,3,0,18,5,2,4,10,7,12,6};

    cout<<longestBand(v)<<endl;

    return 0;
}