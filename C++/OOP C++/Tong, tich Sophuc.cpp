#include <bits/stdc++.h>
using namespace std;

class Sophuc {
private:
    double pthuc, pao;

public:
    // Constructor không tham số
    Sophuc() {
        pthuc = pao = 0;
    }

    // Constructor có tham số
    Sophuc(double pthuc, double pao) {
        this->pthuc = pthuc;
        this->pao = pao;
    }

    // Nạp chồng toán tử cộng
    Sophuc operator + (Sophuc a) {
        Sophuc tong;
        tong.pthuc = a.pthuc + pthuc;
        tong.pao = a.pao + pao;
        return tong;
    }

    // Nạp chồng toán tử nhân
    Sophuc operator * (Sophuc a) {
        Sophuc tich;
        tich.pthuc = pthuc * a.pthuc - pao * a.pao;  // Phần thực
        tich.pao = pthuc * a.pao + pao * a.pthuc;    // Phần ảo
        return tich;
    }

    // Nạp chồng toán tử nhập
    friend istream& operator >> (istream &in, Sophuc &a);
    // Nạp chồng toán tử xuất
    friend ostream& operator << (ostream &out, Sophuc a);
};

istream& operator >> (istream &in, Sophuc &a) {
    cout << "Nhap phan thuc va phan ao: ";
    in >> a.pthuc >> a.pao;
    return in;
}

ostream& operator << (ostream &out, Sophuc a) {
    if (a.pao >= 0)
        out << a.pthuc << " + " << a.pao << "i";
    else
        out << a.pthuc << " - " << -a.pao << "i";
    return out;
}

int main() {
    Sophuc a, b;
    cout << "Nhap so phuc a: " << endl;
    cin >> a;
    cout << "Nhap so phuc b: " << endl;
    cin >> b;

    Sophuc x = a + b;  // Tính tổng
    Sophuc y = a * b;  // Tính tích

    cout << "Tong = " << x << endl;
    cout << "Tich = " << y << endl;

    return 0;
}
