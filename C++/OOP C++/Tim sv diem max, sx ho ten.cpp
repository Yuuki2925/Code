#include <bits/stdc++.h>
using namespace std;
class Thisinh{
    private:
        string ma, ht;
        float dt, dl, dh;
    public:
        Thisinh(){
            ma = ht = "";
            dt = dl = dh = 0;
        }

        Thisinh(string ma, string ht, float dt, float dl, float dh){
            this->ma = ma;
            this->ht = ht;
            this->dt = dt;
            this->dl = dl;
            this->dh = dh;
        }

        float Tinhtongdiem(){
            return dt + dl + dh;
        }

        friend istream& operator >> (istream &in, Thisinh &a);
        friend ostream& operator << (ostream &out, Thisinh a);
        friend bool operator < (Thisinh a, Thisinh b);
};

istream& operator >> (istream &in, Thisinh &a){
    in.ignore();
    cout << "Nhap ma thi sinh: ";
    in >> a.ma;
    cout << "Nhap ho ten: ";
    in.ignore();
    getline(in, a.ht);
    cout << "Nhap diem toan: ";
    in >> a.dt;
    cout << "Nhap diem ly: ";
    in >> a.dl;
    cout << "Nhap diem hoa: ";
    in >> a.dh;
    return in;
}

ostream& operator << (ostream &out, Thisinh a){
    out << a.ma << " " << a.ht << " " << a.dt << " " << a.dl << " " << a.dh << " " << a.Tinhtongdiem() << endl;
    return out;
}

bool operator < (Thisinh a, Thisinh b){
    return a.ht > b.ht;
}

int main(){
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    Thisinh a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int max = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].Tinhtongdiem() > a[max].Tinhtongdiem()) {
            max = i;
        }
    }

    cout << "Sinh vien co tong diem cao nhat:\n" << a[max];

    // Sap xep sinh viên theo tên
    sort(a, a + n);
    cout << "\nDanh sach sinh vien sau khi sap xep:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    return 0;
}