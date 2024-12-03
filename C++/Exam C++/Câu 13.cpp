#include <bits/stdc++.h>
using namespace std;

class Matran {
private:
    int soHang, soCot;
    int pt[100][100];  // Mảng 2 chiều lưu các phần tử ma trận

public:
    // Hàm nhập ma trận
    void nhap() {
        cout << "Nhap so hang: ";
        cin >> soHang;
        cout << "Nhap so cot: ";
        cin >> soCot;
        cout << "Nhap cac phan tu: " << endl;
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> pt[i][j];
            }
        }
    }

    // Hàm xuất ma trận
    void xuat() {
        cout << "Ma tran vua nhap la: " << endl;
        for (int i = 0; i < soHang; i++) {
            for (int j = 0; j < soCot; j++) {
                cout << pt[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Khai báo hàm bạn để tính tổng ma trận
    friend void tong(Matran a, Matran b);
};

void tong(Matran a, Matran b) {
    Matran sum;

    // Kiểm tra ma trận có cùng kích thước không
    if (a.soHang == b.soHang && a.soCot == b.soCot) {
        // Gán kích thước cho ma trận tổng
        sum.soHang = a.soHang;
        sum.soCot = a.soCot;

        // Tính tổng các phần tử của hai ma trận
        for (int i = 0; i < sum.soHang; i++) {
            for (int j = 0; j < sum.soCot; j++) {
                sum.pt[i][j] = a.pt[i][j] + b.pt[i][j];
            }
        }

        // In ra ma trận tổng
        cout << "Tong ma tran la: " << endl;
        for (int i = 0; i < sum.soHang; i++) {
            for (int j = 0; j < sum.soCot; j++) {
                cout << sum.pt[i][j] << " ";  // In ma trận tổng
            }
            cout << endl;
        }
    } else {
        cout << "Ma tran khong dong cap!!" << endl;
    }
}

int main() {
    Matran a, b;

    // Nhập hai ma trận
    cout << "Nhap ma tran A: " << endl;
    a.nhap();
    cout << "Nhap ma tran B: " << endl;
    b.nhap();

    // Xuất hai ma trận
    cout << "Ma tran A: " << endl;
    a.xuat();
    cout << "Ma tran B: " << endl;
    b.xuat();

    // Tính tổng hai ma trận
    tong(a, b);

    return 0;
}
