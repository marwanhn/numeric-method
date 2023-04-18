#include <stdio.h>
#include <math.h>

int main()
{
    float A[10][10], B[10], x[10], y[10], s[10], e[10], error;
    int n, iterasi, i, j, k = 1, c, o = 0;

  	//Menentukan ordo matriks
	do{
	    printf("\nTentukan Ordo Matriks: ");
    	scanf("%d",&n);
    		//validasi ordo<2
			if(n<2)
			{
				printf("Input ordo minimal 2x2");
			}
	}while(n<2);


    //Input nilai ruas di sebelah kiri matriks
    printf("\nInput tiap elemen dari ruas kiri matriks:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf(" A[%d][%d]=", i,j);
            scanf("%f",&A[i][j]);
        }
    }

    //Input nilai ruas di sebelah kanan matriks
    printf("\nInput tiap elemen dari ruas kanan matriks:\n");
    for(i=1; i<=n; i++)
    {
        printf(" B[%d]=",i);
        scanf("%f",&B[i]);
    }

    //Menampilkan inputan matriks dalam bentuk persamaan linear
	printf("\nTampilan Matriks Augmentasi dalam Bentuk Persamaan Linear:\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
		{
			printf("%f x%d",A[i][j],j);
			if(j != n)
            {
                printf(" + ");
            }
		}
		printf(" = %f\n",B[i]);
	}

	//Menentukan batas maksimal iterasi
	printf("\nBatas maksimum iterasi: ");
	scanf("%d",&iterasi);

	//Menentukan toleransi error
	printf("\nToleransi error: ");
	scanf("%f",&error);

	//Menentukan nilai awal dari xi
	printf("\nNilai awal x:\n");
	for(i=1; i<=n; i++)
    {
        printf("x%d = ",i);
        scanf("%f",&x[i]);
    }

    //Menampilkan nilai-nilai xi pada iterasi pertama
    printf("\n");
    for(i=1; i<=n; i++)
    {
        printf("x%d = %.4f\t",i,x[i]);
    }
    printf("\n");

    //Perhitungan nilai-nilai xi
    while(k<=iterasi && o==0)
    {
        c = 0;
        for(i=1; i<=n; i++)
        {
            s[i]=x[i];
            y[i]=B[i]/A[i][i];
            for(j=1; j<=n; j++)
            {
                if(i!=j)
                {
                    y[i]=y[i]-((A[i][j]/A[i][i])*x[j]);
                    x[i]=y[i];
                }
            }
            e[i]=fabs(x[i]-s[i]);
            printf("x%d = %.4f\t",i,y[i]);
        }
        for(i=1; i<=n; i++)
        {
            printf("error %d = %.4f   ",i,e[i]);
            if(e[i]<error)
            {
                c++;
                if(c==n && o==0)
                {
                    o = k;
                }
            }
        }
        printf("\n");
        k++;
    }
    if(o!=0)
    {
        printf("\nToleransi terpenuhi pada iterasi ke : %d\n",o);
        for(i=1; i<=n; i++)
        {
            printf("x%d = %f\t",i,x[i]);
        }
    }
    else
    {
        printf("\nToleransi tidak terpenuhi");
    }

    return 0;
}

