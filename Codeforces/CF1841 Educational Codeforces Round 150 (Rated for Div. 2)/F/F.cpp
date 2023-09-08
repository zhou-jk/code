#include<iostream>
#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
class Fast_char
{
private:
    static const int SIZE=1<<21;
    char fr[SIZE],*pr1=fr,*pr2=fr;
    char fw[SIZE];
    int pw;
public:
    char getc()
    {
        return (pr1==pr2&&(pr2=(pr1=fr)+fread(fr,1,SIZE,stdin),pr1==pr2)?EOF:*pr1++);
    }
    void putc(char ch)
    {
        (pw<SIZE?fw[pw++]=(ch):(fwrite(fw,1,SIZE,stdout),fw[(pw=0)++]=(ch)));
        return;
    }
    ~Fast_char()
    {
        fwrite(fw,1,pw,stdout);
        return;
    }
}fast_char;
#define getchar fast_char.getc
#define putchar fast_char.putc
template<typename T>
inline T read(T &x)
{
    char ch;
    bool flag=false;
    x=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
        if(ch=='-') flag=true;
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(flag) x=-x;
    return x;
}
template<typename T>
void write(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
template<typename T>
void writeln(T x)
{
    write(x),putchar('\n');
    return;
}
char* getstring(char *s)
{
    char ch;
    char *t=s;
    for(ch=getchar();ch!='\n'&&ch!=EOF;ch=getchar()) *t=ch,t++;
    *t='\0';
    return s;
}
int putstring(char *s)
{
    int len=0;
    for(char *t=s;*t!='\0';t++)
        putchar(*t),len++;
    putchar('\n');
    return len;
}
#define gets getstring
#define puts putstring
const int N=300005;
int n;
struct Point
{
    int x,y;
    int quadrant()const
    {
        if(x>0&&y>=0) return 1;
        else if(x<=0&&y>0) return 2;
        else if(x<0&&y<=0) return 3;
        else if(x>=0&&y<0) return 4;
        else return 0;
    }
    friend long long cross(const Point &a,const Point &b)
    {
        return (long long)a.x*b.y-(long long)a.y*b.x;
    }
}p[N+N];
bool cmp(const Point &a,const Point &b)
{
    int x=a.quadrant(),y=b.quadrant();
    if(x!=y) return x<y;
    else return cross(a,b)>0;
}
int main()
{
    read(n);
    long long sx=0,sy=0;
    for(int i=1;i<=n;i++)
    {
        int a,b,c,d;
        read(a),read(b),read(c),read(d);
        int x=a-b,y=c-d;
        p[i]={x,y};
        p[i+n]={-x,-y};
        if(y<0||(y==0&&x<0)) sx+=x,sy+=y;
    }
    sort(p+1,p+n+n+1,cmp);
    __int128 ans=(__int128)sx*sx+(__int128)sy*sy;
    for(int i=1;i<=n+n;i++)
    {
        sx+=p[i].x,sy+=p[i].y;
        ans=max(ans,(__int128)sx*sx+(__int128)sy*sy);
    }
    write(ans);
    return 0;
}