//Cau 56
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct sv{
	char msv[100];
	char ten[100];
	float td;
};

typedef struct sv sv;

//In thong tin sinh vien
void in(sv a){
	printf("%s %s %.2f\n", a.msv, a.ten, a.td);
}

void max(sv a[],int n){
	float max = 0;
	for(int i = 0; i < n; i++){
		max = fmax(max, a[i].td);
	}
	for(int i = 0; i < n; i++){
		if(max == a[i].td){
			in(a[i]);
		}
	}
}
int main(){
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	sv a[n];
	for(int i = 0; i < n; i++){
		getchar();
		printf("Sinh vien thu %d\n", i + 1);
		printf("Nhap ma sinh vien: ");
		gets(a[i].msv);
		printf("Nhap ho ten: ");
		gets(a[i].ten);
		printf("Nhap tong diem: ");
		scanf("%f", &a[i].td);
	}
	printf("\nSinh vien co tong diem cao nhat la:\n");
	max(a, n);
	printf("\nDanh sach sinh vien do la:\n");
	for(int i = 0; i < n; i++){
		if(a[i].td >= 17){
			in(a[i]);
		}
	}
	return 0;
}
