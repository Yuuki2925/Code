//QLSV bang Menu lua chon
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct Sinhvien{
	char ten[20];
	char lop[20];
	float gpa;
};

//Nhap danh sach sinh vien
void nhap(Sinhvien *x){
	getchar();
	printf("Nhap ten: ");
	gets(x->ten);
	printf("Nhap lop: ");
	gets(x->lop);
	printf("Nhap gpa: ");
	scanf("%f", &x->gpa);
}

//In danh sach sinh vien
void in(Sinhvien x){
	printf("%s %s %.2f\n", x.ten, x.lop, x.gpa);
}

//Tim thong tin SV
void timkiem(Sinhvien sv[], int n, char name[]){
	int find = 0;
	for(int i = 0; i < n; i++) {
        if(strcmp(name, sv[i].ten) == 0) {
            in(sv[i]);
            find = 1; // Tìm thay
        }
    }
    if(!find)
        printf("Khong tim thay sinh vien co ten %s\n", name);
}

//In ra sv co GPA cao nhat
void maxGPA(Sinhvien sv[], int n){
	float max = 0;
	for(int i = 0; i < n; i++){
		max = fmax(max, sv[i].gpa);
	}
	printf("Sinh vien co diem GPA cao nhat\n");
	for(int i = 0; i < n; i++){
		if(max == sv[i].gpa){
			in(sv[i]);
		}
	}
}

//Xoa sv theo ten
void xoa(Sinhvien sv[], int *n, char name[]){
	for(int i = 0; i < *n ; i++){
		if(strcmp(name, sv[i].ten) == 0){
			for(int j = i; j < *n - 1; j++){
				sv[j] = sv[j + 1];
			}
			(*n)--;
			break;   // Xoa 1 sinh vien, neu muon xoa tat ca thi bo break
		}
	}
}

//Sap xep theo gpa giam dan
int compar(const void *a, const void *b){
	Sinhvien *x = (Sinhvien*)a;
	Sinhvien *y = (Sinhvien*)b;
	if(y->gpa > x->gpa){
		return 1;
	}
	else{
		return -1;
	}
}

int main(){
	Sinhvien sv[1000];
	int n;
	while(1){
		printf("-------------------------MENU-------------------------\n\n");
		printf("1. Nhap danh sach sinh vien\n");
		printf("2. In danh sach sinh vien\n");
		printf("3. Tim thong tin sinh vien theo ten\n");
		printf("4. Liet ke thong tin sinh vien co diem cao nhat\n");
		printf("5. Xoa thong tin sinh vien theo ten\n");
		printf("6. Sap xem sinh vien theo GPA giam dan\n");
		printf("7. Thoat khoi MENU\n");
		printf("------------------------------------------------------\n\n");
		
		printf("Nhap lua chon: ");
		int lc;
		scanf("%d", &lc);
		if(lc == 1){
			printf("Nhap so luong sinh vien: ");
			scanf("%d", &n);
			for(int i = 0; i < n; i++){
				printf("Sinh vien thu: %d\n", i + 1);
				nhap(&sv[i]);
			}
		}
		else if(lc == 2){
			printf("Danh sach sinh vien gom: \n");
			for(int i = 0; i < n; i++){
				in(sv[i]);
			}
		}
		else if(lc == 3){
			char name[100];
			getchar();
			printf("Nhap ten sinh vien can tim: ");
			gets(name);
			timkiem(sv, n, name);
		}
		else if(lc == 4){
			maxGPA(sv, n);
		}
		else if(lc == 5){
			char name[100];
			getchar();
			printf("Nhap ten sinh vien can xoa: ");
			gets(name);
			xoa(sv, &n, name);
		}
		else if(lc == 6){
			qsort(sv, n, sizeof(Sinhvien), compar);
		}
		else if(lc == 7){
			break;
		}
	}
	return 0;
}
