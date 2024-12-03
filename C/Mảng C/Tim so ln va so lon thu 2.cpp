//Tim so lon nhat va so lon thu 2
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int max1 = -1e9, max2 = -1e9;
	for(int i = 0; i < n ; i++){
		if(max1 < a[i]){
			max2 = max1;
			max1 = a[i];
		}
		else if(max2 < a[i]){
			max2 = a[i];
		}
	}
	printf("%d\n%d", max1, max2);
	return 0;
}
