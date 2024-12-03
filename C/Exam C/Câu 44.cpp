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
	
	//In ra so lon nhat
	int max = a[0];
	for(int i = 0; i < n; i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	printf("So lon nhat la: %d\n", max);
	
	
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
	
	
	//TBC cac so am
	int sum = 0, cnt =0;
    for (int i = 0; i < n ; i++){
       if(a[i] < 0){
       		++cnt;
       		sum += a[i];
	   }
	}
	float res = (float)sum / cnt;
	printf("TBC so am = %.2f", res);
	return 0;
}

