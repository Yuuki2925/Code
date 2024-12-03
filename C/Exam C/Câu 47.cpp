#include <stdio.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	
	//TBC cac so duong
	int sum = 0, cnt =0;
    for (int i = 0; i < n ; i++){
       if(a[i] > 0 && a[i] % 3 == 0){
       		++cnt;
       		sum += a[i];
	   }
	}
	float res = (float)sum / cnt;
	printf("TBC so duong = %.2f\n", res);
	
	//Tim phan tu nho nhat
	int min = a[0];
	for(int i = 0; i < n; i++){
		if(min > a[i]){
			min = a[i];
		}
	}
	printf("Phan tu nho nhat = %d\n", min);
	
	
	//Sap xep theo thu tu tang dan
	int tg;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]){
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}	
		}
	}
	printf("Thu tu tang dan la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	
	
	//Tong cac so khong am
	int td = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			td += a[i];
		}
	}
	printf("Tong duong = %d\n", td);
	
	
	//Dem so le
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 != 0){
			++dem;
		}
	}
	printf("Co %d so le", dem);
	return 0;
}

