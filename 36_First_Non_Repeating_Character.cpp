#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    cin>>ch;

    queue<char> q;
    int f[26]={0};

    while(ch!='.')
    {
        q.push(ch);
        f[ch-'a']++;
        while(!q.empty())
        {
            int idx=q.front()-'a';
            if(f[idx]>1)
            {
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty())
            cout<<"-1"<<endl;
        cin>>ch;
    }
    return 0;
}