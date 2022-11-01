#include<bits/stdc++.h>
using namespace std;

int maxSum(int a[],int n)
{
    if(n==0 ||n==1)
        return a[n];
    return max(a[n]+maxSum(a,n-2),maxSum(a,n-1));
}

int maxSum_dp(int a[],int n)
{
    int dp[n];
    dp[0]=a[0];
    dp[1]=a[1];

    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    }
    return dp[n-1];
}

int main()
{
    int a[]={6,10,12,7,9,14};
    int n=sizeof(a)/sizeof(int);

    cout<<maxSum(a,n-1)<<endl;
    cout<<maxSum_dp(a,n)<<endl;

    return 0;
}