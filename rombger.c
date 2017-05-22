/*************************************************************************
	> File Name: rombger.c
	> Author:KID_XiaoYuan 
	> Mail:kuailexy@126.com
	> Created Time: 2017年05月22日 星期一 21时18分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double ROMBGER(double a, double b, double eps,double al,double ma,double mi);
double Func(double);

int main()
{
    double a,b,eps,al,ma,mi;
    scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&eps,&al,&ma,&mi);
    printf("%.10lf\n",ROMBGER(a,b,eps,al,ma,mi));
    
    return 0;
}

double ROMBGER(double a, double b, double eps,double al,double ma,double mi)
{
    double l,h,r,s,k,l0,m,n;
    int j,q;
    double *t;

    t = (double*)calloc(11,sizeof(double));

    if(t == NULL)
    exit(1);
    l = b - a;
    h = l ;
    t[0] = (Func(a) + Func(b)) * l * 0.5;
    for(q = 0; q <= ma-1; q++)
    {
        r = h;
        h *= 0.5;
        k = h;
         s = Func(a+k);
        do
        {
            k += r;
            if(fabs(k) < fabs(l))
            {
                s += Func(a+k);
            }
        }while(fabs(k) < fabs(l));

        t[q+1] = t[q] * 0.5 + h * s;
        l0 = 1;
        for(j=q;j >= 0; j--)
        {
            l0 *= 0.25;
            m = (t[j+1] - t[j])/(1-l0);
            t[j] += m;
        }
        n = t[0];

        if(fabs(n) >= al)
        {
            m /= n;
        }
        if(fabs(m) < eps && q > mi)
        {
            r = t[0];
            free(t);
            return(r);
        }
    }

    free(t);
    return(r);
}

double Func(double x)
{
    return (exp(x) * x *x);
}
