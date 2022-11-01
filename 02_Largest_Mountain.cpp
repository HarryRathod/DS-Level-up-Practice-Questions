#include<bits/stdc++.h>
using namespace std;

int mountain(vector<int> a)
{
    int n=a.size();

    int largest=0;

    for(int i=1;i<n-1;)
    {
        if(a[i]>a[i-1] && a[i]>a[i+1])
        {
            int j=i;
            int count=1;
            while (j>0 && a[j]>a[j-1])
            {
                count++;
                j--;
            }
            while (i<n-1 && a[i]>a[i+1])
            {
                count++;
                i++;
            }
            largest=max(largest,count);            
        }
        else
            i++;
    }
    return largest;
}

int main()
{
    vector<int> v{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    cout<<mountain(v)<<endl;

    return 0;
}