#include<stdio.h>
int main()
{
    double nota1,count=0,s=0;
    while(count!=2)
    {
        scanf("%lf",&nota1);
     if(nota1>=0 &&nota1<=10)
    {
        s=s+nota1;
        count=count+1;
    }
    else
    {
        printf("nota invalida\n");
    }
    }
    printf("media = %.2lf\n",s/2);

    return 0;
}
