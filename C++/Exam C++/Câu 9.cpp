#include <bits/stdc++.h>
using namespace std;
class Nhanvien{
    private:
        string hoten, chucvu, gioitinh, quequan;
        int namsinh, namvaolam;
    public:

    //Constructor khong doi
        Nhanvien(){
            hoten = chucvu = gioitinh = quequan = "";
            namsinh = namvaolam = 0;
        }

    //Constructor co doi
        Nhanvien(string hoten, string chucvu, string gioitinh, string quequan, int namsinh, int namvaolam){
            this->hoten = hoten;
            this->chucvu = chucvu;
            this->gioitinh = gioitinh;
            this->quequan = quequan;
            this->namsinh = namsinh;
            this->namvaolam = namvaolam;
        }

    int getNamvaolam(){
        return namvaolam;
    }

    //Ham nhap, xuat
    friend istream& operator >> (istream &in, Nhanvien &a);
    friend ostream& operator << (ostream &out, Nhanvien a);
};

istream& operator >> (istream &in, Nhanvien &a){
    in.ignore();
    cout << "Nhap ho ten: ";
    getline(in, a.hoten);
    cout << "Nhap chuc vu: ";
    getline(in, a.chucvu);
    cout << "Nhap gioi tinh: ";
    getline(in, a.gioitinh);
    cout << "Nhap que quan: ";
    getline(in, a.quequan);
    cout << "Nhap nam sinh: ";
    in >> a.namsinh;
    cout << "Nhap nam vao lam: ";
    in >> a.namvaolam;
    return in;
}

ostream& operator << (ostream &out, Nhanvien a){
    out << "Ho va ten: " << a.hoten << endl
        << "Chuc vu: " << a.chucvu << endl
        << "Gioi tinh: " << a.gioitinh << endl
        << "Que quan: " << a.quequan << endl
        << "Nam sinh: " << a.namsinh << endl
        << "Nam vao lam: " << a.namvaolam << endl << endl;
        return out;
}

int main(){
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    Nhanvien a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhan vien thu " << i + 1 << endl;
        cin >> a[i];
    }

    cout << "\nDanh sach nhan vien vao lam tren 20 nam:" << endl;
    for(int i = 0; i < n; i++){
        if(2024 - a[i].getNamvaolam() > 20){
            cout << a[i];
        }
    }
    return 0;
}

