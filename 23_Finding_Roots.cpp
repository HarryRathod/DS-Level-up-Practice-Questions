#include<bits/stdc++.h>
using namespace std;

float findingRoot(int n,int p)
{
    int s=0;
    int e=n-1;
    float ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(mid*mid==n)
            return mid;
        else if(mid*mid<n)
        {
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }

    float inc=0.1;
    for(int i=0;i<p;i++)
    {
        while(ans*ans<=n)
            ans+=inc;
        ans-=inc;
        inc/=10;
    }    
    return ans;
}

int main()
{
    cout<<findingRoot(10,3)<<endl;

    return 0;
}