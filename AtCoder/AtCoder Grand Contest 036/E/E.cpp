#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000005;
int n;
char str[N],s[N];
int cnt[4];
int id[4];
int pre[N],nxt[N];
void del(int i)
{
	pre[nxt[i]]=pre[i];
	nxt[pre[i]]=nxt[i];
	return;
}
int main()
{
	scanf("%s",str+1);
	for(size_t i=1;i<=strlen(str+1);i++)
		if(str[i]!=str[i-1]) s[++n]=str[i];
	for(int i=1;i<=n;i++)
		cnt[s[i]-'A'+1]++;
	id[1]=1,id[2]=2,id[3]=3;
	sort(id+1,id+3+1,[=](const int &x,const int &y){return cnt[x]<cnt[y];});
	sort(cnt+1,cnt+3+1);
	for(int i=1;i<=n;i++)
		nxt[i]=i+1,pre[i]=i-1;
	nxt[0]=1,pre[n+1]=n;
	int head=0,tail=n+1;
	for(int i=head;i!=tail&&cnt[2]<cnt[3];i=nxt[i])
		if(i&&nxt[i]&&s[i]==id[3]+'A'-1&&s[pre[i]]!=s[nxt[i]]) cnt[3]--,del(i);
	if(cnt[2]<cnt[3])
	{
		for(int i=head;i!=tail&&cnt[2]<cnt[3];i=nxt[i])
			if(i&&pre[i]&&nxt[i]&&s[i]==id[3]+'A'-1&&s[pre[i]]==s[nxt[i]]&&s[pre[i]]==id[1]+'A'-1)
			{
				cnt[1]--,cnt[3]--;
				del(pre[i]),del(i);
			}
	}
	if(cnt[2]!=cnt[3]) return 0;
	if(cnt[1]<cnt[2])
	{
		for(int i=head;i!=tail&&cnt[1]<cnt[2];i=nxt[i])
		{
			if(i&&pre[i]&&s[pre[i]]!=id[1]+'A'-1&&s[i]!=id[1]+'A'-1)
			{
				if(s[pre[pre[i]]]==id[1]+'A'-1&&s[nxt[i]]==id[1]+'A'-1) continue;
				cnt[2]--,cnt[3]--;
				del(pre[i]),del(i);
			}
		}
	}
	if(cnt[1]!=cnt[2]||cnt[2]!=cnt[3]) return 0;
	for(int i=head;i!=tail;i=nxt[i])
		if(i) printf("%c",s[i]);
	return 0;
}
