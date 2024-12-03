//Mang doi xung
#include <stdio.h>
int check(int a[], int n){
	int l = 0, r = n - 1;
	while(l <= r){
		if(a[l] != a[r]){
			return 0;
		}
		++l;
		--r;
	}
	return 1;
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
	if(check(a,n)){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
