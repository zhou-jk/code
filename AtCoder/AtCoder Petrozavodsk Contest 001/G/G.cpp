#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=100005;
int n;
char s[N*4];
int c[N*2];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    s[0]=s[2*n]='1';
    vector<int>a;
    for(int i=1;i<=n*2;i++)
        if(s[i-1]=='1'&&s[i]=='1') a.emplace_back(i);
    int cnta=a.size();
    if(cnta%2!=0)
    {
        printf("No");
        return 0;
    }
    if(cnta%4==0)
    {
        int tot=0;
        for(int i=0;i<cnta;i+=4)
        {
            c[a[i]]=c[a[i+2]]=++tot;
            c[a[i+1]]=c[a[i+3]]=++tot;
        }
        int pree=0,pres=0;
        for(int i=1;i<=n*2;i++)
            if(!c[i])
            {
                if(s[i-1]=='1'&&s[i]=='0')
                {
                    if(pres) c[pres]=c[i]=++tot,pres=0;
                    else pree=i;
                }
                else if(s[i-1]=='0'&&s[i]=='1')
                {
                    if(pree) c[pree]=c[i]=++tot,pree=0;
                    else pres=i;
                }
            }
        int prec=0;
        for(int i=1;i<=n*2;i++)
            if(!c[i])
            {
                if(prec) c[prec]=c[i]=++tot,prec=0;
                else prec=i;
            }
    }
    else
    {
        for(int i=1;i<=n*2;i++)
            s[n*2+i]=s[i];
        int tot=0;
        int pos1=-1,pos2=-1;
        a.clear();
        for(int i=0,j=0;i<=n*2;i=j)
        {
            while(j<=n*4&&s[j]=='1') j++;
            if(i!=0&&j-i>=2)
            {
                if(pos1==-1) pos1=i+1;
                else if(pos2==-1)
                {
                    pos2=i+1;
                    if(pos2>n*2) pos2-=n*2;
                    c[i]=++tot;
                    if(j>n*2) c[j-n*2]=c[i];
                    else c[j]=c[i];
                    c[pos1]=c[pos2]=++tot;
                    for(int k=i+1;k<j;k++)
                    {
                        int pos=k;
                        if(pos>n*2) pos-=n*2;
                        if(!c[pos]&&s[pos-1]=='1'&&s[pos]=='1') a.emplace_back(pos);
                    }
                    for(int k=pos1+1;k<=n*4;k++)
                        if(s[k]=='1')
                        {
                            int pos=k;
                            if(pos>n*2) pos-=n*2;
                            if(!c[pos]&&s[pos-1]=='1'&&s[pos]=='1') a.emplace_back(pos);
                        }
                        else break;
                }
                else
                {
                    for(int k=i+1;k<j;k++)
                    {
                        int pos=k;
                        if(pos>n*2) pos-=n*2;
                        if(!c[pos]&&s[pos-1]=='1'&&s[pos]=='1') a.emplace_back(pos);
                    }
                }
            }
            while(j<=n*2&&s[j]=='0') j++;
        }
        cnta=a.size();
        if(pos2==-1)
        {
            printf("No");
            return 0;
        }
        for(int i=0;i<cnta;i+=4)
        {
            c[a[i]]=c[a[i+2]]=++tot;
            c[a[i+1]]=c[a[i+3]]=++tot;
        }
        int pree=0,pres=0;
        for(int i=1;i<=n*2;i++)
            if(!c[i])
            {
                if(s[i-1]=='1'&&s[i]=='0')
                {
                    if(pres) c[pres]=c[i]=++tot,pres=0;
                    else pree=i;
                }
                else if(s[i-1]=='0'&&s[i]=='1')
                {
                    if(pree) c[pree]=c[i]=++tot,pree=0;
                    else pres=i;
                }
            }
        int prec=0;
        for(int i=1;i<=n*2;i++)
            if(!c[i])
            {
                if(prec) c[prec]=c[i]=++tot,prec=0;
                else prec=i;
            }
    }
    printf("Yes\n");
    for(int i=1;i<=n*2;i++)
        printf("%d ",c[i]);
    return 0;
}