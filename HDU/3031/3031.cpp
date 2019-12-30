#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=105;
int T,n,m;
int num[N];
int a[N][10005];
int main()
{
    scanf("%d",&T);
    int YP=0,WP=0;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        priority_queue<int> Y,W;
        for(int i=1;i<=m;i++)
            scanf("%d",&num[i]);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=num[i];j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
        {
            char ch;
            int k;
            for(ch=getchar();ch!='T'&&ch!='C'&&ch!='L'&&ch!='A'&&ch!='E';ch=getchar());
            if(ch=='T')
            {
                scanf("%d",&k);
                if(i%2)
                {
                    for(int i=1;i<=num[k];i++)
                        W.push(a[k][i]);
                }
                else
                {
                    for(int i=1;i<=num[k];i++)
                        Y.push(a[k][i]);
                }
            }
            if(ch=='C')
            {
                int y=Y.top(),w=W.top();
                if(y>w)
                {
                    while(!W.empty())
                    {
                        Y.push(W.top());
                        W.pop();
                    }
                }
                if(w>y)
                {
                    while(!Y.empty())
                    {
                        W.push(Y.top());
                        Y.pop();
                    }
                }
            }
            if(ch=='L')
            {
                if(i%2) W.pop();
                else Y.pop();
            }
            if(ch=='A')
            {
                scanf("%d",&k);
                if(i%2)
                {
                    int w=W.top()+k;
                    W.pop();
                    W.push(w);
                }
                else
                {
                    int y=Y.top()+k;
                    Y.pop();
                    Y.push(y);
                }
            }
            if(ch=='E')
            {
                scanf("%d",&k);
                if(i%2)
                {
                    W.pop();
                    W.push(k);
                }
                else
                {
                    Y.pop();
                    Y.push(k);
                }
            }
            
        }
        printf("%u:%u\n",W.size(),Y.size());
        if(Y.size()>W.size()) YP++;
        else WP++;
    }
    if(YP>WP) printf("I will be back!!\n");
    else printf("Hahaha...I win!!\n");
    return 0;
}