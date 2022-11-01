#include<bits/stdc++.h>
using namespace std;

int lhelper(vector<int> &v,int n,int k)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(v[mid]==k)
        {
            ans=mid;
            e=mid-1;
        }
        else if(v[mid]>k)
            e=mid-1;
        else
            s=mid+1;
    }
    return ans;
}

int rhelper(vector<int> &v,int n,int k)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(v[mid]==k)
        {
            ans=mid;
            s=mid+1;
        }
        else if(v[mid]>k)
            e=mid-1;
        else
            s=mid-1;
    }
    return ans;
}

int BinarySearch(vector<int> &v,int k)
{
    int n=v.size();
    int l=lhelper(v,n,k);
    int r=rhelper(v,n,k);
    return (r-l+1);
}

int chelper(vector<int> &v,int n,int k,bool Left=true)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(v[mid]==k)
        {
            ans=mid;
            if(Left)
                e=mid-1;
            else
                s=mid+1;
        }
        else if(v[mid]>k)
            e=mid-1;
        else
            s=mid+1;
    }
    return ans;
}

int BinarySearch2(vector<int> &v,int k)
{
    int n=v.size();
    int l=chelper(v,n,k);
    int r=chelper(v,n,k,false);
    return (r-l+1);
}

int main()
{
    vector<int> v={0,1,1,1,2,2,2,2,4,5,5,5,5,5,5,5};
    cout<<BinarySearch(v,2)<<endl;
    cout<<BinarySearch2(v,2)<<endl;

    cout<<"ans by using Inbuilt upper_bound & lower_bound functions: "<<endl;
    cout<<upper_bound(v.begin(),v.end(),2)-lower_bound(v.begin(),v.end(),2)<<endl;

    ///NOTE- These upper_bound() & lower_bound inbuilt funtions are present in STL Library.
    /// inside STL they are in algorithm header file. hence must #include<algorithm.h> 

    return 0;
}