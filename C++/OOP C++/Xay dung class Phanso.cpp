#include <bits/stdc++.h>
using namespace std;

// Hàm tính GCD
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Phanso {
    private:
        int ts, ms; // Tử số và mẫu số
    public:
        // Constructor không có đối số
        Phanso() {
            ts = 0;
            ms = 1;
        }

        // Constructor có đối số
        Phanso(int ts, int ms) {
            this->ts = ts;
            this->ms = ms;
            if (ms < 0) {  // Chuyển dấu về tử số
                this->ts = -this->ts;
                this->ms = -this->ms;
            }
        }

        // Nạp chồng toán tử cộng
        Phanso operator +(Phanso a) {
            Phanso k;
            k.ts = ts * a.ms + ms * a.ts;
            k.ms = ms * a.ms;
            k.timGcd();  // Rút gọn phân số
            return k;
        }

        // Nạp chồng toán tử trừ
        Phanso operator -(Phanso a) {
            Phanso k;
            k.ts = ts * a.ms - ms * a.ts;
            k.ms = ms * a.ms;
            k.timGcd();  // Rút gọn phân số
            return k;
        }

        // Nạp chồng toán tử nhân
        Phanso operator *(Phanso a) {
            Phanso k;
            k.ts = ts * a.ts;
            k.ms = ms * a.ms;
            k.timGcd();  // Rút gọn phân số
            return k;
        }

        // Nạp chồng toán tử chia
        Phanso operator /(Phanso a) {
            Phanso k;
            k.ts = ts * a.ms;
            k.ms = ms * a.ts;
            k.timGcd();  // Rút gọn phân số
            return k;
        }

        // Hàm tìm GCD để rút gọn phân số
        void timGcd() {
            long long g = gcd(abs(ts), abs(ms));
            ts /= g;
            ms /= g;
            if (ms < 0) {  // Đảm bảo mẫu số luôn dương
                ts = -ts;
                ms = -ms;
            }
        }

        // Nạp chồng toán tử xuất và nhập
        friend istream& operator >> (istream &in, Phanso &p);
        friend ostream& operator << (ostream &out, Phanso p);
};

istream& operator >> (istream &in, Phanso &p) {
    cout << "Nhap tu so: ";
    in >> p.ts;
    do {
        cout << "Nhap mau so (khac 0): ";
        in >> p.ms;
        if (p.ms == 0) {
            cout << "Mau so khong duoc bang 0. Nhap lai." << endl;
        }
    } while (p.ms == 0);
    // Rút gọn phân số sau khi nhập
    p.timGcd();
    return in;
}

ostream& operator <<(ostream &out, Phanso p) {
    if (p.ms == 1) {
        out << p.ts; // Nếu mẫu số là 1, chỉ in tử số
    } else {
        out << p.ts << "/" << p.ms;
    }
    return out;
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    Phanso a[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        cin >> a[i];
    }

    // Khởi tạo các biến tong, hieu, tich, thuong với phân số đầu tiên
    Phanso tong = a[0];
    Phanso hieu = a[0];
    Phanso tich = a[0];
    Phanso thuong = a[0];

    // Tính tổng, hiệu, tích và thương của n phân số
    for (int i = 1; i < n; i++) {
        tong = tong + a[i];
        hieu = hieu - a[i];
        tich = tich * a[i];
        thuong = thuong / a[i];
    }

    // In kết quả
    cout << "\nTong cac phan so: " << tong << endl;
    cout << "Hieu cac phan so: " << hieu << endl;
    cout << "Tich cac phan so: " << tich << endl;
    cout << "Thuong cac phan so: " << thuong << endl;

    return 0;
}
