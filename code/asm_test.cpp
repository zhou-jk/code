#include <cstdio>
using namespace std;
const unsigned int P = 3;
int main() {
    unsigned a;
    scanf("%u", &a);
    unsigned int b = a % P;
    printf("%u", b);
}