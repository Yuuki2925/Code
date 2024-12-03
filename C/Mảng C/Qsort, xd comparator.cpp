//Qsort va xay dung comparator
#include <stdio.h>
#include <stdlib.h>
//void qsort( array, so_luong_phan_tu, kich_thuoc, int (*comp)(const void* , const void* ))

//Sap xep tang dan
// 1 : neu a va b dung thu tu mong muon
// -1 : neu a va b khong dung thu tu mong muon

int comp(const void *a, const void *b){
	
	//Ep 2 con tro void sang 2 con tro int
	
	int *x = (int *)a;    // *x la con tro
	int *y = (int *)b;    // *y la con tro
	if(*x < *y){          // *x la vi tri con tro x tro den, *y la vi tri con tro y tro den: *x, *y la giai tham chieu
		return -1;
	}
	else{
		return 1;
	}
	
	// co the thay if else = return *x - *y
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), comp);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}

