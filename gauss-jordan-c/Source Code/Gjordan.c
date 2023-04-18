/*
Kelompok 4 Metode Numerik
*/

#include <stdio.h>

//deklarasi variabel
#define size 10
int i,j,k;

//fungsi print matriks
void printMatrix(double A[size][size], int ordo){
	for(i =0; i <ordo; i++)
	{
		printf(" | ");
		for (j = 0; j< ordo; j++)
		{
			printf("%.3lf ", A[i][j]);
			
			//menuliskan vektor matriks B
			if(j==ordo-1){
				printf("\t| %.3lf", A[i][j+1]);
			}
		}
		printf("|\n");
	}
}


//fungsi operasi gauss jordan
void gaussJordan(double A[size][size], int n){
	double pembagi, B[size];
	
	printf("\n[Matriks A | B]\n");
	printMatrix(A, n);
	
	//perulangan keseluruhan matriks
	for(i = 0; i < n; i++)
	{
		//Elemen nilai tengah/diagonal sebagai pembagi (a11,a22,a33)
		pembagi = A[i][i];
		
		//perulangan tiap-tiap baris pada matriks
		for(k = 0; k<n+1;k++)
		{
			A[i][k] /= pembagi;
		}
		
		//perulangan tiap-tiap kolom pada matriks
		//cek secara vertikal agar array selain x[i][i] bernilai 0
		for (j=i+1; j<n+1; j++){
			B[i] = A[j][i];
			
			//perulangan tiap-tiap baris pada matriks kolom yg sama
			for (k = i; k<n+1;k++){
				A[j][k] = A[j][k] - B[i] * A[i][k];
			}
		}
	}
	
	for (i=1; i<n; i++){
		for(j = 1; j < i + 1; j++){
			B[j] = A[j-1][i];
			for(k=0; k<n+1; k++){
				A[j-1][k] -= B[j] * A[i][k];
			}
		}
	}
	printf("\n\t[Matriks Identitas]\n");
	printMatrix(A,n);

}



int main(){
	double A[size][size];
	int n;
	
	//menentukan ordo matriks yang diinginkan user
	do{
	printf("\nTentukan Ordo Matriks : ");
	scanf("%d", &n);
		//validasi ordo < 2
		if (n < 2)
		{
			printf("Input ordo minimal 2x2");
		}
	}while(n<2);
	
	printf("\n[Matriks Ordo %dx%d]\n", n,n);
	
	//Input Tiap Elemen Matriks
	for (i=0; i< n; i++) //perulangan tiap baris matrik
	{
		printf("Matriks baris ke-%d\n", (i+1));
		
		//perulangan tiap item matriks pada barisnya
		for(j=0; j < n; j++)
		{
			printf("a%d%d: ", (i+1),(j+1));
			scanf("%lf", &A[i][j]);
		
			//Vektor B disimpan ke dalam array dimensi kedua indeks terakhir
			//jika telah sampai pada ujung baris (ordo - 1), input vektor B ke array A[i][j+1]
			if (j==n-1)
			{
				printf("b%d: ", (i+1));
				scanf("%lf", &A[i][j+1]);
			}
		}
		printf("\n");
	}
	//Memanggil Fungsi gaussJordan
	gaussJordan(A, n);
	
	//Menampilkan nilai x1,x2,x3
	for (i=0; i<n; i++){
		printf("\nx%d = %.3lf", (i+1), A[i][n]);
	}
	return 0;
}
