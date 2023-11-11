#include<iostream>
#include<cstdio>
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
    void flush()
    {
        fwrite(fw,1,pw,stdout);
        fflush(stdout);
        pw=0;
        return;
    }
    ~Fast_char()
    {
        flush();
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
        x=x*10+ch-'0',ch=getchar();
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
