#include <bits/stdc++.h>
using namespace std;

class Nhansu {
    private:
        string manv, hoten;
        int namsinh;
    public:
        Nhansu() {
            manv = hoten = "";
            namsinh = 0;
        }

        Nhansu(string manv, string hoten, int namsinh) {
            this->manv = manv;
            this->hoten = hoten;
            this->namsinh = namsinh;
        }

        void nhap() {
            cout << "Nhap ma nhan vien: ";
            cin >> manv;
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, hoten);
            cout << "Nhap nam sinh: ";
            cin >> namsinh;
        }

        void xuat() {
            cout << manv << " " << hoten << " " << namsinh << " ";
        }
};

class Canbo : public Nhansu {
    private:
        long long lcb;
        double hsl;
    public:
        Canbo() {
            lcb = hsl = 0;
        }

        Canbo(string manv, string hoten, int namsinh, long long lcb, double hsl) : Nhansu(manv, hoten, namsinh) {
            this->lcb = lcb;
            this->hsl = hsl;
        }

        double luong() {
            return lcb * hsl;
        }

        void nhap() {
            Nhansu::nhap();
            cout << "Nhap luong co ban: ";
            cin >> lcb;
            cout << "Nhap he so luong: ";
            cin >> hsl;
        }

        void xuat() {
            Nhansu::xuat();
            cout << lcb << " " << hsl << " " << luong() << endl;
        }

        friend bool operator < (Canbo a, Canbo b);
};

bool operator < (Canbo a, Canbo b) {
    return a.luong() > b.luong(); // Sắp xếp lương giảm dần
}

int main() {
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    
    // Sử dụng cấp phát động cho mảng
    Canbo* a = new Canbo[n];
    
    for(int i = 0; i < n; i++) {
        a[i].nhap();
    }

    sort(a, a + n);
    
    for(int i = 0; i < n; i++) {
        a[i].xuat();
    }

    // Giải phóng bộ nhớ
    delete[] a;
    
    return 0;
}
