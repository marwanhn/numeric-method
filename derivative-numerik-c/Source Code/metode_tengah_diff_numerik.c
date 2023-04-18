/*
differensial selisih TENGAH
*/
#include"stdio.h"
#include"math.h"
double a,b,x,ft,fek,fx,error,sigma=0,total_error,h;
int i=0;

double f(double x)
{
	return(x*x+2*x+1);
}

double f_eksak(double x,double h)
{
	return(-(f(x+3*h)-f(x+2*h)-2*f(x+h)+2*f(x)+f(x-h)-f(x-2*h))/(24*h*h));	
}

double fungsi_tengah(double x,double h)
{
	return((f(x+h)-f(x-h))/(2*h));	
}


void tengah()
{
	printf("masukan batas atas=");
	scanf("%lf",&b);
	printf("masukan batas bawah=");
	scanf("%lf",&a);
	printf("masukan nilai step h= ");
	scanf("%lf",&h);
	
		puts("==========================================================================");
	printf("%s\t %8s\t %8s\t %8s\t %8s\n\n","x","f(x)","f'(x)","eksak","error");
		puts("==========================================================================");
	for(x=a;x<=b;x+=h)
	{	i++;
		fx=f(x);
		ft=fungsi_tengah(x,h);
		fek=f_eksak(x,h);
		error=fabs(fek-ft);//mencari error
		printf(" %g \t %8lf \t %8lf \t %8lf \t %8lf\n",x,fx,ft,fek,error);
		sigma=sigma+error;
			
	}
	total_error=sigma/i;//rata-rata error
	printf("\nRata-rata error = %lf\n",total_error);	
}

main()
{	puts("\t====================");
	puts("\t    DIFFERENSIAL");
	puts("\tMetode selisih tengah");
	puts("\t====================\n\n");
	tengah();
}
