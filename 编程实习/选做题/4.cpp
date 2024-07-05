#include <stdio.h>

int main()
{
    int start = 2000, end = 3000;
    int count = 0;
    printf("闰年为:\n");
    for (int i = start; i < end; i += 4)
    {
        if(i % 100 != 0 || i % 400 == 0)
        {
            printf("%d ", i);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
    }
    printf("\n共%d年\n", count);
    return 0;
}
