#include<bits/stdc++.h>
using namespace std;

void helper(string s,map<vector<int>, int> &m)
{
    int n=s.length();
    int k=1;
    while(k<=n)
    {
        for(int i=0;i<=n-k;i++)
        {
            int j=i;
            int h=k;
            string out="";
            while(h--)
            {
                out+=s[j];
                j++;
            }
            vector<int> v(26,0);
            for(int i=0;out[i]!='\0';i++)
            {
                v[out[i]-'a']++;
            }
            m[v]++;
        }
        k++;
    }
}

int main()
{
    map<vector<int>, int> m;
    string s="abba";

    helper(s,m);
    int ans=0;

    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second>1)
        {
            int x=it->second;
            int sum=(x*(x-1)/2);
            ans+=sum;
        }
    }

    cout<<ans<<endl;

    return 0;
}