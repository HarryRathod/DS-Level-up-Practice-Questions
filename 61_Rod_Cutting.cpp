#include<bits/stdc++.h>
using namespace std;

int maxProfit(int prices[],int n)
{
    if(n<=0)
        return 0;
    int ans=INT_MIN;

    for(int i=0;i<n;i++)
    {
        int cut=i+1;
        int curr_ans=prices[i]+maxProfit(prices,n-cut);
        ans=max(ans,curr_ans);
    }
    return ans;
}

int max_profit_dp(int prices[],int n)
{
    int dp[n+1];
    dp[0]=0;
    
    for(int len=1;len<=n;len++)
    {
        int ans=INT_MIN;
        for(int i=0;i<len;i++)
        {
            int cut=i+1;
            int curr=prices[i]+dp[len-cut];
            ans=max(ans,curr);
        }
        dp[len]=ans;
    }
    return dp[n];
}

int main()
{
    int prices[]={1,5,8,9,10,17,17,20};
    int n=sizeof(prices)/sizeof(int);

    cout<<maxProfit(prices,n)<<endl;
    cout<<max_profit_dp(prices,n)<<endl;

    return 0;
}