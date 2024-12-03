#include <stdio.h>
#include <math.h>
int main(){
	float x, n;
	printf("Nhap x, n lan luot la: ");
	scanf("%f%f", &x, &n);
	double T = 100, S = 100, P = 90;
	
	
	//Cau a:
	for(int i = 1; i <= n; i++){
			T += pow(-1, i + 1) * x / (10 * i);
	}
	printf("%.2lf\n", T);
	
	
	//Cau b:
	for(int i = 2; i <= n; i++){
			S += pow(-1, i + 1) * 10 * i;
	}
	printf("%.2lf\n", S);
	
	//Cau c:
	for(int i = 1; i <= n; i++){
			P += pow(-1, i + 1) * 10 * i;
	}
	printf("%.2lf\n", P);
}
