//AC
#include <cstdio>

int main()
{
    int n,tot=0;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        int a;
        scanf("%d",&a);
        tot^=a;
    }
    puts(tot?"win":"lose");
    return 0;
}