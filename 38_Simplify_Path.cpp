#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path)
{
    istringstream iss(path);
    string token;
    vector<string> tokens;
    while(getline(iss,token,'/'))
    {
        if(token=="" || token==".")
            continue;
        tokens.push_back(token);
    }
    vector<string> ans;
    if(path[0]=='/')
        ans.push_back("");
    
    for(string token:tokens)
    {
        if(token=="..")
        {
            if(ans.size()==0 || ans[ans.size()-1]=="..")
                ans.push_back("..");
            else if(ans[ans.size()-1]!="")
                ans.pop_back();
        }
        else
            ans.push_back(token);
    }

    if(ans.size()==1 && ans[0]=="")
        return "/";
    
    ostringstream oss;
    int i=0;
    for(auto token:ans)
    {
        if(i!=0)
            oss<<"/";
        i++;
        oss<<token;
    }
    
    return oss.str();
}

int main()
{
    string path="/../x/y/../z/././w/a///../../c/./";

    cout<<simplifyPath(path)<<endl;

    /// Practice to understand the concept of ostringstream.
    ostringstream oss;
    oss<<"Harendra";
    oss<<" Rathod";
    cout<<oss.str()<<endl;
    
    return 0;
}