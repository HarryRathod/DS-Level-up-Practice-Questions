#include<bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

class node
{
public:
    char ch;
    bool isTerminal;
    unordered_map<char,node*> m;
    string word;

    node(char ch)
    {
        this->ch=ch;
        isTerminal=false;
        word="";
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

    void addWord(string word)
    {
        node *temp=root;
        for(auto c:word)
        {
            if(temp->m.count(c)==0)
                temp->m[c]=new node(c);
            temp=temp->m[c];
        }
        temp->isTerminal=true;
        temp->word=word;
    }
};

void dfs(char board[][N],node *t,int i,int j,bool visited[][N],unordered_set<string> &output)
{
    char c=board[i][j];
    if(t->m.count(c)==0)
        return;
    visited[i][j]=true;
    t=t->m[c];

    if(t->isTerminal)
    {
        output.insert(t->word);
    }

    int dx[]={1,1,0,-1,-1,-1,0,1};
    int dy[]={0,-1,-1,-1,0,1,1,1};

    for(int x=0;x<8;x++)
    {
        int xi=i+dx[x];
        int xj=j+dy[x];

        if(xi>=0 && xi<M && xj>=0 && xj<N && !visited[xi][xj])
            dfs(board,t,xi,xj,visited,output);
    }

    visited[i][j]=false;
    return;
}

int main()
{
    string words[]={"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};
    char board[M][N]={{'S','E','R','T'},
                      {'U','N','K','S'},
                      {'T','C','A','T'}};

    trie t;
    for(auto word:words)
    {
        t.addWord(word);
    }

    bool visited[M][N]={0};
    unordered_set<string> output;

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            dfs(board,t.root,i,j,visited,output);
        }
    }

    for(auto word:output)
    {
        cout<<word<<endl;
    }

    return 0;
}