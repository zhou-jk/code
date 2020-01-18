#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<unordered_map>
using namespace std;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
unordered_map<int,int> book;
int s;
int c[4][4];
queue<int>q;
int main()
{
    scanf("%d",&s);
    book[s]=0;
    q.push(s);
    if(s==123804765)
    {
        printf("0");
        return 0;
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int temp=u;
        int x,y;
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                c[i][j]=temp%10,temp/=10;
                if(c[i][j]==0) x=i,y=j;
            }
        for(int i=0;i<4;i++)
        {
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<1||ty>3||ty<1||ty>3) continue;
            swap(c[x][y],c[tx][ty]);
            int t=0;
            for(int j=3;j>=1;j--)
                for(int k=3;k>=1;k--)
                    t=t*10+c[j][k];
            swap(c[x][y],c[tx][ty]);
            if(book.count(t)) continue;
            book[t]=book[u]+1;
            if(t==123804765)
            {
                printf("%d",book[t]);
                return 0;
            }
            q.push(t);
        }
    }
    return 0;
}