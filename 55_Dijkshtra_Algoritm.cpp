#include<bits/stdc++.h>
using namespace std;

class graph
{
public:
    int v;
    list<pair<int,int> > *l;

    graph(int v)
    {
        this->v=v;
        l=new list<pair<int,int> >[v];
    }

    void addEdge(int x,int y,int wt,bool undir=true)
    {
        l[x].push_back({wt,y});
        if(undir)
            l[y].push_back({wt,x});
    }

    int dijkshtraAlgorithm(int s,int dest)
    {
        vector<int> dist(v,INT_MAX);
        set<pair<int,int> > st;
        st.insert({0,s});
        dist[s]=0;

        while(!st.empty())
        {
            auto it=st.begin();
            int node=it->second;
            int nodeDist=it->first;
            st.erase(it);

            for(auto nbrPair:l[node])
            {
                int edgeWeight=nbrPair.first;
                int nbr=nbrPair.second;

                auto f=st.find({dist[nbr],nbr});
                if(f!=st.end())
                    st.erase(f);
                
                if(dist[nbr]>nodeDist+edgeWeight)
                {
                    dist[nbr]=nodeDist+edgeWeight;
                    st.insert({dist[nbr],nbr});
                }
            }
        }
        for(int i=0;i<v;i++)
        {
            cout<<"Node i "<<i<<" dist "<<dist[i]<<endl;
        }

        return dist[dest];
    }
};

int main()
{
    graph g(6);
    g.addEdge(0,1,2);
    g.addEdge(0,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,4,2);
    g.addEdge(3,4,2);
    g.addEdge(3,5,2);

    cout<<g.dijkshtraAlgorithm(0,5)<<endl;

    return 0;
}