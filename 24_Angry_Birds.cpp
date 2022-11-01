#include<bits/stdc++.h>
using namespace std;

bool canPlaceBirds(vector<int> &v,int B,int n,int mid)
{
    int birds=1;
    int location=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]-location>=mid)
        {
            location=v[i];
            birds++;
            if(birds==B)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> v={1,2,4,8,9};
    sort(v.begin(),v.end());
    int B=3;
    int n=v.size();
    int ans=-1;
    int s=0;
    int e=v[n-1]-v[0];

    while(s<=e)
    {
        int mid=(s+e)/2;
        bool canPlace= canPlaceBirds(v,B,n,mid);
        if(canPlace)
        {
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }

    cout<<ans<<endl;

    return 0;
}