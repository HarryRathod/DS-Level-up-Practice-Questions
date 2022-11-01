#include<bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};


class Compare2
{
public:
    bool operator()(pair<float,float> a,pair<float,float> b)
    {
        return a.first>b.first;
    }
};

vector<int> findCabs(vector<vector<int> > cars,int k)
{
    vector<int> ans;
    if(k==0 || cars.size()==0)
        return ans;

    priority_queue<pair<float,float>,vector<pair<float,float> >,Compare2 > q;
    
    for(int i=0;i<cars.size();i++)
    {
        float dist=sqrt(pow(cars[i][0],2)+pow(cars[i][1],2));
        q.push({dist,i+1});
    }
    while(k--)
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}

int mergingRopes(vector<int> v)
{
    int n=v.size();
    int ans=0;
    priority_queue<int,vector<int>,greater<int> > q(v.begin(),v.end());

    while(q.size()!=1)
    {
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        ans+=(x+y);
        q.push(x+y);
    }
    return ans;
}

void runningMedian(vector<int> v)
{
    float med=v[0];
    cout<<med<<", ";
    priority_queue<int> lheap;
    priority_queue<int,vector<int>,greater<int> > rheap;

    lheap.push(v[0]);
    for(int i=1;i<v.size();i++)
    {
        if(lheap.size()>rheap.size())
        {
            if(v[i]>med)
                rheap.push(v[i]);
            else
            {
                rheap.push(lheap.top());
                lheap.pop();
                lheap.push(v[i]);
            }
            med=(lheap.top()+rheap.top())/2.0;
        }
        else if(lheap.size()==rheap.size())
        {
            if(v[i]>med)
            {
                rheap.push(v[i]);
                med=rheap.top();
            }
            else
            {
                lheap.push(v[i]);
                med=lheap.top();
            }
        }
        else
        {
            if(v[i]>med)
            {
                lheap.push(rheap.top());
                rheap.pop();
                rheap.push(v[i]);
            }
            else{
                lheap.push(v[i]);
            }
            med=(lheap.top()+rheap.top())/2.0;
        }
        cout<<med<<",";
    }
    cout<<endl;
}

int main()
{
    int arr[]={12,23,7,18,2,9,1,20};

    priority_queue<int,vector<int>,Compare > q;

    for(auto x:arr)
    {
        q.push(x);
    }

    while(!q.empty())
    {
        cout<<q.top()<<endl;
        q.pop();
    }

    vector<vector<int> > cars= {{1,1},{2,1},{3,2},{0,1},{2,3}};

    vector<int> ans=findCabs(cars,3);

    for(auto x:ans)
    {
        cout<<x<<", ";
    }
    cout<<endl;


    vector<int> v={4,3,2,6};
    cout<<mergingRopes(v)<<endl;

    cout<<"Running Median Problem: "<<endl;
    vector<int> v1={10,5,2,3,0,12,18,20,22};
    runningMedian(v1);

    return 0;
}