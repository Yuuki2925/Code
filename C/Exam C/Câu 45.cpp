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
	
	
	//In ra so nho nhat
	int min = a[0];
	for(int i = 0; i < n; i++){
		if(min > a[i]){
			min = a[i];
		}
	}
	printf("So nho nhat = %d\n", min);
	
	
	//Theo thu tu giam dan
	int tg;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] < a[j]){
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	printf("Thu tu giam dan la: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	
	
	//TBC cac so duong
	int sum = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			++cnt;
			sum += a[i];
		}
	}
	float res = (float)sum / cnt;
	printf("TBC = %.2f", res);
	return 0;
}

