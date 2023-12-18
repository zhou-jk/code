#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char name[50][9];
    int sex[50];
    for (int i = 0; i < n; i++)
        scanf("%d%s", &sex[i], name[i]);
    int lastm = n - 1, lastf = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        while (lastm >= 0 && sex[lastm] != 1)
            lastm--;
        while (lastf >= 0 && sex[lastf] != 0)
            lastf--;
        if (sex[i] == 0)
            printf("%s %s\n", name[i], name[lastm]), lastm--;
        else
            printf("%s %s\n", name[i], name[lastf]), lastf--;
    }
    return 0;
}