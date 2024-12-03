#include <bits/stdc++.h>
using namespace std;

class Thisinh {
private:
    string masv, hoten;
    float dt, dl, dh;

public:
    // Hàm tính tổng điểm
    float tinhtongdiem() {
        return dt + dl + dh;
    }

    // Constructor không đối
    Thisinh() {
        masv = hoten = "";
        dt = dl = dh = 0;
    }

    // Constructor có đối
    Thisinh(string masv, string hoten, float dt, float dl, float dh) {
        this->masv = masv;
        this->hoten = hoten;
        this->dt = dt;
        this->dl = dl;
        this->dh = dh;
    }

    friend istream& operator >> (istream &in, Thisinh &a);
    friend ostream& operator << (ostream &out, Thisinh &a);
    friend bool operator < (Thisinh &a, Thisinh &b);
};

istream& operator >> (istream &in, Thisinh &a) {
    cout << "Nhap ma sv: ";
    in >> a.masv;
    cout << "Nhap ho ten: ";
    in.ignore();
    getline(in, a.hoten);
    cout << "Nhap diem toan, ly, hoa: ";
    in >> a.dt >> a.dl >> a.dh;
    return in;
}

ostream& operator << (ostream &out, Thisinh &a) {
    out << a.masv << " " << a.hoten << " " << a.dt << " " << a.dl << " " << a.dh << " " << a.tinhtongdiem() << endl;
    return out;
}

bool operator < (Thisinh &a, Thisinh &b) {
    return a.hoten < b.hoten;
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    Thisinh a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].tinhtongdiem() > a[max].tinhtongdiem()) {
            max = i;
        }
    }

    cout << "Sinh vien co tong diem cao nhat:\n" << a[max];

    // Sắp xếp sinh viên theo tên
    sort(a, a + n);
    cout << "\nDanh sach sinh vien sau khi sap xep:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }

    return 0;
}
