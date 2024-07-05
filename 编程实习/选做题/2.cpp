#include <stdio.h>
void exchange(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    exchange(a, b);
    printf("a=%d b=%d\n", a, b);
    return 0;
}
