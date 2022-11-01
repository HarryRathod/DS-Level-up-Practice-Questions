#include<bits/stdc++.h>
using namespace std;

int countBST(int n)
{
    /// This is Recursive Solution & it will take Exponential OOT.(O[2^n]). 
    if(n==0 || n==1)
        return 1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=countBST(i-1);
        int y=countBST(n-i);
        ans+=(x*y);
    }
    return ans;
}

int countBST_dp(int n,int dp[])
{
    /// This is Top Down DP Solution & it will take OOT as O[n^2].
    if(n==0 || n==1)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=countBST_dp(i-1,dp);
        int y=countBST_dp(n-i,dp);
        ans+=(x*y);
    }
    return dp[n]=ans;
}

int countBST_dp2(int n)
{
    /// This is Bottom Up DP Solution & it will take O[n^2] but it is Iterative not Recursive.
    int dp[n+1]={0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i]+=(dp[j-1]*dp[i-j]);
        }
    }
    return dp[n];
}

int main()
{
    int n=3;
    int dp[n+1]={0};

    cout<<countBST(n)<<endl;
    cout<<countBST_dp(n,dp)<<endl;

    cout<<countBST_dp2(n)<<endl;

    return 0;
}