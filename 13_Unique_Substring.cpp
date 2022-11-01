#include<bits/stdc++.h>
using namespace std;

int uniqueSubstring(string s)
{
    int largest=0;
    int i=0;
    int j=0;
    int winSize=0;
    unordered_map<char,int> mymap;

    while(j<s.size())
    {
        if(mymap.find(s[j])!=mymap.end() && mymap[s[j]]>=i)
        {
            i=mymap[s[j]]+1;
            mymap[s[j]]=j;
            winSize=j-i+1;
            j++;
        }
        else
        {
            mymap[s[j]]=j;
            winSize++;
            j++;
            if(largest<winSize)
                largest=winSize;
        }
    }
    return largest;
}

string uniqueSubstring2(string s)
{
    int i=0;
    int j=0;
    int largest=0;
    int winSize=0;
    int start=0;

    unordered_map<char,int> mymap;

    while (j<s.size())
    {
        char ch=s[j];
        if(mymap.count(ch) && mymap[ch]>=i)
        {
            i=mymap[ch]+1;
            winSize=j-i;
        }

        mymap[ch]=j;
        winSize++;
        j++;

        if(largest<winSize)
        {
            largest=winSize;
            start=i;
        }
    }

    return s.substr(start,largest);    
}

int main()
{
    string s="abcaebfd";

    cout<<uniqueSubstring(s)<<endl;

    cout<<uniqueSubstring2(s)<<endl;

    return 0;
}