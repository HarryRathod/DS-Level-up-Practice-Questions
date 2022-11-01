#include<bits/stdc++.h>
using namespace std;

void strsubset(string s,vector<string> &ans,string out="")
{

    if(s.length()==0)
    {
        ans.push_back(out);
        return ;
    }
    strsubset(s.substr(1),ans,out);
    strsubset(s.substr(1),ans,out+s[0]);
}

bool cmp(string a,string b)
{
    if(a.length()==b.length())
        return a<b;
    return a.length()<b.length();
}

int main()
{
    string s="ABC";
    vector<string> ans;
    strsubset(s,ans);
    sort(ans.begin(),ans.end(),cmp);

    for(auto x:ans)
        cout<<x<<endl;

    return 0;
}