//Chen 1
#include <stdio.h>
int main(){
	int n, k ,x;
	scanf("%d%d%d", &n, &x, &k);
	int a[n + 1];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	k--;
	for(int i = n; i > k; i--){
		a[i] = a[i - 1];
	}
	a[k] = x;
	n++;
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
