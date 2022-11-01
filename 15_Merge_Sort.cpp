#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a,int l,int mid,int h)
{
    vector<int> b(h+1);
    int i,j,k;
    i=k=l;
    j=mid+1;

    while (i<=mid && j<=h)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }

    for( ;i<=mid;i++)
        b[k++]=a[i];
    for( ;j<=h;j++)
        b[k++]=a[j];

    for(i=l;i<=h;i++)
        a[i]=b[i];    
}

void mergeSort(vector<int> &a,int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}

int main()
{
    vector<int> v{5,3,7,2,1,18,12,11};
    int h=v.size()-1;

    mergeSort(v,0,h);

    for(auto x:v)
        cout<<x<<", ";

    cout<<endl;

    return 0;
}