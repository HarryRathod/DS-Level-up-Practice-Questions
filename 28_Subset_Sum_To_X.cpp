#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &v,int n,int i,int X)
{
    if(i==n)
    {
        if(X==0)
            return 1;
        return 0;
    }
    int inc=countSubsets(v,n,i+1,X-v[i]);
    int exc=countSubsets(v,n,i+1,X);
    return inc+exc;
}

int countSubsets2(vector<int> &v,int n,int i,int X)
{
    if(i==n)
    {
        return 0;
    }
    if(X==v[i])
        return 1;
    int inc=countSubsets(v,n,i+1,X-v[i]);
    int exc=countSubsets(v,n,i+1,X);
    return inc+exc;
}


int main()
{
    vector<int> v={1,2,3,4,5};
    cout<<countSubsets(v,5,0,6)<<endl;
    cout<<countSubsets2(v,5,0,6)<<endl;

    return 0;
}