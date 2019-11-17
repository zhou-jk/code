#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define for0(a, n) for (int (a) = 0; (a) < (n); (a)++)
#define for1(a, n) for (int (a) = 1; (a) <= (n); (a)++)
#define mes(a,x,s)  memset(a,x,(s)*sizeof a[0])
#define mem(a,x)  memset(a,x,sizeof a)
#define ysk(x)  (1<<(x))
#define sqr(x)  ((x)*(x))
typedef long long ll;
const int INF =0x3f3f3f3f;
const int maxn=30    ;
const int mod=19993    ;
const int N=500000;
int n,m,x,y;
int pre[maxn+3],cnt[maxn+3];
int find(int x)  { return x==pre[x]?x:pre[x]=find(pre[x]); }
bool cmp(int a,int b)  {return a>b;}

struct Code
{
   int a[32],s;
   Code()
   {
      mes(a,0,n);
      s=0;
   }
   void clear()
   {
       mes(a,0,n);
       s=0;
   }
   int normalize()
   {
       sort(a,a+n,cmp);
       s=0;
       for(int i=0;i<n;i++)
       {
           if(!a[i])  break;
           s=s*31+a[i];
           s%=mod;
       }
       return s;
   }
   bool operator==(const Code & y)const
   {
       for0(i,n)
       {
           if(!a[i])  break;
           if(a[i]!=y.a[i])  return false;
       }
       return true;
   }
   bool end()
   {
       return a[0]==n&&a[1]==0;
   }

};
typedef pair<Code, double> pcd;

struct Hsh
{
   vector<pcd>G[mod+3];
   void insert(Code & x,double& y)
   {
       int p=x.s;
       G[p].push_back(make_pair(x,y));
   }
   double find(Code x)
   {
       int p=x.s,siz=G[p].size();
       for0(i,siz)
       {
           if(G[p][i].first==x)  return G[p][i].second;
       }
       return -1;
   }
   void clear()
   {
       for0(i,mod)  G[i].clear();
   }


}hmp;



double DP(Code st)
{
    if(st.end())  return 0;
    double x=hmp.find(st);
    if(x>=-0.5)  return  x;
    int sum=0;double ans=0;
    int F=n*(n-1)/2;
    for0(i,n)
    {
        if(!st.a[i]) break;
        sum+=(st.a[i])*(st.a[i]-1)/2;
    }
    for0(i,n) for(int j=i+1;j<n;j++) if(st.a[i]&&st.a[j])
    {
        int ret=st.a[i]*st.a[j];
        Code t=st;
        t.a[i]=st.a[i]+st.a[j];
        t.a[j]=0;
        t.normalize();
        ans+=DP(t)*ret/F;
    }
    ans++;
    ans/=(1-   1.0*sum/F  );
    hmp.insert(st,ans);
    return ans;
}

void solve()
{
    hmp.clear();
    mes(cnt,0,n+1);
    for0(i,n)  cnt[find(i)]++;
    int tot=0;Code st;
    for0(i,n) if(cnt[i])
    {
        st.a[tot++]=cnt[i];
    }
    st.normalize();
    cout<<fixed<<setprecision(8)<<DP(st)<<endl;

}
int main()
{
   while(cin>>n>>m)
   {
       for0(i,n) pre[i]=i;
       for0(i,m)
       {
           cin>>x>>y;x--;y--;
           int tx=find(x),ty=find(y);
           if(tx!=ty)  pre[tx]=ty;
       }
       solve();
   }
   return 0;
}