#include<bits/stdc++.h>
using namespace std;

int frogMinCost(int a[],int n,int i)
{
    if(i<=0)
        return 0;
    if(i==n-1)
        return 0;
    if(i==1)
    {
        return abs(a[1]-a[0]);
    }

    for(int j=i;j<n;j++)
    {
        return min(frogMinCost(a,n,i-2)+abs(a[i]-a[i-2]),frogMinCost(a,n,i-1)+abs(a[i]-a[i-1]));
    }
    return INT_MAX;
}

int frogMinCost_dp(int a[],int n)
{
    int dp[n];
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);

    for(int i=2;i<n;i++)
    {
        dp[i]=min(dp[i-2]+abs(a[i]-a[i-2]),dp[i-1]+abs(a[i]-a[i-1]));
    }
    return dp[n-1];
}

int main()
{
    int a[]={10,30,40,20};
    int n=sizeof(a)/sizeof(int);

    cout<<frogMinCost(a,n,2)<<endl;
    cout<<frogMinCost_dp(a,n)<<endl;

    return 0;
}
