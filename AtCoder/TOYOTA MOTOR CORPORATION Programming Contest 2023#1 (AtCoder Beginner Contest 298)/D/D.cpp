#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=600005;
const int MOD=998244353;
int n,q;
int pw10[N];
queue<int>s;
int sum;
void init(int n=600000)
{
    pw10[0]=1;
    for(int i=1;i<=n;i++)
        pw10[i]=(long long)pw10[i-1]*10%MOD;
    return;
}
int main()
{
    init();
    n=1;
    s.emplace(1);
    sum=1;
    scanf("%d",&q);
    while(q--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int x;
            scanf("%d",&x);
            s.emplace(x);
            n++;
            sum=((long long)sum*10+x)%MOD;
        }
        else if(op==2)
        {
            sum=(sum-(long long)s.front()*pw10[n-1]%MOD+MOD)%MOD;
            s.pop();
            n--;
        }
        else if(op==3)
        {
            printf("%d\n",sum);
        }
    }
    return 0;
}