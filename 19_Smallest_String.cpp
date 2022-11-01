#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b)
{
    return a+b < b+a;
}

int main()
{
    string s[]={"a","ab","aba"};
    int n=3;
    sort(s,s+n,cmp);

    for(auto x:s)
        cout<<x;
    cout<<endl;

    return 0;
}