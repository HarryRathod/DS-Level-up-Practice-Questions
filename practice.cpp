#include<bits/stdc++.h>
using namespace std;
	
void perm(string s,int j=0)
{
	if(s[j]=='\0')
	{
		cout<<s<<endl;
		return;
	}
	else
	{
		for(int i=j;s[i]!='\0';i++)
		{
			swap(s[i],s[j]);
			perm(s,j+1);
			swap(s[i],s[j]);
		}
	}
}

int main()
{
	string s="ABC";
	perm(s);

	return 0;
}