//Dem chan le, tong chan le
#include <stdio.h>
#include <math.h>
int tongdem(int a[], int n){
	int chan = 0, le = 0;
	int tc = 0, tl = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0){
			tc += a[i];
			chan++;
		}
		else{
			tl += a[i];
			le++;
		}
	}
	printf("Tong chan = %d\nSo chan = %d\n", tc, chan);
	printf("Tong le = %d\nSo le = %d", tl, le);
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	tongdem(a,n);
	return 0;
}
