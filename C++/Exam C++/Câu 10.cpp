#include <bits/stdc++.h>
using namespace std;
class Nhansu{
    protected:
        string manv, hoten;
        int namsinh;
    public:
        Nhansu(){
            manv = hoten = "";
            namsinh = 0;
        }

        Nhansu(string mannv, string hoten, int namsinh){
            this->manv = manv;
            this->hoten = hoten;
            this->namsinh = namsinh;
        }

        void nhap(){
            cout << "Nhap ma nhan vien: ";
            cin >> manv;
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoten);
            cout << "Nhap nam sinh: ";
            cin >> namsinh;
        }

        void xuat(){
            cout << "Ma nhan vien: " << manv << ", "
                 << "Ho ten: " << hoten << ", "
                 << "Nam sinh: " << namsinh << ", ";
        }
};

class Canbo : public Nhansu{
    private:
        long long luongcoban, hesoluong;
    public:
        Canbo(){
            luongcoban = hesoluong = 0;
        }

        Canbo(string mannv, string hoten, int namsinh, long long luongcoban, long long hesoluong) : Nhansu(manv, hoten, namsinh){
            this->luongcoban = luongcoban;
            this->hesoluong = hesoluong;
        }

        long long luongcanbo(){
            return luongcoban * hesoluong;
        }

        void nhap(){
            Nhansu :: nhap();
            cout << "Nhap luong co ban: ";
            cin >> luongcoban;
            cout << "Nhap he so luong: ";
            cin >> hesoluong;
        }

        void xuat(){
            Nhansu :: xuat();
            cout << "Luong co ban: " << luongcoban << ", "
                 << "He so luong: " << hesoluong << ", "
                 << "Luong can bo: " << luongcanbo() << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    Canbo a[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i].luongcanbo() > a[j].luongcanbo()){
                Canbo tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    cout << "Danh sach can bo theo thu tu giam dan cua tien luong la: " << endl;
    for(int i = 0; i < n; i++){
        a[i].xuat();
    }
}