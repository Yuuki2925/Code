#include <bits/stdc++.h>
using namespace std;
class Nguoi{
    private:
        string hoTen, queQuan;
        int tuoi, namSinh;
    public:
        Nguoi(){
            hoTen = queQuan = "";
            tuoi = namSinh = 0;
        }

        Nguoi(string hoTen, string queQuan, int tuoi, int namSinh){
            this->hoTen = hoTen;
            this->queQuan = queQuan;
            this->tuoi = tuoi;
            this->namSinh = namSinh;
        }

        string getqueQuan(){
            return queQuan;
        }

        int getnamSinh(){
            return namSinh;
        }

        void nhap(){
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Nhap so tuoi: ";
            cin >> tuoi;
            cout << "Nhap nam sinh: ";
            cin >> namSinh;
            cin.ignore();
            cout << "Nhap que quan: ";
            getline(cin, queQuan);
        }

        void xuat(){
            cout << hoTen << " " << tuoi << " " << namSinh << " " << queQuan << endl;
        }
};

class HSHocSinh : public Nguoi {
    private:
        string lop, khoaHoc;
        int kyHoc;
    public:
        HSHocSinh(){
            lop = khoaHoc = "";
            kyHoc = 0;
        }

        HSHocSinh(string hoTen, string queQuan, int tuoi, int namSinh, string lop, string khoaHoc, int kyHoc) : Nguoi(hoTen, queQuan, tuoi, namSinh){
            this->lop = lop;
            this->khoaHoc = khoaHoc;
            this->kyHoc = kyHoc;
        }
    
        void nhap(){
            Nguoi :: nhap();
            cout << "Nhap lop: ";
            getline(cin, lop);
            cout << "Nhap khoa hoc: ";
            getline(cin, khoaHoc);
            cout << "Nhap ky hoc: ";
            cin >> kyHoc;
        }

        void in(){
            Nguoi :: xuat();
            cout << lop << " " << khoaHoc << " " << kyHoc << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    HSHocSinh a[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }

    int cnt = 0;
    cout << "Sinh vien co nam sinh 1985 la: "<< endl;
    for(int i = 0; i < n; i++){
        if(a[i].getnamSinh() == 1985){
            a[i].xuat();
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i].getnamSinh() == 1985 && a[i].getqueQuan() == "Thai Nguyen"){
            cnt++;
        }
    }
    cout << "So sinh vien sinh 1985 va co que o Thai Nguyen la: " << cnt << endl;
    return 0;
}