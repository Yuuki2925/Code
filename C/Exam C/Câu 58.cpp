//Cau 58
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


//Xep loai sinh vien
void xeploai(sv a){
    printf("Ma SV: %s, Ho ten: %s, Tong diem: %.2f, Xep loai: ", a.msv, a.ten, a.td);
    if (a.td >= 8.0) {
        printf("Gioi\n");
    } else if (a.td >= 7.0) {
        printf("Kha\n");
    } else {
        printf("Khong dat\n");
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
	for(int i = 0; i < n; i++){
		xeploai(a[i]);
	}
	return 0;
}
