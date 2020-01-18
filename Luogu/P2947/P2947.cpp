#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int n;
stack<int>s;
int a[100001],f[100001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>0;i--)
    {
        while(!s.empty()&&a[s.top()]<=a[i])
            s.pop();
        if(!s.empty()) f[i]=s.top();
        s.push(i);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",f[i]);
    return 0;
} 