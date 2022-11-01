#include<bits/stdc++.h>
using namespace std;

void generateBrackets(int n,string out="",int open=0,int close=0,int i=0)
{
    if(i==2*n)
    {
        cout<<out<<endl;
        return ;
    }
    if(close<open)
        generateBrackets(n,out+')',open,close+1,i+1);
    if(open<n)
        generateBrackets(n,out+'(',open+1,close,i+1);
}

int main()
{
    generateBrackets(3);

    return 0;
}