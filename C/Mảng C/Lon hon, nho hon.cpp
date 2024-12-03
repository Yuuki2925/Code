//Lon hon, nho hon
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int x;
	scanf("%d", &x);
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > x){
			++cnt1;
		}
		else if(a[i] < x){
			++cnt2;
		}
	}
	printf("Co %d so nho hon %d\n", cnt2, x);
	printf("Co %d so lon hon %d", cnt1, x);
	return 0;
}
