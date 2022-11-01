#include<bits/stdc++.h>
using namespace std;

char * mystrtok(char *str,char delim)
{
    static char*input=NULL;
    if(str!=NULL)
        input=str;
    if(input==NULL)
        return NULL;

    char *token=new char(strlen(input)+1);
    int i;
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]!=delim)
            token[i]=input[i];

        else
        {
            token[i]='\0';
            input=input+i+1;
            return token;
        }
    }

    token[i]='\0';
    input=NULL;
    return token;
}

int main()
{
    char s[]="Hello How are you?";
    //getline(cin,s);

    ///-----------FIRST METHOD----------------------------------------------
    // stringstream ss(s);
    // string token;
    // vector<string> tokens;
    // while(getline(ss,token,' '))
    // {
    //     tokens.push_back(token);
    // }

    // for(auto token:tokens)
    //     cout<<token<<endl;


    ///---------------------------SECOND METHOD-----------------------------------

    // char *token=strtok(s," ");

    // while(token!=NULL)
    // {
    //     cout<<token<<endl;
    //     token=strtok(NULL," ");
    // }



    ///--------------THIRD METHOD---------------------------------------------
    char *token1=mystrtok(s,' ');
    
    while (token1!=NULL)
    {
        cout<<token1<<endl;
        token1=mystrtok(NULL,' ');
    }   


    return 0;
}