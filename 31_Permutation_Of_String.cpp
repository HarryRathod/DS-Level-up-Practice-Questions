#include<bits/stdc++.h>
using namespace std;

void perm(string in,int i=0)
{
    if(in[i]=='\0')
    {
        cout<<in<<endl;
        return;
    }
    for(int j=0;j<=i;j++)
    {
        swap(in[i],in[j]);
        perm(in,i+1);
        swap(in[i],in[j]);
    }
}

int main()
{
    string s="ABC";
    perm(s);

    return 0;
}