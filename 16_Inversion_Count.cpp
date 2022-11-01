#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &v,int l,int m,int h)
{
    int i=l;
    int k=l;
    int j=m+1;
    int b[h];
    int cnt=0;
    while(i<=m && j<=h)
    {
        if(v[i]<v[j])
            b[k++]=v[i++];
        else{
            b[k++]=v[j++];
            cnt+=m-i+1;
        }
    }
    while(i<=m)
        b[k++]=v[i++];
    while(j<=h)
        b[k++]=v[j++];
    for(int i=l;i<=h;i++)
    {
        v[i]=b[i];
    }
    return cnt;
}

int inversionCount(vector<int> &v,int l,int h)
{
    if(l>=h)
        return 0;
    int m=(l+h)/2;
    int c1=inversionCount(v,l,m);
    int c2=inversionCount(v,m+1,h);
    int ci=merge(v,l,m,h);
    return c1+c2+ci;
}

int main()
{
    vector<int> v={0,5,2,3,1};
    int n=v.size()-1;

    cout<<inversionCount(v,0,n)<<endl;

    return 0;
}