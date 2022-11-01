#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> v)
{
    int n=v.size();
    vector<int> dp(n,1);

    int max_len=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j]<v[i])
            {
                dp[i]=max(dp[i],1+dp[j]);
                max_len=max(max_len,dp[i]);
            }
        }
    }
    return max_len;
}

int main()
{
    vector<int> v={50,4,10,8,30,100};

    cout<<lis(v)<<endl;

    return 0;
}