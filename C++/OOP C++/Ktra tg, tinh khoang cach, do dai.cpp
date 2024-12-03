#include <bits/stdc++.h>
using namespace std;

class Diem {
private:
    float x, y;

public:
    // Constructor mặc định
    Diem() {
        x = y = 0;
    }

    // Constructor có tham số
    Diem(float x, float y) {
        this->x = x;
        this->y = y;
    }

    // Phương thức nhập tọa độ điểm
    void nhap() {
        cout << "Nhap toa do x: ";
        cin >> x;
        cout << "Nhap toa do y: ";
        cin >> y;
    }

    // Phương thức xuất tọa độ điểm
    void xuat() {
        cout << "(" << x << "," << y << ")";
    }

    // Khai báo hàm friend để tính khoảng cách giữa hai điểm
    friend float khoangCach(Diem a, Diem b);
};

// Hàm friend tính khoảng cách giữa hai điểm
float khoangCach(Diem a, Diem b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

class Tamgiac {
private:
    Diem A, B, C;
    float AB, AC, BC;

public:
    // Phương thức nhập tam giác (các đỉnh)
    void nhap() {
        cout << "Nhap toa do diem A:\n";
        A.nhap();
        cout << "Nhap toa do diem B:\n";
        B.nhap();
        cout << "Nhap toa do diem C C:\n";
        C.nhap();
        
        // Tính độ dài các cạnh
        AB = khoangCach(A, B);
        AC = khoangCach(A, C);
        BC = khoangCach(B, C);
    }

    // Phương thức xuất độ dài các cạnh
    void xuat() {
        cout << "Do dai cac canh la: AB = " << AB << ", AC = " << AC << ", BC = " << BC << endl;
    }

    // Phương thức kiểm tra loại tam giác
    void ktraTG() {
        if (AB + AC > BC && AB + BC > AC && AC + BC > AB) {
            if (AB == AC && AC == BC) {
                cout << "Tam giac deu" << endl;
            } 
            else if (AB == AC || AC == BC || AB == BC) {
                if (AB * AB + AC * AC == BC * BC || AB * AB + BC * BC == AC * AC || AC * AC + BC * BC == AB * AB) {
                    cout << "Tam giac vuong can" << endl;
                } else {
                    cout << "Tam giac can" << endl;
                }
            } 
            else if (AB * AB + AC * AC == BC * BC || AB * AB + BC * BC == AC * AC || AC * AC + BC * BC == AB * AB) {
                cout << "Tam giac vuong" << endl;
            } 
            else {
                cout << "Tam giac thuong" << endl;
            }
        } else {
            cout << "Ba diem khong tao thanh tam giac" << endl;
        }
    }
};

int main() {
    Tamgiac tg;
    tg.nhap();
    tg.xuat();
    tg.ktraTG();
    return 0;
}
