//Vi tri so lon nhat nho nhat
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
	int max = -1e9, min = 1e9;
	int max_pos, min_pos;
	for(int i = 0; i < n; i++){
		if(max < a[i]){
        	max = a[i];
        	max_pos = i;
        }
        if(min >= a[i]){
        	min = a[i];
        	min_pos = i;
       	}
    }
    printf("Max_pos = %d\nMin_pos = %d", max_pos, min_pos);
    return 0;
}


//////Cach 2
//#include <stdio.h>
//#include <math.h>
//int main(){
//	int n;
//	printf("Nhap n = ");
//	scanf("%d", &n);
//	int a[n];
//	for(int i = 0; i < n; i++){
//		printf("a[%d] = ", i);
//		scanf("%d", &a[i]);
//	}
//	int max = -1e9, min = 1e9;
//	for(int i = 0; i < n; i++){
//		if(max < a[i]){
//			max = a[i];
//		}
//		if(min > a[i]){
//			min = a[i];
//		}
//	}
//	for(int i = n - 1; i >= 0; i--){
//		if(a[i] == min){
//			printf("Min_pos = %d\n", i);
//		}
//	}
//	for(int i = 0; i < n; i++){
//		if(a[i] == max){
//			printf("Max_pos = %d", i);
//		}
//	}
//	return 0;
//}
