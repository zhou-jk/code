void CharPyramid(int n, char ch)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("%c ", ch);
        printf("\n");
    }
    return;
}