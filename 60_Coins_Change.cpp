#include<bits/stdc++.h>
using namespace std;

int coinsChange(int n,int *t,int tn)
{
    if(n==0)
        return 0;

    int ans=INT_MAX;
    
    for(int i=0;i<tn;i++)
    {
        if(t[i]<=n)
        {
            int curr=coinsChange(n-t[i],t,tn);
            if(1+curr<ans)
                ans=1+curr;
        }
    }   
    if(ans==INT_MAX)
        return -1;
    else 
        return ans;
}

int coinsChange2(int m,int t[],int n)  /// Bottom Up DP Approach
{
    int dp[m+1];
    dp[0]=0;
    for(int i=1;i<=m;i++)
    {
        dp[i]=INT_MAX;

        for(int c=0;c<n;c++)
        {
            if((i-t[c])>=0 && dp[i-t[c]]!=INT_MAX)
            {
                dp[i]=min(dp[i],dp[i-t[c]]+1);
            }
        }
    }
    return dp[m]==INT_MAX?-1:dp[m];
}

int main()
{
    int t[]={1,3,7,10};
    cout<<coinsChange(21,t,4)<<endl;
    cout<<coinsChange2(21,t,4)<<endl;

    return 0;
}