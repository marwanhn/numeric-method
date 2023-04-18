#include<stdio.h>
#include<math.h>

// persamaan
double f(double x) {
return(x*x-x-2);
}


void main() {
double y[100],a,b,e,y1,y2,xr,y3;
int n,i=0;
printf("\t\tMetode Regula falsi\t\t\n");
printf("masukkan batas atas=");
scanf("%lf",&a);
printf("masukkan batas bawah=");
scanf("%lf",&b);
printf("masukkan toleransi error=");
scanf("%lf",&e);
printf("masukkan iterasi maksimum=");
scanf("%d",&n);
y1=f(a);
y2=f(b);
if(y1*y2>0)
printf("tidak ditemukan akar\n\n");
else {
i<=n;
printf("iterasi\t a\t b\t xr\t\t f(a)\t f(b)\t f(x)|\n");
printf("=========================================================\n");

while (i<=n)
{
xr=((y2*a)-(y1*b))/(y2-y1);
y[i]=f(xr);
y3=f(xr);
printf("|%3d|%.7lf|%.7lf|%.7lf|%.7lf|%.7lf|%.7lf|\n",i+1, a, b, xr, y1,y2,f(xr));

if(y[i]*y1<0)
{ b=xr;
y2 = f(xr);

}
else
{ a=xr;
y1 = f(xr);
}
i++;
if(fabs(b-a)<=e || i>(n-1))
break;
}

printf("=========================================================\n");
printf("Akar persamaan adalah %lf\n",xr);
if (f(xr)<0)
{
y3=(fabs(y2*-1));
printf("Nilai error = %.7f\n",y3);
}
else
printf("Nilai error = %.7f\n",y3);
}
}
