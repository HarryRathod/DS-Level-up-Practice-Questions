#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    string key;
    int value;

    node(string key,int value)
    {
        this->key=key;
        this->value=value;
    }
};

class LRUCache
{
public:
    int maxSize;
    list<node> l;
    unordered_map<string,list<node>::iterator > m;

    LRUCache(int size)
    {
        maxSize=size>1?size:1;
    }

    void insertKeyValue(string key,int value)
    {
        if(m.find(key)!=m.end())
        {
            auto it=m[key];
            it->value=value; ///here, it->value is indicating value of key in map 
                             ///& 2nd value is argument passed in function call.
                             ///here, simply we are doing an upadte operation.
        }
        else
        {
            if(l.size()==maxSize)
            {
                node n=l.back();
                l.pop_back();
                m.erase(n.key);
            }
            node n(key,value);
            l.push_front(n);
            m[key]=l.begin(); ///This will store the address of first element from list.
        }
    }

    int* getValue(string key) ///If key not found then it returning a NULL, due to which int* is written.
    {                         ///int * is returning a pointer.
        if(m.find(key)!=m.end())
        {
            auto it=m[key];

            l.push_front(*it);
            l.erase(it);
            return &l.begin()->value;  ///Here, we are passing an address of list's first element value
        }
        return NULL; ///If key is not present then it is returning a NULL.
    }

    string mostRecentKey()
    {
        return l.begin()->key;
    }
};

int main()
{
    LRUCache lru(3);

    lru.insertKeyValue("mango",20);
    lru.insertKeyValue("guave",10);
    lru.insertKeyValue("banana",30);

    cout<<lru.mostRecentKey()<<endl;

    int *v=lru.getValue("mango");
    if(v!=NULL)
        cout<<"Mango orders are "<<*v<<endl;

    lru.insertKeyValue("apple",40);

    if(lru.getValue("guava")==NULL)
        cout<<"Guava not found"<<endl;


    return 0;
}