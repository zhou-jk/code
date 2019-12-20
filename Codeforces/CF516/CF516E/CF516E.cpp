#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
inline ll read(){
	ll s=0; bool f=0; char ch=' ';
	while(!isdigit(ch))	{f|=(ch=='-'); ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
	return (f)?(-s):(s);
}
inline void write(ll x){
	if(x<0) {putchar('-'); x=-x;}
	if(x<10) {putchar(x+'0'); return;}
	write(x/10); putchar((x%10)+'0');
}
#define PI pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int N=200005;
int n,m,A,B;
PI q[N];
ll ans;
set<ll> sa,sb;
set<ll>::iterator it;
vector<ll> v[N];
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
    {
		x=1; y=0; return a;
	}
	long long d=exgcd(b,a%b,x,y);
    long long tmp=x;
    x=y,y=tmp-a/b*y;
    return d;
}
ll getinv(ll a,ll b)
{
	ll x,y;
	exgcd(a,b,x,y);
	return (x+b)%b;
}
void solve(vector<ll> v,ll n,ll m,ll d){
	if(!v.size()){
		puts("-1"); exit(0);
	}
	n/=d; m/=d;
	ll inv=getinv(m,n),o=v.size();
	//For(i,0,o-1)cout<<v[i]<<endl;
	For(i,0,o-1)q[i]=mp((ll)v[i]/d*inv%n,v[i]);
	sort(q,q+o);
	For(i,0,o-1){
		if((q[i].fi+1-q[(i+1)%o].fi)%n){
			//cout<<q[i].se<<" "<<(q[(i+1)%o].fi-q[i].fi+n-1)<<endl;
			ans=max(ans,q[i].se+(q[(i+1)%o].fi-q[i].fi+n-1)%n*m*d);
		}
	}
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&A);
    for(int i=1;i<=A;i++)
    {
        int x;
        scanf("%d",&x);
        sa.insert(x);
    }
    scanf("%d",&B);
    for(int i=1;i<=B;i++)
    {
        int x;
        scanf("%d",&x);
        sb.insert(x);
    }
	if(n<m)
    {
		swap(n,m);
        swap(A,B);
        swap(sa,sb);
	}
	bool flag=true;
    for(int i=0;i<n;i++)
        if(!sa.count(i)&&!sb.count(i))
        {
            flag=false;
            break;
        }
	if(flag)
    {
		int ans=-1;
        for(int i=0;i<m;i++)
		    if(!sa.count(i)||!sb.count(i)) ans=i;
        printf("%d",ans);
		return 0;
	}
	int d=gcd(n,m); 
	if(d>n+m)
    {
		printf("-1");
        return 0;
	}
    for(auto u:sa)
        v[u%d].push_back(u);
    for(auto u:sb)
        if(!sa.count(u)) v[u%d].push_back(u);
	// for(it=sa.begin();it!=sa.end();it++)v[*it%d].pb(*it);
	// for(it=sb.begin();it!=sb.end();it++)if(!sa.count(*it))v[*it%d].pb(*it);
	For(i,0,d-1)solve(v[i],n,m,d);
	cout<<ans<<endl;
	return 0;
}

