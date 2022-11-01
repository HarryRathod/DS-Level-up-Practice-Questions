#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    node *left;
    node *right;
};

class trie
{
    node *root;

public:
    trie()
    {
        root=new node();
    }

    void insert(int n)
    {
        node *temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit==0)
            {
                if(temp->left==NULL)
                    temp->left=new node();
                temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                    temp->right=new node();
                temp=temp->right;
            }
        }
    }

    int max_xor_helper(int n)
    {
        int curr_sum=0;
        node *temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit==0)
            {
                if(temp->right!=NULL)
                {
                    temp=temp->right;
                    curr_sum+=(1<<i);
                }
                else
                {
                        temp=temp->left;
                }
            }
            else
            {
                if(temp->left)
                {
                    temp=temp->left;
                    curr_sum+=(1<<i);
                }
                else
                {
                    temp=temp->right;
                }
            }            
        }
        return curr_sum;
    }

    int max_xor(int a[],int n)
    {
        int curr_sum=0;
        int max_sum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            insert(a[i]);
            int curr_sum=max_xor_helper(a[i]);
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }

};

int main()
{
    int a[]={3,10,5,25,9,2};
    int n=sizeof(a)/sizeof(int);
    trie t;

    cout<<t.max_xor(a,n)<<endl;

    return 0;
}