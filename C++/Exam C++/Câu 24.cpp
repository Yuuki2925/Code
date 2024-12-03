#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int x = a % b;
        a = b;
        b = x;
    }
    return a;
}

class PS1 {
protected:
    int ts, ms; // Tử số và mẫu số
public:
    PS1(){
        ts = 0;
        ms = 1;
    }

    PS1(int tu, int mau){
        ts = tu;
        ms = mau;
    }

    void nhap() {
        cout << "Nhap tu so: ";
        cin >> ts;
        do {
            cout << "Nhap mau so: ";
            cin >> ms;
            if (ms == 0) {
                cout << "Nhap lai mau so khac 0." << endl;
            }
        } while (ms == 0);
    }

    int getTs() {
        return ts;
    }

    int getMs() {
        return ms;
    }

    void xuat() {
        cout << ts << "/" << ms;
    }

    void toigian() {
        int ucln = gcd(abs(ts), abs(ms));
        ts /= ucln;
        ms /= ucln;
        if (ms < 0) {
            ts = -ts;
            ms = -ms;
        }
    }
};

class PS2 : public PS1 {
public:
    PS2() : PS1() {} // Constructor không tham số kế thừa từ PS1
    
    PS2(int tu, int mau) : PS1(tu, mau) {} // Constructor 2 tham số từ PS1
    
    PS2 operator=(PS2 a) {
        ts = a.ts;
        ms = a.ms;
        return *this;
    }

    bool operator>(PS2 a) {
        return ts * a.ms > a.ts * ms;
    }

    PS2 operator+(PS2 a) {
        PS2 sum;
        sum.ts = a.ts * ms + a.ms * ts;
        sum.ms = ms * a.ms;
        sum.toigian();
        return sum;
    }
};

int main() {
    int n;
    do {
        cout << "Nhap so luong phan so (Toi da 10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    PS2 ps[10];
    for (int i = 0; i < n; i++) {
        ps[i].nhap();
        ps[i].toigian();
    }

    PS2 max = ps[0];
    for (int i = 1; i < n; i++) {
        if (ps[i] > max) {
            max = ps[i];
        }
    }

    cout << "Phan so co gia tri lon nhat la: ";
    max.xuat();
    cout << endl;

    PS2 tong = PS2(0,1);
    tong.toigian(); 
    for (int i = 0; i < n; i++) {
        if (ps[i].getTs() * 4 > ps[i].getMs()) { // Điều kiện > 1/4
            tong = tong + ps[i];
        }
    }

    cout << "Tong phan so co gia tri lon hon 1/4 la: ";
    tong.xuat();
    cout << endl;

    return 0;
}
