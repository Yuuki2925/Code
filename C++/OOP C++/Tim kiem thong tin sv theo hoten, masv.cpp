#include <bits/stdc++.h>
using namespace std;
class Nguoi{
    private:
        string hoTen;
        int namSinh;
    public:
        Nguoi(){
            hoTen = "";
            namSinh = 0;
        }

        Nguoi(string hoTen, int namSinh){
            this->hoTen = hoTen;
            this->namSinh = namSinh;
        }

        string getHoTen() {
            return hoTen;
        }

        void nhap(){
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Nhap nam sinh: ";
            cin >> namSinh;
        }

        void xuat(){
            cout << hoTen << " " << namSinh << " ";
        }
};

class Sinhvien : public Nguoi{
    private:
        string ma;
        float dtb;
    public:
        Sinhvien(){
            ma = "";
            dtb = 0;
        }

        Sinhvien(string hoTen, int namSinh, string ma, float dtb) : Nguoi(hoTen, namSinh){
            this->ma = ma;
            this->dtb = dtb;
        }

        string getMa() {
            return ma;
        }

        void nhap(){
            Nguoi :: nhap();
            cin.ignore();
            cout << "Nhap ma sinh vien: ";
            getline(cin, ma);
            cout << "Nhap diem trung binh: ";
            cin >> dtb;
        }

        void xuat(){
            Nguoi :: xuat();
            cout << ma << " " << dtb << endl;
        }

        friend bool operator < (Sinhvien a, Sinhvien b);
};

bool operator < (Sinhvien a, Sinhvien b){
    return a.dtb > b.dtb;
}

void Timkiem(Sinhvien a[], int n, string tukhoa){
    bool timthay = false;
    for(int i = 0; i < n; i++){
        if(a[i].getMa() == tukhoa || a[i].getHoTen() == tukhoa ){
            timthay = true;
            a[i].xuat();
        }
    }
    if(!timthay){
        cout << "Khong tim thay!!" << endl;
    }
}

int main(){
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    Sinhvien a[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }
    
    sort(a, a + n);
    cout << "Sap xep theo diem trung binh giam dan: " << endl;
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
    
    cin.ignore();
    string tukhoa;
    cout << "Tim kiem thong tin sinh vien qua ma sinh vien hoac ho ten: ";
    getline(cin, tukhoa);
    Timkiem(a, n, tukhoa);
    return 0;
}