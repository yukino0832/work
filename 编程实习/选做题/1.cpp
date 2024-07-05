#include <stdio.h>
int main()
{
    double R1,R2;
    printf("请输入两个电阻阻值：");
    scanf("%lf %lf",&R1,&R2);
    if(R1 == 0 || R2 == 0)
    {
        printf("输入有误!");
    }
    else
    {
        printf("串联:%.2lf ", R1 + R2);
        printf("并联:%.2lf\n", (R1 * R2) / (R1 + R2));
    }
    return 0;
}
