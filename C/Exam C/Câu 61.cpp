//Cau 61
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct sv{
	char ten[100];
	int ns;
	double dtb;
};
typedef struct sv sv;

//In thong tin
void in(sv a){
	printf("%s %d %.2lf\n", a.ten, a.ns, a.dtb);
}

//Sap xep theo dtb
int cmp(const void *a, const void *b){
	sv *x = (sv*)a;
	sv *y = (sv*)b;
	if( x->dtb > y->dtb ){
		return -1;
	} 
	else{
		return 1;
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
		printf("Nhap ten: ");
		gets(a[i].ten);
		printf("Nhap nam sinh: ");
		scanf("%d", &a[i].ns);
		printf("Nhap diem trung binh: ");
		scanf("%lf", &a[i].dtb);
	}
	printf("\nSinh vien xep loai kha la:\n");
	for(int i = 0; i < n; i++){
		if(a[i].dtb >= 7 && a[i].dtb < 8){
			in(a[i]);
		}
	}
	printf("\nSinh vien tu 20 tuoi tro xuong la:\n");
	for(int i = 0; i < n; i++){
		int tuoi = 2015 - a[i].ns;
		if(tuoi <= 20){
			in(a[i]);
		}
	}
	printf("\nSap xep sinh vien theo DTB giam dan la:\n");
	qsort(a, n, sizeof(sv), cmp);
	for(int i = 0; i < n; i++){
		in(a[i]);
	}
	return 0;
}
