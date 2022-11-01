#include<bits/stdc++.h>
using namespace std;

int ladder(int n)
{
    if(n==0 || n==1)
        return 1;
    if(n==2)
        return 2;
    return ladder(n-1)+ladder(n-2)+ladder(n-3);
}

int ladder2(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int ladder3(int n,int k)
{
    int dp[n+1];
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
                ans+=dp[i-j];
        }
        dp[i]=ans;
    }
    return dp[n];
}

int ladder4(int n,int k)
{
    int dp[n+1];
    dp[0]=1;
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans+=dp[i-1];
        dp[i]=ans;
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i]=(2*dp[i-1]-dp[i-k-1]);
    }
    return dp[n];
}

int ladder5(int n,int k)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;

    int ans=0;
    for(int i=1;i<=k;i++)
        ans+=ladder5(n-i,k);

    return ans;
}

int ladder6(int n,int k,int *dp)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(dp[n]!=0)
        return dp[n];
    int ans=0;
    for(int i=1;i<=k;i++)
        ans+=ladder6(n-i,k,dp);
    return dp[n]=ans;
}

int ladder7(int n,int k)
{
    int dp[n+1];
    dp[0]=dp[1]=1;

    for(int i=2;i<=k;i++)
        dp[i]=2*dp[i-1];

    for(int i=k+1;i<=n;i++)
    {
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    return dp[n];
}
int main()
{

    int dp[100]={0};
    cout<<ladder(4)<<endl;
    cout<<ladder2(4)<<endl;
    cout<<ladder3(4,3)<<endl;
    cout<<ladder4(4,3)<<endl;
    cout<<ladder5(4,3)<<endl;
    cout<<ladder6(4,3,dp)<<endl;
    cout<<ladder7(4,3)<<endl;

    return 0;
}