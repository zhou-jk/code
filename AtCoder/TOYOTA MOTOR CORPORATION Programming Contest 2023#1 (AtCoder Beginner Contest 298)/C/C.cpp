#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n,q;
set<int>s[N];
vector<int>g[N];
int main()
{
    scanf("%d%d",&n,&q);
    while(q--)
    {
        int op,i,j;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&i,&j);
            g[j].emplace_back(i);
            s[i].insert(j);
        }
        else if(op==2)
        {
            scanf("%d",&i);
            sort(g[i].begin(),g[i].end());
            for(const int &v:g[i])
                printf("%d ",v);
            printf("\n");
        }
        else if(op==3)
        {
            scanf("%d",&i);
            for(const int &v:s[i])
                printf("%d ",v);
            printf("\n");
        }
    }
    return 0;
}