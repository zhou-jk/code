#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=4000005;
int n,m,k;
int s[N],t[N];
set<int>pos;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%1d",&s[i]);
    reverse(s+1,s+n+1);
    for(int i=1;i<=m;i++)
        scanf("%1d",&t[i]);
    reverse(t+1,t+m+1);
    for(int i=max(n,m);i>=1;i--)
        if(s[i]==1&&t[i]==1)
        {
            pos.insert(i);
            int ret=k;
            set<int>::iterator it=pos.begin();
            while(it!=pos.end())
            {
                int j=*it;
                if(s[j]>=2||t[j]>=2)
                {
                    if(s[j]>=2) s[j+1]+=s[j]/2,s[j]%=2;
                    if(t[j]>=2) t[j+1]+=t[j]/2,t[j]%=2;
                    pos.insert(j+1);
                    if(s[j]==0&&t[j]==0)
                    {
                        set<int>::iterator p=it;
                        p++;
                        pos.erase(it);
                        it=p;
                    }
                    else if(s[j]==1&&t[j]==1)
                    {
                        if(ret==0) break;
                        set<int>::iterator p=it;
                        p++;
                        if(p!=pos.end())
                        {
                            int nxt=*p;
                            pos.erase(it);
                            it=p;
                            if(ret>nxt-j)
                            {
                                s[j]--,t[j]--;
                                s[nxt]++,t[nxt]++;
                                pos.insert(nxt);
                                ret-=nxt-j;
                                it=pos.find(nxt);
                            }
                            else
                            {
                                nxt=j+ret;
                                s[j]--,t[j]--;
                                s[nxt]++,t[nxt]++;
                                pos.insert(nxt);
                                ret=0;
                                it=pos.find(nxt);
                            }
                        }
                        else
                        {
                            pos.erase(it);
                            int nxt=j+ret;
                            s[j]--,t[j]--;
                            s[nxt]++,t[nxt]++;
                            pos.insert(nxt);
                            ret=0;
                            it=pos.find(nxt);
                        }
                    }
                    else it++;
                }
                else if(s[j]==1&&t[j]==1)
                {
                    if(ret==0) break;
                    set<int>::iterator p=it;
                    p++;
                    if(p!=pos.end())
                    {
                        int nxt=*p;
                        pos.erase(it);
                        it=p;
                        if(ret>nxt-j)
                        {
                            s[j]--,t[j]--;
                            s[nxt]++,t[nxt]++;
                            pos.insert(nxt);
                            ret-=nxt-j;
                            it=pos.find(nxt);
                        }
                        else
                        {
                            nxt=j+ret;
                            s[j]--,t[j]--;
                            s[nxt]++,t[nxt]++;
                            pos.insert(nxt);
                            ret=0;
                            it=pos.find(nxt);
                        }
                    }
                    else
                    {
                        pos.erase(it);
                        int nxt=j+ret;
                        s[j]--,t[j]--;
                        s[nxt]++,t[nxt]++;
                        pos.insert(nxt);
                        ret=0;
                        it=pos.find(nxt);
                    }
                }
                else break;
            }
        }
        else if(s[i]==1||t[i]==1) pos.insert(i);
    int lens=n+k;
    while(lens>1&&s[lens]==0) lens--;
    int lent=m+k;
    while(lent>1&&t[lent]==0) lent--;
    reverse(s+1,s+lens+1);
    reverse(t+1,t+lent+1);
    for(int i=1;i<=lens;i++)
        printf("%d",s[i]);
    printf("\n");
    for(int i=1;i<=lent;i++)
        printf("%d",t[i]);
    return 0;
}