#include<bits/stdc++.h>
using namespace std;

void subSequence(string s,string o,vector<string> &v)
{
    if(s.size()==0)
    {
        v.push_back(o);
        return;
    }
    string reduced=s.substr(1);

    subSequence(reduced,o+s[0],v);
    subSequence(reduced,o,v);
}

bool cmp(string s1,string s2)
{
    if(s1.size()==s2.size())
    {
        return s1<s2;
    }
    return s1.length()<s2.length();
}

int main()
{
    string s="abcd";

    vector<string> ans;
    subSequence(s," ",ans);

    sort(ans.begin(),ans.end(),cmp);

    for(auto x:ans)
        cout<<x<<", ";

    return 0;
}