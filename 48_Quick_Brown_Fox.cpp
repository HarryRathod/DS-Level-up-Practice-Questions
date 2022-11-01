#include<bits/stdc++.h>
using namespace std;

int quickBrownFox(string in,unordered_set<string> s,int i=0)
{
    if(in[i]=='\0')
        return 0;
    
    string out="";
    int ans=INT_MAX;

    for(int j=i;in[j]!='\0';j++)
    {
        out+=in[j];
        if(s.find(out)!=s.end())
        {
            int subAns=quickBrownFox(in,s,j+1);
            if(subAns!=-1)
            {
                ans=min(ans,1+subAns);
            }
        }
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}

int main()
{
    string in="thequickbrownfox";
    unordered_set<string> s{"the","quickbrown","fox","quick","brown"};

    cout<<quickBrownFox(in,s)-1<<endl;

    return 0;
}