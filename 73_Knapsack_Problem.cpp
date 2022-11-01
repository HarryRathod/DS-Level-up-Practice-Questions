#include<bits/stdc++.h>
using namespace std;

int knapsack(int prices[],int n,int W,int wts[])  /// Recursive Solution
{
    if(n==0 || W==0)
        return 0;
    int inc=0;
    if(wts[n-1]<=W)
        inc=prices[n-1]+knapsack(prices,n-1,W-wts[n-1],wts);
    int exc=knapsack(prices,n-1,W,wts);
    return max(inc,exc);
}

int knapsack_dp(int prices[],int wts[],int W,int n,int dp[][10]) /// Top Down DP Solution
{
    if(n==0 || W==0)
        return 0;
    if(dp[n][W]!=0)
        return dp[n][W];
    int inc=0;
    if(wts[n-1]<=W)
        inc=prices[n-1]+knapsack_dp(prices,wts,W-wts[n-1],n-1,dp);
    int exc=knapsack_dp(prices,wts,W,n-1,dp);
    return dp[n][W]=max(inc,exc);

}

int knapsack_dp2(int prices[],int wts[],int W,int N)  ///Bottom Up DP Solution
{
    vector<vector<int> > dp(N+1,vector<int>(W+1,0));

    for(int n=1;n<=N;n++)
    {
        for(int w=0;w<=W;w++)
        {
            int inc=0,exc=0;
            if(wts[n-1]<=w)
                inc=prices[n-1]+dp[n-1][w-wts[n-1]];
            exc=dp[n-1][w];

            dp[n][w]=max(inc,exc);
        }
    }
    return dp[N][W];
}

int main()
{
    int prices[]={5,20,20,10};
    int wts[]={2,7,3,4};

    int dp[10][10]={0};

    int n=4;
    int W=11;

    cout<<"Recursive Solution: "<<knapsack(prices,n,W,wts)<<endl;
    cout<<"Top Down DP Solution: "<<knapsack_dp(prices,wts,W,n,dp)<<endl;
    cout<<"Bottom Up DP Solution: "<<knapsack_dp2(prices,wts,W,n)<<endl;

    return 0;
}