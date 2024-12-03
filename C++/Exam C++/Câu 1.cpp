#include <bits/stdc++.h>
using namespace std;

class Thisinh {
private:
    string mats, ht;
    float dt, dl, dh;

public:
    // Constructor không đối
    Thisinh() {
        mats = ht = "";
        dt = dl = dh = 0;
    }

    // Constructor có đối
    Thisinh(string mats, string ht, float dt, float dl, float dh) {
        this->mats = mats;
        this->ht = ht;
        this->dt = dt;
        this->dl = dl;
        this->dh = dh;
    }

    // Tính tổng điểm thí sinh
    float tongdiem() {
        return dt + dl + dh;
    }

    string getHoten() {
        return ht;
    }

    // Hàm nhập, xuất
    void nhap() {
        cout << "Nhap ma thi sinh: ";
        cin >> mats;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, ht);
        cout << "Nhap diem toan: ";
        cin >> dt;
        cout << "Nhap diem ly: ";
        cin >> dl;
        cout << "Nhap diem hoa: ";
        cin >> dh;
    }

    void xuat(){
        cout << "Ma thi sinh: " << mats << endl
             << "Ho va ten: " << ht << endl
             << "Diem toan: " << dt << endl
             << "Diem ly: " << dl << endl
             << "Diem hoa: " << dh << endl
             << "Tong diem: " << tongdiem() << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    Thisinh* ts = new Thisinh[n];

    // Nhập thông tin các thí sinh
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        ts[i].nhap();
    }

    Thisinh maxTS = ts[0];
    for (int i = 1; i < n; i++) {
        if (ts[i].tongdiem() > maxTS.tongdiem()) {
            maxTS = ts[i];
        }
    }

    // In ra thí sinh có tổng điểm cao nhất
    cout << "\nSinh vien co tong diem cao nhat la:\n";
    maxTS.xuat();

    // Sắp xếp thí sinh theo họ tên tăng dần
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ts[i].getHoten() > ts[j].getHoten()) {
                Thisinh tmp = ts[i]; 
                ts[i] = ts[j];       
                ts[j] = tmp;         
            }
        }
    }

    // In ra danh sách thí sinh đã sắp xếp
    cout << "\nDanh sach thi sinh sau khi sap xep theo ho ten:\n";
    for (int i = 0; i < n; i++) {
        ts[i].xuat();
        cout << endl;
    }

    // Giải phóng bộ nhớ
    delete[] ts;

    return 0;
}
