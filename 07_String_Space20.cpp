#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[]="Hi How are you?";
    int space=0;
    for(char x:s)
    {
        if(x==' ')
            space+=1;
    }
    int cn=strlen(s);
    int nn=cn+2*space;

    int i=cn-1;
    int j=nn-1;
    s[nn]='\0';
    
    while (j>0)
    {
        if(s[i]==' ')
        {
            s[j--]='0';
            s[j--]='2';
            s[j--]='%';
            i--;
        }
        else
        {
            s[j--]=s[i--];
        }
    }
    cout<<s<<endl;

    return 0;
}