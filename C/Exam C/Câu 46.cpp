#include <stdio.h>
	
//Tinh tong so am, so duong
int tong(int a[], int n){
	int td = 0, ta = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			td += a[i];
		}
		else{
			ta += a[i];
		}
	}
	printf("Tong duong = %d\nTong am = %d\n", td, ta);
}


//Chia het 6, tan cung = 2
int check(int a[], int n){
	printf("So chia het cho 6, tan cung la 2 la: ");
	for(int i = 0; i < n; i++){
		if(a[i] % 6 == 0 && a[i] % 10 == 2){
			printf("%d ", a[i]);
		}
	}
}

int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	tong(a,n);
	check(a,n);
	return 0;
}
