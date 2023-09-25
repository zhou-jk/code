double fact(int n)
{
    double sum = 1;
    for (int i = 1; i <= n; i++)
        sum *= i;
    return sum;
}