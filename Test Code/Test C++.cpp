#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, p, chuvi, dientich;
    
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;


    if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
        p = (a + b + c) / 2; 
        chuvi = a + b + c;
        dientich = sqrt(p * (p - a) * (p - b) * (p - c));

        cout << "Chu vi tam giac la: " << chuvi << endl;
        cout << "Dien tich tam giac la: " << dientich << endl;
    } else {
        cout << "Khong phai la tam giac hop le!" << endl;
    }
    
    return 0;
}
