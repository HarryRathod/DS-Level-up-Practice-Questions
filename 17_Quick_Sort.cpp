#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int l,int h)
{
    int pivot=v[l];
    int i=l;
    int j=h;
    do
    {
        while(v[i]<=pivot)
            i++;
        while( v[j]>pivot)
            j--;
        if(i<j)
            swap(v[i],v[j]);
    }while(i<=j);
    swap(v[j],v[l]);
    return j;
}

void quickSort(vector<int> &v,int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(v,l,h);
        quickSort(v,l,j-1);
        quickSort(v,j+1,h);
    }
}

int partition2(vector<int> &a,int s,int e)
{
    int i=s;
    int pivot=a[e];
    for(int j=s;j<e;j++)
    {
        if(a[j]<pivot)
        {
            swap(a[j],a[i]);
            i++;
        }
    }
    swap(a[i],a[e]);
    return i;
}

void quickSort2(vector<int> &a,int s,int e)

{
    if(s<e)
    {
        int j=partition2(a,s,e);
        quickSort2(a,s,j-1);
        quickSort2(a,j+1,e);
    }
}

int main()
{
    vector<int> v{5,4,3,2,1};
    int n=v.size()-1;
    quickSort(v,0,n);

    for(auto x:v)
        cout<<x<<", ";
    cout<<endl;

    vector<int> a={5,2,4,7,9,1};
    int m=a.size()-1;
    quickSort2(a,0,m);

    for(int x:a)
        cout<<x<<", ";
    cout<<endl;

    return 0;
}