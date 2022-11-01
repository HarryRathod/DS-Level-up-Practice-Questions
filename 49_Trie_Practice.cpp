#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    unordered_map<char,node*> m;
    bool isTerminal;

    node(char d)
    {
        data=d;
        isTerminal=false;
    }
};

class trie
{
public:
    node *root;

    trie()
    {
        root=new node('\0');
    }

    void insert(string s)
    {
        node *temp=root;
        for(char ch:s)
        {
            if(temp->m.count(ch)==0)
            {
                temp->m[ch]=new node(ch);
            }
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }

    bool search(string s)
    {
        node *temp=root;
        for(char ch:s)
        {
            if(temp->m.count(ch)==0)
                return false;
            temp=temp->m[ch];
        }
        return temp->isTerminal;
    }
};

int main()
{
    trie t;
    t.insert("new");
    t.insert("news");
    t.insert("north");
    t.insert("west");

    cout<<t.search("new")<<endl;
    cout<<t.search("newz")<<endl;


    return 0;
}