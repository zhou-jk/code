#include<bits/stdc++.h>
using namespace std;
const int N=2019;
int n,ans;
bitset<N>L[N],R[N],a[N];
char str[N];
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%s",str+1);
        for(int j=1;j<i;j++)a[i][j]=str[j]-'0',a[j][i]='1'-str[j];
    }
    for(int i=1;i<=n;i++)L[i][i]=R[i][i]=1;
    for(int l=2;l<=n;l++)
    for(int i=1,j;i+l-1<=n;i++)
    {
        j=i+l-1;
        L[j][i]=(R[i+1]&L[j]&a[i]).count()!=0;
        R[i][j]=(L[j-1]&R[i]&a[j]).count()!=0;
		cerr<<"now"<<i<<" "<<j<<" "<<L[j][i]<<" "<<R[i][j]<<"\n";
    }
    for(int i=1;i<=n;i++)
    {if(R[1][i]&&L[n][i]) cout<<"pos"<<i<<endl;ans+=R[1][i]&&L[n][i];}
    printf("%d",ans);
}
