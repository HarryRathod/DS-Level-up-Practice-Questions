#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a1={-1,5,10,20,3};
    vector<int> a2={26,134,135,15,17};

    sort(a2.begin(),a2.end());
    int n=a1.size();
    int p1,p2,diff=INT_MAX;

    for(int i=0;i<n;i++)
    {
        int x=a1[i];
        auto lb=lower_bound(a2.begin(),a2.end(),x)-a2.begin();
        if(lb-1>=0 && x-a2[lb-1]<diff)
        {
            diff=x-a2[lb-1];
            p1=x;
            p2=a2[lb-1];
        }
        if(lb<a2.size() && a2[lb]-x<diff)
        {
            diff=a2[lb]-x;
            p1=a2[lb];
            p2=x;
        }
    }
    cout<<p1<<" and "<<p2<<endl;

    return 0;
}