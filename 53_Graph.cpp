/// This code is showing how to represent different cities by using Adjacency List Method.

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    string name;
    list<string> nbrs;

    node(string name)
    {
        this->name=name;
    }
};

class graph
{
    unordered_map<string,node*> m;

public:
    graph(vector<string> cities)
    {
        for(auto city:cities)
        {
            m[city]=new node(city);
        }
    }

    void addEdge(string x,string y,bool unid=false)
    {
        m[x]->nbrs.push_back(y);

        if(unid)
        {
            m[y]->nbrs.push_back(x);
        }
    }

    void printGraph()
    {
        for(auto nodePair:m)
        {
            auto city=nodePair.first;
            node *cityNode=nodePair.second;

            cout<<city<<"-->";
            for(auto nbr:cityNode->nbrs)
                cout<<nbr<<",";
            cout<<endl;
        }
    }
};

int main()
{
    vector<string> cities={"Delhi","London","Paris","New York"};

    graph g(cities);

    g.addEdge("Delhi","London");
    g.addEdge("New York","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");

    g.printGraph();

    return 0;
}