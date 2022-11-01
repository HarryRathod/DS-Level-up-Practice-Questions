#include<bits/stdc++.h>
using namespace std;

int rainWater(vector<int> v)
{
    int n=v.size();
    if(n<=2){
        return 0;
    }
    
    int L[n]={0};
    int R[n]={0};

    int ans=0;
    int lm=0;
    int rm=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]>lm)
            lm=v[i];
        if(v[n-i-1]>rm)
            rm=v[n-i-1];
        L[i]=lm;
        R[n-i-1]=rm;
    }

    for(int i=0;i<n;i++)
    {
        ans=ans+(min(L[i],R[i])-v[i]);
    }

    return ans;
}

int main()
{
    vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<rainWater(v)<<endl;

    return 0;
}