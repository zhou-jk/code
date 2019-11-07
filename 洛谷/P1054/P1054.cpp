#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MOD=1000000007;
const int pre[5]={5,7,11,2,3};
int n;
long long last[15],now[15];
int book[100];
char C[60];
void init()
{
    for(int i='0';i<='9';i++)
        book[i]=1;
    book[int('(')]=2;
    book[int('+')]=3;
    book[int('-')]=3;
    book[int('*')]=4;
    book[int('^')]=5;
    book[int(')')]=6;
    book[int('a')]=7;
    return;
}
int cnt;
void read()
{
    char ch=getchar();
    while(!book[ch])
        ch=getchar();
    cnt=-1;
    while(ch!='\r'&&ch!='\n')
    {
        if(book[ch]) C[++cnt]=ch;
        ch=getchar();
    }
    return;
}
struct Node
{
    int k;
    long long c;
};
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
stack<Node> s1,s2;
bool get(char *now,int cnt,int flag)
{
    while(!s1.empty()) s1.pop();
    while(!s2.empty()) s2.pop();
    for(int k=0;k<=4;k++)
    {
        for(int i=0;i<=cnt;i++)
        {
            long long x=0;
            char c=now[i];
            if(book[c]==1)
            {
                while(book[c]==1&&i<=cnt) {x=x*10+c-'0';i++;c=*(now+i);}
                s1.push((Node){0,x});
                i--;
            }
            else if(book[c]==7) s1.push((Node){0,pre[k]});
            else if(book[c]==6)
            {
                while(!s2.empty())
                {
                    if(s2.top().k&&book[s2.top().c]==2) break;
                    s1.push(s2.top()),s2.pop();
                }
                if(s2.empty()) return false;
                else s2.pop();
            }
            else
            {
                Node u;
                u.k=1,u.c=c;
                while(!s2.empty()&&book[s2.top().c]>=book[c]&&s2.top().c!='('&&c!='(')
                    s1.push(s2.top()),s2.pop();
                s2.push(u);
            }
        }
        while(!s2.empty())
        {
            if(book[s2.top().c]==2) return false;
            s1.push(s2.top());
            s2.pop();
        }
        while(!s1.empty())
            s2.push(s1.top()),s1.pop();
        while(!s2.empty())
        {
            Node u=s2.top();
            s2.pop();
            if(u.k)
            {
                long long t1=s1.top().c;
                s1.pop();
                long long t2=s1.top().c;
                s1.pop();
                long long t3;
                if(char(u.c)=='+') t3=t1+t2;
                else if(char(u.c)=='-') t3=t2-t1;
                else if(book[u.c]==4) t3=t2*t1%MOD;
                else if(book[u.c]==5) t3=ksm(t2,t1);
                s1.push((Node){0,t3});
            }
            else s1.push(u);
        }
        int tmp=s1.top().c%MOD;
        if(flag) last[k]=s1.top().c%MOD;
        else if(last[k]!=tmp) return false;
        s1.pop();
    }
    return true;
}
int main()
{
    init();
    read();
    get(C,cnt,1);
    char ch;
    for(ch=getchar();!book[ch];ch=getchar());
    while(ch!='\r'&&ch!='\n')
        n=(n<<1)+(n<<3)+(ch^48),ch=getchar();
    for(int i=1;i<=n;i++)
    {
        read();
        if(get(C,cnt,0))
            printf("%c",char(i+'A'-1));
    }
    return 0;
}