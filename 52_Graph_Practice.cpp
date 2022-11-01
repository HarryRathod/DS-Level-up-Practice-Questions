/// This code is showing how to represent GRAPH by using Adjacency List Method.
#include<bits/stdc++.h>
using namespace std;

class graph
{
    int v;
    list<int> *l;

public:
    graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }

    void addEdge(int i,int j,bool bid=true)
    {
        l[i].push_back(j);
        if(bid)
        {
            l[j].push_back(i);
        }
    }

    void printGraph()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"-->";
            for(auto node:l[i])
                cout<<node<<",";
            cout<<endl;
        }
    }

    void BFS(int s,int dest=-1)
    {
        /// here, if we want to find out the shortest path b/w two nodes then pass them as s & dest.
        /// if dest is not -1 then this function will give the shortest path b/w theose 2 nodes.
        queue<int> q;
        bool *visited=new bool[v]{false};
        int *dist=new int[v]{0};
        int *parent=new int[v];

        for(int i=0;i<v;i++)
            parent[i]=-1;

        parent[s]=s;

        q.push(s);
        visited[s]=true;

        while (!q.empty())
        {
            int cv=q.front();
            q.pop();
            ///cout<<cv<<endl;
            for(auto nbr:l[cv])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=cv;
                    dist[nbr]=dist[cv]+1;
                }
            }
        }
        for(int i=0;i<v;i++)
        {
            cout<<"Shortest Distance to "<<i<<" is "<<dist[i]<<endl;
        }

        if(dest!=-1)
        {
            int temp=dest;
            while(temp!=s)
            {
                cout<<temp<<"--";
                temp=parent[temp];
            }
            cout<<s<<endl;
        }
    }

    void helper(int s,bool *&visited)
    {
        cout<<s<<endl;
        visited[s]=true;
    }

    void DFS(int s)
    {
        bool *visited=new bool[v]{0};
        cout<<s<<endl;
        visited[s]=true;

        for(auto cv:l[s])
        {
            if(visited[cv]==false)
            {
                helper(cv,visited);
            }
        }
    }

    bool cycle_helper(int s,bool *&visited,int parent)
    {
        visited[s]=true;
        for(auto nbr:l[s])
        {
            if(visited[nbr]==false)
            {
                bool cycleFound=cycle_helper(nbr,visited,s);
                if(cycleFound)
                    return true;
            }
            else if(s!=parent)
                return true;
        }
        return false;
    }

    bool detect_cycle()
    {
        bool *visited=new bool[v]{0};
        return cycle_helper(0,visited,-1);
    }

    bool directed_cycle_helper(int s,vector<bool> &visited,vector<bool> &stack)
    {
        visited[s]=true;
        stack[s]=true;

        for(auto nbr:l[s])
        {
            if(stack[nbr]==true)
                return true;
            else if(!visited[nbr]==false)
            {
                bool nbrFoundCycle=directed_cycle_helper(nbr,visited,stack);
                if(nbrFoundCycle)
                    return true;
            }
        }
        stack[s]=false;
        return false;
    }

    bool cycle_in_directed(int s)
    {
        vector<bool> visited(v,false);
        vector<bool> stack(v,false);

        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                bool detectCycle=directed_cycle_helper(i,visited,stack);
                if(detectCycle)
                    return true;
            }
        }
        return false;
    }

};

class WGraph  /// Weighted Graph
{
    int v;
    list<pair<int,int> > *l;

public:
    WGraph(int v)
    {
        this->v=v;
        l=new list<pair<int,int> >[v];
    }    

    void addEdge(int i,int j,int w,bool unid=true)
    {
        l[i].push_back({j,w});
        if(unid)
        {
            l[j].push_back({i,w});
        }
    }

    void printWG()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"-->";
            for(auto gpair:l[i])
            {
                cout<<"("<<gpair.first<<","<<gpair.second<<"),";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);

    g.printGraph();

    cout<<"BFS Traversal:"<<endl;
    g.BFS(0,3);

    cout<<"DFS Treversal:"<<endl;
    g.DFS(0);

    cout<<"Cycle Status: "<<g.detect_cycle()<<endl;

    cout<<"Weighted Graph"<<endl;
    WGraph wg(4);
    wg.addEdge(0,1,1);
    wg.addEdge(0,2,2);
    wg.addEdge(0,3,3);
    wg.addEdge(1,2,3);
    wg.addEdge(2,3,5);
    wg.addEdge(1,3,4);

    wg.printWG();

    /// Directed Graph Practice
    graph dg(3);
    dg.addEdge(0,1,false);
    dg.addEdge(1,2,false);
    dg.addEdge(2,0,false);

    cout<<"Directed Graph: "<<endl;
    dg.printGraph();

    cout<<dg.cycle_in_directed(0)<<endl;

    return 0;
}