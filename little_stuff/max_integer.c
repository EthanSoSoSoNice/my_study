#include <stdio.h>
#include <stdlib.h>

#define LLONG_MAX   9223372036854775807
#define LLONG_MIN   (-9223372036854775807 - 1)

int main(void)
{
    // printf("%lu", LLONG_MAX);
    char i;
    unsigned long long n = 0;
    // 读取符号位
    char neg = getchar();
    if (neg == '-') 
        neg = 1;
    else if (neg == '+')
        neg = 0;
    else
        exit(2);

    while((i = getchar()) != '\n')
    {
        char i2 = (i - '0');
        if ( i < '0' || i > '9') exit(2);
        if (n >= (LLONG_MAX / 10) && (n > (LLONG_MAX /10) || i2 > (LLONG_MAX % 10) + neg))// 负数能表示的10进制值比正数要大1
        {
            printf("n:%lu, i:%c", n, i);
            printf("overflow");
            return 0;
        }
        
        n = n * 10 + i2;
    }
    printf("%lu", n);

    return 0;
}