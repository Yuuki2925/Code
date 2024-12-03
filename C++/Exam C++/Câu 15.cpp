#include <bits/stdc++.h>
using namespace std;
class Canbo{
    protected:
        string macb, madv, hoten;
        int namsinh;
    public:
        Canbo(){
            macb = madv = hoten = "";
            namsinh = 0;
        }

        Canbo(string mcb, string mdv, string ht, int ns){
            macb = mcb;
            madv = mdv;
            hoten = ht;
            namsinh = ns;
        }

        void nhap(){
            cout << "Nhap ma can bo: ";
            cin >> macb;
            cout << "Nhap ma don vi: ";
            cin >> madv;
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoten);
            cout << "Nhap nam sinh: ";
            cin >> namsinh;
        }

        void xuat(){
            cout << "Ma can bo: " << macb << endl
                 << "Ma don vi: " << madv << endl
                 << "Ho va ten: " << hoten << endl
                 << "Nam sinh: " << namsinh << endl;
        }
};

class Luong : public Canbo{
    private:
        double phucap, hesoluong, baohiem;
    public:
        Luong(){
            phucap = hesoluong = baohiem = 0;
        }

        Luong(string mcb, string mdv, string ht, int ns, double pc, double hsl, double bh) : Canbo(mcb, mdv, ht, ns){
            phucap = pc;
            hesoluong = hsl;
            baohiem = bh;
        }

        double tinhLuong(){
            return hesoluong * 290000 + phucap - baohiem;
        }

        void nhap(){
            Canbo :: nhap();
            cout << "Nhap phu cap: ";
            cin >> phucap;
            cout << "Nhap he so luong: ";
            cin >> hesoluong;
            cout << "Nhap bao hiem: ";
            cin >> baohiem;
        }

        void xuat(){
            Canbo :: xuat();
            cout << "Phu cap: " << phucap << endl
                 << "He so luong: " << hesoluong << endl
                 << "Bao hiem: " << baohiem <<endl
                 << "Luong can bo: " << tinhLuong() << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    vector<Luong> ds(n);

    for(int i = 0; i < n; i++){
        cout << "Can bo thu " << i + 1 << endl;
        ds[i].nhap();
    }

    cout << "Luong cua can bo la: " << endl;
    for(int i = 0; i < n; i++){
        ds[i].xuat();
    }
    return 0;
}