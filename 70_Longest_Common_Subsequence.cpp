#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,int i=0,int j=0)  /// Recursive Solution
{
    if(i>=s1.length() || j>=s2.length())
        return 0;
    if(s1[i]==s2[j])
        return 1+LCS(s1,s2,i+1,j+1);
    return max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
}

int LCS_dp(string s1,string s2,vector<vector<int> > &dp,int i=0,int j=0)  // Top Down DP Solution
{
    if(i==s1.length() || j==s2.length())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j])
    {
        dp[i][j]=1+LCS_dp(s1,s2,dp,i+1,j+1);
        return dp[i][j];
    }
    else
    {
        dp[i][j]=max(LCS_dp(s1,s2,dp,i+1,j),LCS_dp(s1,s2,dp,i,j+1));
        return dp[i][j];
    }
}

int LCS_dp2(string s1,string s2)  /// Bottom Up DP Approach
{
    int n1=s1.length();
    int n2=s2.length();

    vector<vector<int> > dp(n1+1,vector<int> (n2+1,0));

    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    /// Following code is to print the common characters in Substring.
    vector<char> word;
    int i=n1,j=n2;
    while(i!=0 && j!=0)
    {
        if(dp[i][j]==dp[i][j-1])
            j--;
        else if(dp[i][j]==dp[i-1][j])
            i--;
        else{
            word.push_back(s1[i-1]);
            i--;
            j--;
        }
    }

    reverse(word.begin(),word.end());

    for(char x:word)
        cout<<x<<",";
    cout<<endl;

    return dp[n1][n2];
}

int main()
{
    string s1="ABCD";
    string s2="ABEDF";

    int n1=s1.length();
    int n2=s2.length();

    vector<vector<int> > dp(n1,vector<int>(n2,-1));

    cout<<LCS(s1,s2)<<endl;
    cout<<LCS_dp(s1,s2,dp)<<endl;
    cout<<LCS_dp2(s1,s2)<<endl;

    return 0;
}