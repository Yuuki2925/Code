//Liet ke cac gtri khac nhau
#include <stdio.h>
int main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n ; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		int check = 1;
		for(int j = 0; j < i; j++){
			if(a[i] == a[j]){
				check = 0;
				break;
			}
		}
		if(check == 1){
			printf("%d ", a[i]);
		}
	}
	return 0;
}
