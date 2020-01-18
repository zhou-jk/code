#include<bits/stdc++.h>
#define hash fuck
#define int long long
using namespace std;
int const maxn=2005;
int const p=1e9+7;
int const base=19260817;
int n,m,f[2][maxn][maxn],po[maxn];
char a[2][maxn],b[maxn];
struct node{
	int hash[maxn];
	inline void make(char *s){
		hash[0]=0;
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)
		  hash[i]=(hash[i-1]*base%p+s[i])%p;
	}
	inline int query(int l,int r){
		return ((hash[r]-hash[l-1]*po[r-l+1]%p)%p+p)%p;
	}
}pre[2],suf[2],ss;
inline int dp(bool rev){
	int res=0;
	memset(f,0,sizeof(f));
	for(int j=1;j<=n;j++){
		f[0][j][0]=f[1][j][0]=1;//标新立异地不从左U开始
		 
		//考虑接下来接上一个右U，给结尾加点花样 （标新立异者将会在第53行处理） 
		for(int i=0;i<2;i++) 
		  for(int k=2;k<=min(m/2,n-j+1);k++)
		  //k最小是2，因为必须是一个U形，k最大不能超过m，不然U形填不完，k最大也不能超过n-j+1，否则U形放不下
		    if(ss.query(m-2*k+1,m-k)==pre[i].query(j,j+k-1) && ss.query(m-k+1,m)==suf[i^1].query(n-(j+k-1)+1,n-j+1))
			//弯过去                                             弯回来 
			  if(2*k!=m || rev)//如果只有一个U，没有中间的东西，那么在反转之后会被计算两次 
	            res=(res+f[i][j][m-2*k])%p;
	    
		//考虑从一个左U开始我的表演（标新立异者已经在第26行处理掉了） 
		for(int i=0;i<2;i++) 
		  for(int k=2;k<=min(m/2,j);k++)//这里与上面相同
		    if(ss.query(k+1,2*k)==pre[i].query(j-k+1,j) && ss.query(1,k)==suf[i^1].query(n-j+1,n-(j-k+1)+1))
			//弯回来                                      弯过去 
			  if(2*k!=m || rev)
			    f[i][j+1][2*k]=(f[i][j+1][2*k]+1)%p;
		
		//考虑在中间弯来弯去 
		for(int i=0;i<2;i++)
		  for(int k=0;k<m;k++)
		    if(a[i][j]==b[k+1]){
		       f[i][j+1][k+1]=(f[i][j+1][k+1]+f[i][j][k])%p;//直接往右 
		       if(k+2<=m && a[i^1][j]==b[k+2])
		         f[i^1][j+1][k+2]=(f[i^1][j+1][k+2]+f[i][j][k])%p;//调整一下方向，然后往右
		    }
		//结算答案，顺便把那些标新立异，不以右U结尾的算进去
		for(int i=0;i<2;i++)
		  res=(res+f[i][j+1][m])%p;//注意这里是j+1，因为我们强迫自己往右边走，所以答案会掉到右边去 
	}         
	return res;
}
signed main(){
	po[0]=1;
	for(int i=1;i<=2000;i++)
	  po[i]=po[i-1]*base%p;
	for(int i=0;i<2;i++)
	  scanf("%s",a[i]+1);
	n=strlen(a[0]+1);
	scanf("%s",b+1);
	m=strlen(b+1);
	for(int i=0;i<2;i++){
		pre[i].make(a[i]);
		reverse(a[i]+1,a[i]+n+1);
		suf[i].make(a[i]);
		reverse(a[i]+1,a[i]+n+1);
	}
	ss.make(b+1);
	int ans=dp(true);
	if(m>1){//=1禁止反转
	     reverse(b+1,b+m+1);
	     ss.make(b);
	     ans=(ans+dp(false))%p;
	     if(m==2){//=2时在中间弯来弯去也会导致重复计算 
	         for(int j=1;j<=n;j++)
	           for(int i=0;i<2;i++)
	     	     if(a[i][j]==b[1] && a[1^1][j]==b[2])
	     	       ans=(ans-1+p)%p;
		 }
	}
	printf("%lld\n",ans);
	return 0;
}