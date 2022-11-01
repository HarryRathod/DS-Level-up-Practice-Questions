#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int l,int h)
{
    int pivot=v[h];
    int i=l;
    for(int j=l;j<h;j++)
    {
        if(v[j]<pivot)
        {
            swap(v[j],v[i]);
            i++;
        }
    }
    swap(v[i],v[h]);
    return i;
}

int quickSelect(vector<int> &v,int l,int h,int k)
{
        int j=partition(v,l,h);
        if(j==k)
            return v[k];
        else if(k<j)
            quickSelect(v,l,j-1,k);
        else
            quickSelect(v,j+1,h,k);
}

int main()
{
    vector<int> v={10,5,2,0,7,6,4};
    int n=v.size()-1;
    int k;
    cin>>k;
    cout<<quickSelect(v,0,n,k)<<endl;

    return 0;
}