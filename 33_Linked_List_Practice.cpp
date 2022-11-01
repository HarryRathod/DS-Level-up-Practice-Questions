#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void insertAtHead(node * &head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
    }
    else
    {
        node *n=new node(data);
        n->next=head;
        head=n;
    }
}

void insertAtMiddle(node *&head,int x)
{
    if(head==NULL)
    {
        head=new node(x);
        return;
    }
    node *a=head;
    node *b=head;
    int cnt=0;
    while(b)
    {
        b=b->next;
        cnt++;
    }
    cnt=cnt/2;
    for(int i=0;i<cnt-1;i++)
        a=a->next;
    node *temp=new node(x);
    temp->next=a->next;
    a->next=temp;
}

void printLL(node *head)
{
    if(head)
    {
        cout<<head->data<<"-->";
        printLL(head->next);
    }
}

void insertAtIndex(node *&head,int x,int index)
{
    if(index==0)
        insertAtHead(head,x);
    else{
        node *a=head;
        for(int i=0;i<index-1;i++)
        {
            a=a->next;
        }
        node *temp=new node(x);
        temp->next=a->next;
        a->next=temp;
    }
}

void reverseLL(node *&head)
{
    if(head==NULL)
        return ;
    node *p=NULL,*q=NULL;
    node *r=head;
    while(r)
    {
        p=q;
        q=r;
        r=r->next;
        q->next=p;
    }
    head=q;
}

void reverseLL2(node *&head,node *p,node *q)
{
    if(p)
    {
        reverseLL2(head,p->next,p);
        p->next=q;
    }
    else
        head=q;
}

node * reverseLL3(node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
    node *sHead=reverseLL3(head->next);
    head->next->next=head;
    head->next=NULL;
    return sHead;
}

node * kReverse(node *head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    node *pre=NULL;
    node *cur=head;
    node *temp;
    int cnt=1;

    while(cur!=NULL && cnt<=k)
    {
        temp=cur->next;
        cur->next=pre;

        pre=cur;
        cur=temp;
        cnt++;
    }

    if(temp!=NULL)
        head->next=kReverse(temp,k);
    return pre;
}

node *mergeLL(node *&head1,node *&head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    node *head=NULL;
    if(head1->data<head2->data)
    {
        head=head1;
        head->next=mergeLL(head1->next,head2);
    }
    else
    {
        head=head2;
        head->next=mergeLL(head1,head2->next);
    }
    return head;
}

node *mergeLL2(node *&head1,node *head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    node *head=NULL;

    if(head1->data<head2->data)
    {
        head=head1;
        head1=head1->next;
    }
    else
    {
        head=head2;
        head2=head2->next;
    }
    node *last=head;
    while(head1 && head2)
    {
        if(head1->data<head2->data)
        {
            last->next=head1;
            last=head1;
            head1=head1->next;
        }
        else
        {
            last->next=head2;
            last=head2;
            head2=head2->next;
        }
    }
    if(head1)
    {
        last->next=head1;
    }
    else
    {
        last->next=head2;
    }
    return head;
}

node *midPoint(node *head)
{
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node *mergeSortLL(node *head)
{
    if(head==NULL || head->next==NULL)
        return head;

    node *mid=midPoint(head);
    node *a=head;
    node *b=mid->next;
    mid->next=NULL;
    a=mergeSortLL(a);
    b=mergeSortLL(b);

    return mergeLL(a,b);
}

int main()
{
    node *head=NULL;

    insertAtHead(head,10);
    insertAtHead(head,4);
    insertAtHead(head,31);
    insertAtHead(head,22);
    insertAtHead(head,3);
    insertAtHead(head,1);
    insertAtHead(head,7);
    insertAtHead(head,8);
    insertAtHead(head,5);

    printLL(head);
    cout<<endl;

    // insertAtMiddle(head,10);
    // insertAtIndex(head,45,3);

    // printLL(head);
    // cout<<endl;

    // reverseLL(head);

    // printLL(head);
    // cout<<endl;

    // reverseLL2(head,head,NULL);

    // printLL(head);
    // cout<<endl;

    // head=reverseLL3(head);
    // printLL(head);
    // cout<<endl;

    // head=kReverse(head,3);
    // printLL(head);
    // cout<<endl;

    // node *head2=NULL;
    // insertAtHead(head2,13);
    // insertAtHead(head2,12);
    // insertAtHead(head2,11);
    // insertAtHead(head2,10);

    // printLL(head2);
    // cout<<endl;

    // head2=mergeLL2(head,head2);

    // printLL(head2);
    // cout<<endl;

    head=mergeSortLL(head);
    printLL(head);
    cout<<endl;

    return 0;
}