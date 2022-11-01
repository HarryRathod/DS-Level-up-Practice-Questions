#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *builtTree()
{
    int d;
    cin >> d;

    if (d == -1)
        return NULL;
    node *n = new node(d);
    n->left = builtTree();
    n->right = builtTree();

    return n;
}

node *builtFromLevelOrder()
{
    int x;
    cout<<"Enter the value of root :";
    cin>>x;
    node *root=new node(x);
    queue<node *> q;
    q.push(root);

    while(!q.empty())
    {
        node *f=q.front();
        q.pop();
        int l;
        cout<<"Enter the left child of "<<f->data<<": ";
        cin>>l;
        if(l!=-1)
        {
            node *le=new node(l);
            f->left=le;
            q.push(le);
        }
        int r;
        cout<<"Enter the right child of "<<f->data<<": ";
        cin>>r;
        if(r!=-1)
        {
            node *ri=new node(r);
            f->right=ri;
            q.push(ri);
        }
    }
    return root;
}

void preoreder(node *p)
{
    if (p)
    {
        cout << p->data << ", ";
        preoreder(p->left);
        preoreder(p->right);
    }
}

void levelorder(node *p)
{
    queue<node *> q;
    q.push(p);
    q.push(NULL);
    while (!q.empty())
    {
        node *f = q.front();
        q.pop();
        if (f == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << f->data << ",";
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
}

int height(node *root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));    
}

int diameter(node *root)
{
    if(root==NULL)
        return 0;
    int op1=height(root->left)+height(root->right);
    int op2=diameter(root->left);
    int op3=diameter(root->right);

    return max(op1,max(op2,op3));
}

pair<int,int> diameter2(node *p)
{
    if(p==NULL)
    {
        return {0,0};
    }
    pair<int,int> leftAns=diameter2(p->left);
    pair<int,int> rightAns=diameter2(p->right);

    int lh=leftAns.first;
    int ld=leftAns.second;

    int rh=rightAns.first;
    int rd=rightAns.second;

    pair<int,int> ans;
    ans.first=1+max(lh,rh);
    ans.second=max(lh+rh,max(ld,rd));
    return ans;
}

int replaceWithDescendantSum(node *&root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int temp=root->data;
    root->data=replaceWithDescendantSum(root->left)+replaceWithDescendantSum(root->right);
    return temp+root->data;
}

pair<int,bool> isHeigthBalancedTree(node *root)
{
    // This function will check whether Binart Tree is Height Balanced BT or not.
    // Simultaneously it's also calculating Height of BT in Order of Time O[N].

    pair<int,bool> p,Left,Right;
    if(root==NULL)
    {
        p.first=0;
        p.second=true;
        return p;
    }
    Left=isHeigthBalancedTree(root->left);
    Right=isHeigthBalancedTree(root->right);

    int h=1+max(Left.first,Right.first);

    if(abs(Left.first-Right.first)<=1 && Left.second && Right.second)
        return make_pair(h,true);
    return make_pair(h,false);
}



class Pair
{
public:
    int inc;
    int exc;
};

Pair maxSubsetSum(node *root)
{
    /// PROBLEM - In this we have to find the max sum of nodes but if we consider a node then we can not consider it's parent & children nodes.
    /// this has Order of Time O[N]

    Pair p,Left,Right;
    if(root==NULL)
    {
        p.inc=p.exc=0;
        return p;
    }
    Left=maxSubsetSum(root->left);
    Right=maxSubsetSum(root->right);

    p.inc=root->data+Left.exc+Right.exc;
    p.exc=max(Left.inc,Left.exc)+max(Right.inc,Right.exc);

    return p;

}

int main()
{
    //node *root = builtTree();

    // preoreder(root);
    // cout << endl;
    // levelorder(root);

    node *root=builtFromLevelOrder();
    preoreder(root);
    cout<<endl;
    levelorder(root);

    cout<<endl<<"diameter : "<<diameter(root)<<endl;
    cout<<"diameter 2: "<<diameter(root)<<endl;

    // cout<<"After Repalcing with Descendant Sum: "<<endl;
    // replaceWithDescendantSum(root);
    // levelorder(root);
    // cout<<endl;

    // pair<int,bool> p=isHeigthBalancedTree(root);
    // if(p.second)
    //     cout<<"Yes, BT is Heigth Balanced"<<endl;
    // else
    //     cout<<"No, BT is not Balanced"<<endl;

    Pair P=maxSubsetSum(root);
    cout<<"Max sum is :"<<max(P.inc,P.exc)<<endl;

    return 0;
}