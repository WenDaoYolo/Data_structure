#include<iostream>
#include<iomanip>
#define RLEN 4
#define CLEN RLEN
#define INVALID -1
#define X 999

void OutputGraphInfo(const char* str,int(*graph)[RLEN])
{
    std::cout<<str<<std::endl;
    for(int i=0;i<RLEN;i++)
    {
        for(int j=0;j<CLEN;j++)
        {
            if(graph[i][j]!=X)
                std::cout<<"vertex"<<i<<" to vertex"<<j<<" have edge"<<std::endl;
        }
    }
}

void InitFloyd(int(*P)[RLEN],int(*D)[RLEN],int(*G)[RLEN])
{
    for(int i=0;i<RLEN;i++)
    {
        for(int j=0;j<CLEN;j++)
        {
            if(i==j)//自己到自己
            {
                P[i][j]=INVALID;
                D[i][j]=0;
            }//相邻
            else if(G[i][j]!=X)
            {
                P[i][j]=i;
                D[i][j]=G[i][j];
            }//不相邻
            else
            {
                P[i][j]=INVALID;
                D[i][j]=X;
            }
        }
    }
}

void OutputFloydTableInfo(int(*P)[RLEN],int(*D)[RLEN])
{
    for(int i=0;i<RLEN;i++)
        std::cout<<std::left<<std::setw(5)<<"      "<<i<<"     ";
    std::cout<<std::endl;

    for(int i=0;i<RLEN;i++)
    {
        for(int j=0;j<CLEN;j++)
        {
            if(j==0)
                std::cout<<i;
            std::cout<<"  "<<P[i][j]<<"("<<D[i][j]<<")"<<std::left<<std::setw(5)<<"  ";
        }
        std::cout<<std::endl;
    }
}

void Floyd(const char* str,int(*G)[RLEN])
{
    int P[RLEN][CLEN];
    int D[RLEN][CLEN];
    InitFloyd(P,D,G);

    for(int mid=0;mid<RLEN;mid++)
    {   
        for(int start=0;start<RLEN;start++)
        {
            for(int target=0;target<RLEN;target++)
            {
                //自己到自己，中间点通过中间点到某点，某点通过中间点到中间点
                if(start==target||start==mid||target==mid)
                    continue;

                if(D[start][mid]+D[mid][target]<D[start][target])
                {
                    D[start][target]=D[start][mid]+D[mid][target];
                    P[start][target]=P[mid][target];
                }
            }
        }
    }

    std::cout<<str<<std::endl;
    OutputFloydTableInfo(P,D);
}

int main()
{
    int graph[RLEN][CLEN]=
    {
        X,10,X,15,
        X,X,6,X,
        4,X,X,X,
        X,X,3,X
    };

    OutputGraphInfo("graph info:",graph);
    std::cout<<std::endl;
    Floyd("graph floyd info:",graph);

    return 0;
}