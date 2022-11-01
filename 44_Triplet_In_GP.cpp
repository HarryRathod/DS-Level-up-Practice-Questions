#include<bits/stdc++.h>
using namespace std;

int tripletInGP(vector<int> v,int r)
{
    int n=v.size();
    int m=INT_MIN;
    int way=0;

    for(int i=0;i<n;i++)
    {
        if(m<v[i])
            m=v[i];
    }

    int left[m+1]={0};
    int right[m+1]={0};

    for(int i=1;i<n;i++)
    {
        right[v[i]]++;
    }

    for(int i=1;i<n-1;i++)
    {
        left[v[i-1]]++;
        right[v[i]]--;
        int lcount=0;
        int rcount=0;
        int  a=v[i]/r;
        if(a*r==v[i] && left[a]>0)
        {
            lcount=left[a];
        }
        if(v[i]*r<=m && right[v[i]*r]>0)
            rcount=right[v[i]*r];
        way+=(lcount*rcount);
        if(lcount!=0 && rcount!=0)
        {
            while (lcount>0 || rcount>0)
                {
                    cout<<v[i]/r<<", "<<v[i]<<", "<<v[i]*r<<endl;
                    lcount--;
                    rcount--;
                }
        }
    }
    return way;
}

int tripletInGP2(vector<int> v,int r)    /// Efficient Solution by using unordered_map
{
    int ans=0; 
    unordered_map<long,int> left;
    unordered_map<long,int> right;

    for(int i=0;i<v.size();i++)
    {
        left[v[i]]=0;
        right[v[i]]++;
    }

    for(int i=0;i<v.size()-1;i++)
    {
        right[v[i]]--;
        if(v[i]%r==0)
        {
            long a=v[i]/r;
            long b=v[i];
            long c=v[i]*r;

            if(left[a]>0 && right[c]>0)
                ans+=left[a]*right[c];
        }
        left[v[i]]++;
    }
    return ans;
}

int main()
{
    vector<int> v={1,16,4,16,64,16};

    cout<<tripletInGP(v,4)<<endl;
    cout<<tripletInGP2(v,4)<<endl;

    return 0;
}