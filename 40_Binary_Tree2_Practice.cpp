#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};

void printAtKLevel(node *p,int k)
{
    if(p==NULL)
        return;
    if(k==0)
    {
        cout<<p->data<<",";
        return ;
    }
    printAtKLevel(p->left,k-1);
    printAtKLevel(p->right,k-1);
    return ;
}

int nodesAtDistanceK(node *p,node *target,int k)
{
    if(p==NULL)
        return -1;
    if(p==target)
    {
        printAtKLevel(target,k);
        return 0;
    }

    int DL=nodesAtDistanceK(p->left,target,k);
    if(DL!=-1)   /// DL- Distance at Left side of Node
    {
        if(DL+1==k)
        {
            cout<<p->data<<",";
        }
        else{
            printAtKLevel(p->right,k-2-DL);
        }
        return 1+DL;
    }

    int DR=nodesAtDistanceK(p->right,target,k);
    if(DR!=-1)     /// DR - Distance at Right side of Node
    {
        if(DR+1==k)
            cout<<p->data<<",";
        else
        {
            printAtKLevel(p->left,k-DR-2);
        }
        return 1+DR;
    }
    return -1;
}

void helper(node *root,int d,map<int,vector<int> > &m)
{
    if(root==NULL)
        return;
    m[d].push_back(root->data);
    helper(root->left,d-1,m);
    helper(root->right,d+1,m);
}

void vericalTraversal(node *root)
{
    if(root==NULL)
        return;
    map<int,vector<int> > m;
    helper(root,0,m);

    for(auto it:m)
    {
        for(auto x:it.second)
            cout<<x<<",";
        cout<<endl;
    }
    
}

void levelorder(node *p)
{
    if(p==NULL)
        return;
    queue<node *> q;
    q.push(p);
    q.push(NULL);
    cout<<p->data<<endl;

    while(!q.empty())
    {
        node *f=q.front();
        q.pop();
        if(f==NULL)
        {
            if(q.size()==0)
                return;
            else
            {
                cout<<endl;
                q.push(NULL);
            }
        }
        else
        {
            if(f->left)
            {
                cout<<f->left->data<<",";
                q.push(f->left);
            }
            if(f->right)
            {
                cout<<f->right->data<<",";
                q.push(f->right);
            }
        }
    }
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->left->left->right=new node(9);

    node *target=root->left;
    levelorder(root);
    
    cout<<"Print at level k : "<<endl;
    printAtKLevel(root,2);
    cout<<endl<<"Print at level k Advance Version: "<<endl;
    nodesAtDistanceK(root,target,2);


    cout<<"Vertical order Traversal: "<<endl;
    vericalTraversal(root);

    return 0;

}