#include <stdio.h>
#define MAX 30

float x[MAX], y[MAX];

void linier(){
	y[0] = ((y[2] - y[1]) / (x[2] - x[1]) * (x[0] - x[1])) + y[1];
}

void kuadratik(){
	y[0] = y[1]*(((x[0] - x[2])*(x[0] - x[3])) / ((x[1] - x[2])*(x[1] - x[3]))) + y[2]*(((x[0] - x[1])*(x[0] - x[3])) / ((x[2] - x[1])*(x[2] - x[3]))) + y[3]*(((x[0] - x[1])*(x[0] - x[2])) / ((x[3] - x[1])*(x[3] - x[2])));
}

void main(){
	int i, n=0, met;
	printf("Metode\n");
	printf("1. Interpolasi Linier\n");
	printf("2. Interpolasi Kuadratik\n");
	printf("3. ....\n");
	printf("Pilih : ");
	scanf("%d", &met);
	if (met == 1)
		n = 2;
	else if (met == 2)
		n = 3;
	for (i = 1; i <= n; i++){
		printf("Inputkan (x%d, y%d)  : ", i, i);
		scanf("%f, %f", &x[i], &y[i]);
	}
	printf("Inputkan (x) baru : ");
	scanf("%f", &x);
	switch (met){
	case 1:
		linier();
		break;
	case 2:
		kuadratik();
		break;
	default:
		printf("\nInput salah!\n");
		break;
	}
	printf("\nNilai titik baru (%g, %g)\n", x[0], y[0]);
}