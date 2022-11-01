#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > housing(vector<int> &v,int sum)
{
    vector<pair<int,int> > ans;
    int i=0;
    int j=1;
    int preSum=v[i]+v[j];
    while (j<v.size())
    {
        if(preSum==sum)
        {
            ans.push_back({i,j});
            preSum-=v[i];
            i++;
            j++;
            preSum+=v[j];
        }
        else if(preSum<sum)
        {
            j++;
            preSum+=v[j];
        }
        else
        {
            preSum-=v[i];
            i++;
        }
    }
    
    return ans;
}

void housing2(vector<int> v,int sum)
{
    int i=0;
    int j=0;
    int cs=0;

    while (j<v.size())
    {
        cs+=v[j];
        j++;

        while(cs>sum && i<j)
        {
            cs-=v[i];
            i++;
        }

        if(cs==sum)
        {
            cout<<i<<" - "<<j-1<<endl;
        }
    }
    
}

int main()
{
    vector<int> v{1,3,2,1,4,1,3,2,1,1,2};

    vector<pair<int,int> > ans=housing(v,8);

    for(auto x:ans)
    {
        cout<<x.first<<", "<<x.second<<endl;
    }

    cout<<"Indecies by 2nd Method: "<<endl;
    housing2(v,8);

    return 0;
}