#include<bits/stdc++.h>
using namespace std;

string keypad[]={"","","ABC","DEF","FHI","JKL","MNO","PQRS","TUV","WXYZ"};

void smartKeypad(string in,string out,int i=0)
{
    if(in[i]=='\0')
    {
        cout<<out<<endl;
        return ;
    }
    int pos=in[i]-'0';
    if(pos==0 || pos==1)
        smartKeypad(in,out,i+1);
    for(int k=0;k<keypad[pos].size();k++)
        smartKeypad(in,out+keypad[pos][k],i+1);

    return;
}

int main()
{
    string in="23";
    string out;
    smartKeypad(in,out);

    return 0;
}