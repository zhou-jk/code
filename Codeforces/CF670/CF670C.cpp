#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=200001;
int n,m;
map<int,int> book;
int b[N],c[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        book[x]++;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    int max1=0,max2=0;
    int id=1;
    for(int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)
        if(book[b[i]]>max1||(book[b[i]]==max1&&book[c[i]]>max2)) max1=book[b[i]],max2=book[c[i]],id=i;
    printf("%d",id);
    return 0;
}