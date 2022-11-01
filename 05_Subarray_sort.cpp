#include<bits/stdc++.h>
using namespace std;

vector<int> subArray(vector<int> &v)
{
    int n=v.size();
    vector<int> ans(v);
    sort(ans.begin(),ans.end());

    int i=0;
    while (i<n && v[i]==ans[i])
    {
        i++;
    }

    int j=n-1;
    while (j>=0 && v[j]==ans[j])
    {
        j--;
    }
    if(i==n-1)
        return {-1,-1};
    
    return {i,j};
}




bool helper(vector<int> &v,int i)
{
    if(i==0)
        return v[i]>v[i+1];
    else if(i==v.size()-1)
        return v[i]<v[i-1];
    else
        return (v[i]>v[i+1] || v[i]<v[i-1]);
}

vector<int> subArray2(vector<int> &v)
{
    int i,j;
    int n=v.size();
    int lower=INT_MAX;
    int higher=INT_MIN;
    for(i=0;i<n;i++)
    {
        if(helper(v,i))
        {
            lower=min(lower,v[i]);
            higher=max(higher,v[i]);
        }
    }
    i=0;
    j=n-1;
    while (v[i]<lower)
    {
        i++;
    }

    while (v[j]>higher)
    {
        j--;
    }
    if(lower==INT_MAX)
        return {-1,-1};
    
    return {i,j};
    
}

int main()
{
    vector<int> v{1,2,3,4,5,8,6,7,9,10};

    vector<int> ans=subArray(v);
    for(int x:ans)
        cout<<x<<", ";
    cout<<endl;

    vector<int> ans2=subArray2(v);
    for(int x:ans2)
        cout<<x<<", ";
    cout<<endl;

    return 0;
}