//Viet chuong tr�nh nhap a, b. Giai v� bien luan phuong tr�nh ax+b=0. In ket qua l�n m�n h�nh
#include <stdio.h>
#include <math.h>
int main(){
	int a, b;
	printf("Nhap a, b lan luot la: ");
	scanf("%d%d", &a, &b);
	float x = (float)-b / a;
	if(a == 0){
		if(b == 0){
			printf("Phuong trinh vo so nghiem");
		}
		else{
			printf("Phuong trinh vo nghiem");
		}
	}
	else{
		printf("Phuong trinh co 1 nghiem la x = %.2f", x);
	}
	return 0;
}
