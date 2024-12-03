#include <bits/stdc++.h>
using namespace std;
class Nhansu{
    protected:
        string manv, hoten;
        int namsinh;
    public:
        Nhansu(){
            manv = hoten = "";
            namsinh = 0;
        }

        Nhansu(string mannv, string hoten, int namsinh){
            this->manv = manv;
            this->hoten = hoten;
            this->namsinh = namsinh;
        }

        void nhap(){
            cout << "Nhap ma nhan vien: ";
            cin >> manv;
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoten);
            cout << "Nhap nam sinh: ";
            cin >> namsinh;
        }

        void xuat(){
            cout << "Ma nhan vien: " << manv << endl
                 << "Ho ten: " << hoten << endl
                 << "Nam sinh: " << namsinh << endl;
        }
};

class Congnhan : public Nhansu{
    private:
        int ngaycong;
    public:
        Congnhan(){
            ngaycong = 0;
        }

        Congnhan(string mannv, string hoten, int namsinh, int ngaycong) : Nhansu(manv, hoten, namsinh){
            this->ngaycong = ngaycong;
        }

        long long tinhtienthuong(){
            if(ngaycong > 26){
                return (ngaycong - 26) * 100000;
            }
            return 0;
        }

        int getNgaycong(){
            return ngaycong;
        }

        void nhap(){
            Nhansu :: nhap();
            cout << "Nhap so ngay cong: ";
            cin >> ngaycong;
        }

        void xuat(){
            Nhansu :: xuat();
            cout << "So ngay cong: " << ngaycong << endl
                 << "So tien duoc thuong: " << tinhtienthuong() << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong cong nhan: ";
    cin >> n;
    vector<Congnhan> ds(n);
    for(int i = 0; i < n; i++){
        ds[i].nhap();
    }

    cout << "\nDanh sach cong nhan duoc thuong la: " << endl;
    for(int i = 0; i < n; i++){
        if(ds[i].getNgaycong() > 26){
            ds[i].xuat();
        }
    }
    return 0;
}