#include<bits/stdc++.h>
using namespace std;

int RotatedSearch(vector<int> &v,int k)
{
    int s=0;
    int e=v.size()-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(v[mid]==k)
            return mid;
        else if(v[mid]>=v[s])
        {
            if(k>=v[s] && k<v[mid])
                e=mid-1;
            else
                s=mid+1;
        }
        else
        {
            if(k<=v[e] && k>v[mid])
                s=mid+1;
            else
                e=mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v={4,5,6,1,2,3};
    cout<<RotatedSearch(v,4)<<endl;
    cout<<RotatedSearch(v,5)<<endl;
    cout<<RotatedSearch(v,6)<<endl;
    cout<<RotatedSearch(v,1)<<endl;
    cout<<RotatedSearch(v,2)<<endl;
    cout<<RotatedSearch(v,3)<<endl;

    return 0;
}