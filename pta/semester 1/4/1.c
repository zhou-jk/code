int fib(int n)
{
    int a = 1, b = 1;
    for (int i = 3; i <= n; i++)
    {
        int c = a + b;
        a = b, b = c;
    }
    return b;
}