#include<bits/stdc++.h>
using namespace std;

int wines(int prices[],int l,int r,int y)
{
    if(l>r)
        return 0;
    int pick_left=y*prices[l]+wines(prices,l+1,r,y+1);
    int pick_right=y*prices[r]+wines(prices,l,r-1,y+1);

    return max(pick_left,pick_right);
}

int winesDP(int prices[],int dp[][10],int l,int r,int y)  /// Top Down DP Solution
{
    if(l>r)
        return 0;
    if(dp[l][r]!=0)
        return dp[l][r];
    int pick_left=y*prices[l]+winesDP(prices,dp,l+1,r,y+1);
    int pick_right=y*prices[r]+winesDP(prices,dp,l,r-1,y+1);

    return dp[l][r]=max(pick_left,pick_right);
}

int winesDP2(int prices[],int n)   /// Bottom Up DP Solution
{
    vector<vector<int> > dp(n,vector<int>(n,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            int year=n-(j-i);
            if(i==j)
            {
                dp[i][j]=n*prices[i];
            }
            else if(i<j)
            {
                int pick_left=year*prices[i]+dp[i+1][j];
                int pick_right=year*prices[j]+dp[i][j-1];

                dp[i][j]=max(pick_left,pick_right);
            }
        }
    }

    /// Printing a Matrix
    cout<<"Bottom up DP Matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%2d ",dp[i][j]);
        }
        cout<<endl;
    }

    return dp[0][n-1];
}

int main()
{
    int prices[]={2,3,5,1,4};
    int n=5;

    int dp[10][10]={0};

    cout<<"Recursive Solution: "<<wines(prices,0,n-1,1)<<endl;
    cout<<"Top Down DP Solution: "<<winesDP(prices,dp,0,n-1,1)<<endl;

    
    /// printig DP Matrix.
    /// This is Diagonal Top Down Dp means in this traversal occur diagonically.
    cout<<"Top Down DP Matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%2d ",dp[i][j]);
        }
        cout<<endl;
    }

    cout<<"Bottom Up DP Solution: "<<winesDP2(prices,n)<<endl;
    
    return 0;
}