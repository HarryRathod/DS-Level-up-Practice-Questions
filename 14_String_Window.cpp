#include<bits/stdc++.h>
using namespace std;

string stringWindow(string s,string p)
{
    int FS[256]={0};
    int FP[256]={0};

    for(int i=0;i<p.length();i++)
    {
        FP[p[i]]++;
    }

    int cnt=0;
    int start=0;
    int start_idx=-1;
    int min_so_far=INT_MAX;
    int window_size;

    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        FS[ch]++;

        if(FP[ch]!=0 && FS[ch]<=FP[ch])
        {
            cnt+=1;
        }

        if(cnt==p.length())
        {
            while(FP[s[start]]==0 || FS[s[start]]>FP[s[start]])
            {
                FS[s[start]]--;
                start++;
            }

            window_size=i-start+1;
            if(window_size<min_so_far)
            {
                min_so_far=window_size;
                start_idx=start;
            }
        }
    }

    if(start_idx==-1)
        return "NO WINDOW FOUND!";
    
    return s.substr(start_idx,min_so_far);
}

string stringWindow2(string s1,string s2)
{
    /// This method will not give correct answer in some cases.
	unordered_map<char,int> m;
	for(int i=0;s2[i]!='\0';i++)
	{
		if(m.count(s2[i]))
			m[s2[i]]++;
		else
			m[s2[i]]=1;
	}

	int start=INT_MAX;
	int win_len=0;
	for(int i=0;s1[i]!='\0';i++)
	{
		if(m.count(s1[i]))
		{
			start=min(start,i);
			m[s1[i]]--;
			if(m[s1[i]]==0)
				m.erase(s1[i]);
		}
		if(start!=INT_MAX)
			win_len++;
		if(m.empty())
			return s1.substr(start,win_len);
	}
}

int main()
{
    string s="helloguys";

    cout<<stringWindow(s,"eo")<<endl;
    
    cout<<"By 2nd Method: "<<endl;
    cout<<stringWindow2(s,"eo")<<endl;

    return 0;
}