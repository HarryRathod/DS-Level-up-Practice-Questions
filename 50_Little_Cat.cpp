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
                temp->m[ch]=new node(ch);
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }
};

void helper(string doc,trie t,unordered_map<string,bool> &mymap,int i)
{
    node *temp=t.root;
    for(int j=i;j<doc.length();j++)
    {
        char ch=doc[j];
        if(temp->m.count(ch)==0)
            return;
        temp=temp->m[ch];
        if(temp->isTerminal==true)
        {
            string out=doc.substr(i,j-i+1);
            mymap[out]=true;
        }
    }
    return;
}

void search(vector<string> words,string doc)
{
    trie t;
    for(auto word:words)
    {
        t.insert(word);
    }

    unordered_map<string,bool> mymap;
    for(int i=0;i<doc.length();i++)
    {
        helper(doc,t,mymap,i);
    }

    for(auto word:words)
    {
        if(mymap[word])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return;
}

int main()
{
    string doc="little cute cat loves to code in c++,java & python";
    vector<string> words={"cute cat","ttle","cat","quick","big"};

    search(words,doc);

    return 0;
}