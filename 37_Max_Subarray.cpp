///This is HARD Level Problem.
///It require concept of deque & sliding window.

#include<bits/stdc++.h>
using namespace std;

void maxSubArray(int a[],int k,int n)
{
    deque<int> q(k);
    int i;
    for(i=0;i<k;i++)
    {
        while(!q.empty() && a[i]>a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<a[q.front()]<<",";
        while(!q.empty() && q.front()<=i-k)
            q.pop_front();
        while(!q.empty() && a[i]>=a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout<<a[q.front()]<<endl;
}

int main()
{
    int a[]={1,2,3,1,4,5,2,3,6};
    int n=9;
    maxSubArray(a,3,n);

    return 0;
}