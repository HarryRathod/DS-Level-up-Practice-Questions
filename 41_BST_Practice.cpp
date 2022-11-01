#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int k)
    {
        data=k;
        left=NULL;
        right=NULL;
    }
};

node *createBST(node *root,int k)
{
    if(root==NULL)
        return new node(k);
    if(k<root->data)
    {
        root->left=createBST(root->left,k);
    }
    else
    {
        root->right=createBST(root->right,k);
    }
    return root;
}

bool search(node *root,int k)
{
    if(root==NULL)
        return false;
    if(k==root->data)
        return true;
    if(k<root->data)
        return search(root->left,k);
    else
        return search(root->right,k);
}

node *createBSTFromSortedArray(vector<int> arr,int s,int e)
{
    if(s>e)
        return NULL;
    int mid=(s+e)/2;
    node *root=new node(arr[mid]);
    
    root->left=createBSTFromSortedArray(arr,s,mid-1);
    root->right=createBSTFromSortedArray(arr,mid+1,e);

    return root;
}

int closestNode(node *root,int target)
{
    int closest;
    int min_diff=INT_MAX;
    node *temp=root;
    
    while(temp!=NULL)
    {
        int curr_diff=abs(temp->data-target);

        if(curr_diff==0)
            return temp->data;
        if(curr_diff<min_diff)
        {
            min_diff=curr_diff;
            closest=temp->data;
        }

        if(target<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    return closest;
}


class LL
{
public:
    node *head;
    node *tail;
};

LL BST2LL(node *root)
{
    LL l;
    if(root==NULL)
    {
        l.head=l.tail=NULL;
        return l;
    }

    if(root->left==NULL && root->right==NULL)
    {
        l.head=l.tail=root;
    }
    else if(root->left!=NULL && root->right==NULL)
    {
        LL leftL=BST2LL(root->left);
        leftL.tail->right=root;

        l.head=leftL.head;
        l.tail=root;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        LL rightR=BST2LL(root->right);
        root->right=rightR.head;

        l.head=root;
        l.tail=rightR.tail;
    }
    else
    {
        LL LeftL=BST2LL(root->left);
        LL rightR=BST2LL(root->right);

        LeftL.tail->right=root;
        root->right=rightR.head;

        l.head=LeftL.head;
        l.tail=rightR.tail;
    }
    return l;
}

node *inorderSucc(node *root,node *target)
{
    if(target->right!=NULL)
    {
        node *temp=root->right;
        while(temp->left!=NULL)
            temp=temp->left;
        return temp;
    }

    node *temp=root;
    node *succ;
    while(temp!=NULL)
    {
        if(target->data<temp->data)
        {
            succ=temp;
            temp=temp->left;
        }
        else if(target->data>temp->data)
        {
            temp=temp->right;
        }
        else
            break;
    }
    return succ;
}

void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<", ";
        inorder(root->right);
    }
}

int main()
{
    node *root=NULL;
    int arr[]={8,3,10,1,6,14,4,7,13};
    for(auto x:arr)
    {
        root=createBST(root,x);
    }

    inorder(root);
    cout<<endl;

    cout<<closestNode(root,4)<<endl;
    cout<<closestNode(root,11)<<endl;

    cout<<search(root,1)<<endl;
    cout<<search(root,15)<<endl;

    cout<<"BST to LL: "<<endl;
    LL head1=BST2LL(root);
    node *temp=head1.head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->right;
    }
    

    vector<int> v{1,2,3,4,5,6,7};
    node *root2=NULL;
    root2=createBSTFromSortedArray(v,0,v.size()-1);

    inorder(root2);
    cout<<endl;

    node *ans=inorderSucc(root2,root2);
    cout<<"Inorder Succesor: "<<ans->data<<endl;
    
    return 0;
}