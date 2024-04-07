#include<bits/stdc++.h>
using namespace std;

bool isSafe(int a[][9],int i,int j,int no)
{
    for(int k=0;k<9;k++)
    {
        if(a[k][j]==no || a[i][k]==no)
            return false;
    }
    int sx=(i/3)*3;
    int sy=(j/3)*3;
    for(int i=sx;i<sx+3;i++)
    {
        for(int j=sy;j<sy+3;j++)
        {
            if(a[i][j]==no)
                return false;
        }
    }
    return true;
}

bool isSafe2(int a[][9],int &i,int &j,int &no) //This function is very faster then above function.
    {
        for(int k=0;k<9;k++)
        {
            if(board[k][j]==no || board[i][k]==no) return false;
            if(board[3*(i/3)+(k/3)][3*(j/3)+(k%3)]==no) return false;
        }
        return true;
    }

bool soduko(int a[][9],int i,int j,int n)
{
    if(i==n)
        return true;
    if(j==n)
        return soduko(a,i+1,0,n);
    if(a[i][j]!=0)
        return soduko(a,i,j+1,n);

    for(int no=1;no<=9;no++)
    {
        if(isSafe(a,i,j,no))
        {
            a[i][j]=no;
            bool solveSubProblem=soduko(a,i,j+1,n);
            if(solveSubProblem)
                return true;
        }
    }
    a[i][j]=0;
    return false;
}

int main()
{
    int a[9][9]={{5,3,0,0,7,0,0,0,0},
                 {6,0,0,1,9,5,0,0,0},
                 {0,9,8,0,0,0,0,6,0},
                 {8,0,0,0,6,0,0,0,3},
                 {4,0,0,8,0,3,0,0,1},
                 {7,0,0,0,2,0,0,0,6},
                 {0,6,0,0,0,0,2,8,0},
                 {0,0,0,4,1,9,0,0,5},
                 {0,0,0,0,8,0,0,7,9}};
    if(soduko(a,0,0,9))
    {
        cout<<"Soduko Solved!"<<endl;
        for(int i=0;i<9;i++){
            for(int y=0;y<9;y++)
                cout<<a[i][y]<<",";
            cout<<endl;
        }
    }
    else{
        cout<<"Soultion not Possible!"<<endl;
    }
    return 0;
}
