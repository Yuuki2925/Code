#include <bits/stdc++.h>
using namespace std;
class Monhoc{
    protected:
        string tenmon;
        float dcc, dktra, dthi;
    public:
        Monhoc(){
            tenmon = "";
            dcc = dktra = dthi = 0;
        }

        Monhoc(string tenmon, float dcc, float dktra, float dthi){
            this->tenmon = tenmon;
            this->dcc = dcc;
            this->dktra = dktra;
            this->dthi = dthi;
        }

        float getdcc(){
            return dcc;
        }

        float getdktra(){
            return dktra;
        }

        void nhap(){
            cin.ignore();
            cout << "Nhap ten mon: ";
            getline(cin, tenmon);
            cout << "Nhap diem chuyen can: ";
            cin >> dcc;
            cout << "Nhap diem kiem tra: ";
            cin >> dktra;
            cout << "Nhap diem thi: ";
            cin >> dthi;
        }

        void xuat(){
            cout << "Ten mon: " << tenmon << endl
                 << "Diem chuyen can: " << dcc << endl
                 << "Diem kiem tra: " << dktra << endl
                 << "Diem thi: " << dthi << endl;
        }
};

class Sinhvien : public Monhoc{
    private:
        string hoten, lop, masv;
    public:
        Sinhvien(){
            hoten = lop = masv = "";
        }

        Sinhvien(string tenmon, float dcc, float dktra, float dthi, string hoten, string lop, string masv) : Monhoc(tenmon, dcc, dktra, dthi){
            this->hoten = hoten;
            this->lop = lop;
            this->masv = masv;
        }

        float tinhDiemHocPhan(){
            return dcc * 0.1 + dktra * 0.3 + dthi * 0.6;
        }

        void nhap(){
            Monhoc :: nhap();
            cout << "Nhap ho ten sinh vien: ";
            cin.ignore();
            getline(cin, hoten);
            cout << "Nhap lop: ";
            getline(cin, lop);
            cout << "Nhap ma sinh vien: ";
            getline(cin, masv);
        }

        void xuat(){
            Monhoc :: xuat();
            cout << "Ho ten: " << hoten << endl
                 << "Lop: " << lop << endl
                 << "Ma sinh vien: " << masv << endl
                 << "Diem hoc phan: " << tinhDiemHocPhan() << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    vector<Sinhvien> a(n);
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }

    cout << "\nDanh sach sinh vien bi cam thi la: \n";
    for(int i = 0; i < n; i++){
        if(a[i].getdcc() < 5 || a[i].getdktra() == 0){
            a[i].xuat();
            cout << endl;
        }
    }
    return 0;
}