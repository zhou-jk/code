#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double ans1,ans2,ans3;
int n,num[2],last[2],a[100001],b[100001];
void solve(int x)
{
    memset(num,0,sizeof(num));
    memset(last,0,sizeof(last));
    for(int i=1;i<=n;i++)
		b[i]=((a[i]>>x)&1);
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
        {
            ans1+=(double)(1<<x)/n/n*num[!b[i]];
            if(b[i]==0) ans3+=(double)(1<<x)/n/n*last[1];    
            else ans3+=(double)(1<<x)/n/n*(i-1),ans2+=(double)(1<<x)/n/n*(i-1-last[0]);
        }
        last[b[i]]=i;
        if(b[i]==0) num[0]++;
        else swap(num[0],num[1]),num[1]++; 
    }
    for(int i=1;i<=n;i++) 
    if(b[i])
    {
        double tmp=(double)(1<<x)/n/n/2;
        ans1+=tmp,ans2+=tmp,ans3+=tmp;
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    for(int i=0;i<=30;i++)
		solve(i);
    printf("%.3lf %.3lf %.3lf",ans1*2,ans2*2,ans3*2);
    return 0;
}
