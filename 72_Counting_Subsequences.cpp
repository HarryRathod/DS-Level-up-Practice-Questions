#include<bits/stdc++.h>
using namespace std;

int countingSS(string s1,string s2,int i,int j)
{
    if(j==-1)
        return 1;
    if(i==-1)
        return 0;
    if(s1[i]==s2[j])
        return (countingSS(s1,s2,i-1,j-1)+countingSS(s1,s2,i-1,j));
    else
        return countingSS(s1,s2,i-1,j);
}

int countSS_dp(string s1,string s2,int dp[][10],int i,int j) /// Top Down DP Solution
{
    if(j==-1)
        return 1;
    if(i==-1)
        return 0;
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    if(s1[i]==s2[j])
        return dp[i][j]=(countSS_dp(s1,s2,dp,i-1,j-1)+countSS_dp(s1,s2,dp,i-1,j));
    else
        return dp[i][j]=countSS_dp(s1,s2,dp,i-1,j);
}

int countSS_dp2(string s1,string s2)  /// Bottom Up DP Solution
{
    int n1=s1.length();
    int n2=s2.length();

    vector<vector<int> > dp(n1+1,vector<int>(n2+1,0));

    for(int i=0;i<=n1;i++)
        dp[i][0]=1;

    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    /// Printing DP Matrix
    cout<<"Bottom Up DP Matrix: "<<endl;
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[n1][n2];
}

int main()
{
    string s1="ABCDCE";
    string s2="ABC";

    int dp[10][10]={0};

    int i=s1.length()-1;
    int j=s2.length()-1;

    cout<<"Recursive Solution: "<<countingSS(s1,s2,i,j)<<endl;

    cout<<"Top Down Solution: "<<countSS_dp(s1,s2,dp,i,j)<<endl;

    cout<<"Bottom Up Solution: "<<countSS_dp2(s1,s2)<<endl;

    return 0;
}