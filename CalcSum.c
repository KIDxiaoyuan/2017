/*************************************************************************
	> File Name: CalcSum.c
	> Author:KID_XiaoYuan 
	> Mail:kuailexy@126.com
	> Created Time: 2017年05月23日 星期二 22时10分38秒
 ************************************************************************/

#include<stdio.h>

extern int CalcSum_ (int a,int b,int c)
{
    return a+b+c;
}
int main()
{
    int a =17, b = 11,c = 14;
    int sum = CalcSum_(a,b,c);
    printf("%d\n",sum);
    return 0;
}
