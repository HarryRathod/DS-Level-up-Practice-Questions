#include<bits/stdc++.h>
using namespace std;

int arrayJump(int a[],int n,int i)
{
    if(i==n-1)
        return 0;
    if(i>=n)
        return INT_MAX;
    int steps=INT_MAX;
    int max_jump=a[i];
    for(int jump=1;jump<=max_jump;jump++)
    {
        int next_cell=i+jump;
        int sub_step=arrayJump(a,n,next_cell);
        if(sub_step!=INT_MAX)
        {
            steps=min(steps,1+sub_step);
        }
    }
    return steps;
}

int array_jump_dp(int a[],int n,int dp[],int i)   /// Top Down DP Approach
{
    if(i==n-1)
        return 0;
    if(i>=n)
        return INT_MAX;

    if(dp[i]!=0)
        return dp[i];
    
    int steps=INT_MAX;
    int max_jump=a[i];
    for(int jump=1;jump<=max_jump;jump++)
    {
        int next_cell=i+jump;
        int sub_prob=array_jump_dp(a,n,dp,next_cell);
        if(sub_prob!=INT_MAX)
        {
            steps=min(steps,1+sub_prob);
        }
    }
    return dp[i]=steps;
}

int main()
{
    int a[]={3,4,2,1,2,3,10,1,1,1,2,5};
    int n=sizeof(a)/sizeof(int);

    int dp[n+1]={0};

    cout<<arrayJump(a,n,0)<<endl;
    cout<<array_jump_dp(a,n,dp,0)<<endl;

    return 0;
}