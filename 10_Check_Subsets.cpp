#include<bits/stdc++.h>
using namespace std;

bool checkSubset(string s,string sub)
{
    int i,j;
    i=j=0;
    for(;i<s.size();i++)
    {
        if(s[i]==sub[j])
        {
            j++;
            if(j==sub.size())
                return true;
        }
    }
    return false;
}

int main()
{
    cout<<checkSubset("codingminutes","cines")<<endl;

    return 0;
}