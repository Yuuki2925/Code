#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class SP1 {
protected:
    float pt, pa;

public:
    SP1() {
        pt = pa = 0;
    }

    SP1(float pt, float pa) {
        this->pt = pt;
        this->pa = pa;
    }

    double module() {
        return sqrt(pt * pt + pa * pa);
    }

    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> pt;
        cout << "Nhap phan ao: ";
        cin >> pa;
    }

    void hienThi() {
        cout << pt << " + " << pa << "i" << endl;
    }
};

class SP2 : public SP1 {
public:
    SP2() {}

    SP2(float pt, float pa) : SP1(pt, pa) {}

    SP2 operator + (SP2 a) {
        SP2 tong;
        tong.pt = a.pt + pt;
        tong.pa = a.pa + pa;
        return tong;
    }

    friend bool operator > (SP2 a, SP2 b);
    friend bool operator < (SP2 a, SP2 b);
    friend bool operator == (SP2 a, SP2 b);
};

bool operator > (SP2 a, SP2 b) {
    return a.module() > b.module();
}

bool operator < (SP2 a, SP2 b) {
    return a.module() < b.module();
}

bool operator == (SP2 a, SP2 b) {
    return (a.pt == b.pt && a.pa == b.pa);
}

int main() {
    int n;
    cout << "Nhap so luong so phuc (toi da 10): ";
    cin >> n;
    if (n > 10){
        n = 10; // Đảm bảo số phần tử không vượt quá 10
    }
    
    SP2 ds[10];

    // Nhập danh sách các số phức
    for (int i = 0; i < n; i++) {
        cout << "Nhap so phuc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // 4. Sắp xếp danh sách theo thứ tự tăng dần module
    sort(ds, ds + n); // Sử dụng toán tử < đã nạp chồng

    cout << "\nDanh sach so phuc theo thu tu tang dan cua module:\n";
    for (int i = 0; i < n; i++) {
        ds[i].hienThi();
    }

    // 3. Sắp xếp danh sách theo thứ tự giảm dần module
    sort(ds, ds + n, greater<SP2>()); // Sử dụng toán tử > đã nạp chồng

    cout << "\nDanh sach so phuc theo thu tu giam dan cua module:\n";
    for (int i = 0; i < n; i++) {
        ds[i].hienThi();
    }

    // 5. Tìm số phức có module lớn nhất và nhỏ nhất
    SP2 max = ds[0], min = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i] > max){
            max = ds[i];
        }
        if (ds[i] < min){
            min = ds[i];
        }
    }

    cout << "\nSo phuc co module lon nhat: ";
    max.hienThi();
    cout << "So phuc co module nho nhat: ";
    min.hienThi();

    // 6. Tính tổng các số phức trong danh sách
    SP2 tong;
    for (int i = 0; i < n; i++) {
        tong = tong + ds[i]; // Sử dụng toán tử + đã nạp chồng
    }
    cout << "\nTong cac so phuc: ";
    tong.hienThi();

    // 7. Tìm số phức có giá trị bằng 3 + 4i và đếm xem có bao nhiêu số phức bằng 3+4i
    SP2 sp34(3, 4);
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i] == sp34){
            dem++;
        }
    }
    cout << "\nSo phuc co gia tri bang 3 + 4i: " << dem;
    return 0;
}
