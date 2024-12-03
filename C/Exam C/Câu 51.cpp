//Cau 51
#include <stdio.h>
#include <math.h>
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n][m];
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("a[%d][%d] = ", i , j);
			scanf("%d", &a[i][j]);
		}
	}
	
	//Tong phan tu co chu so tan cung bang 6
	int sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] % 10 == 6){
				sum += a[i][j];
			}
		}
	}
	printf("Tong phan tu co chu so tan cung bang 6 la: %d\n", sum);
	
	//Tim phan tu lon nhat trong mang
	int max = -1e9;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] > max){
				max = a[i][j];
			}
		}
	}
	printf("Phan tu lon nhat trong mang la: %d\n", max);
//Dem so phan tu chan chia het cho 3
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] % 2 == 0 && a[i][j] % 3 == 0){
				cnt++;
			}
		}
	}
	printf("So phan tu chan chia het cho ba la: %d\n", cnt);
	
	//Tinh tong cac phan tu o hang 2
	int sum2 = 0;
	for(int j = 0; j < m; j++){
		sum2 += a[1][j];
	}
	printf("Tong cac phan tu o hang 2 la: %d\n", sum2);
	
	//Trung binh cong phan tu tren cot 2
	int sum3 = 0, cnt2 = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			sum3 += a[i][1];
			cnt2++;
		}
	}
	float tbc = (float)sum3 / cnt2;
	printf("TBC phan tu tren cot 2 la: %.2f\n", tbc);
	
	//Tinh tong cac phan tu tren duong cheo chinh
	int sum4 = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0;j < m; j++){
			if(i == j){
				sum4 += a[i][j];
			}
		}
	}
	printf("Tong ptu tren duong cheo chinh la: %d\n", sum4);
	
	//Tinh tong cac phan tu tren duong cheo phu
	int sum5 = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0;j < m; j++){
			if(n - 1 == i + j){
				sum5 += a[i][j];
			}
		}
	}
	printf("Tong ptu tren duong cheo phu la: %d\n", sum5);
	return 0;
}
