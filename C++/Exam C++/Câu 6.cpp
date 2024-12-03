#include <bits/stdc++.h>
using namespace std;
class Nguoi{
    protected:
        string hoten;
        int namsinh;
    public:
        Nguoi(){
            hoten = "";
            namsinh = 0;
        }

        Nguoi(string hoten, int namsinh){
            this->hoten = hoten;
            this->namsinh = namsinh;
        }

        string getHoten(){
            return hoten;
        }

        void nhap(){
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoten);
            cout << "Nhap nam sinh: ";
            cin >> namsinh;
        }

        void xuat(){
            cout << "Ho va ten: " << hoten << ", " << "Nam sinh: " << namsinh << ", ";
        }
};

class Sinhvien : public Nguoi{
    private:
        string masv;
        float dtb;
    public:
        Sinhvien(){
            masv = "";
            dtb = 0;
        }

        Sinhvien(string hoten, int namsinh, string masv, float dtb) : Nguoi(hoten, namsinh){
            this->masv = masv;
            this->dtb = dtb;
        }

        string getMsv(){
            return masv;
        }

        void nhap(){
            Nguoi :: nhap();
            cout << "Nhap ma sinh vien: ";
            cin >> masv;
            cout << "Nhap diem trung binh: ";
            cin >> dtb;
        }
        
        void xuat(){
            Nguoi :: xuat();
            cout << "Ma sinh vien: " << masv << ", " << "Diem trung binh: " << fixed << setprecision(2) << dtb << endl;
        }
};

int main(){
    int n;
    cout << "So luong sinh vien la: ";
    cin >> n;
    Sinhvien a[n];

    for(int i = 0; i < n; i++){
        a[i].nhap();
    }

    string find;
    cout << "\nNhap ho ten hoac ma sinh vien muon tim: ";
    cin.ignore();
    getline(cin, find);
    bool found = false;
    for(int i = 0; i < n; i++){
        if(find == a[i].getHoten() || find == a[i].getMsv()){
            found = true;
            a[i].xuat();
        }
    }
    if(!found){
        cout << "Khong tim thay!!";
    }
    return 0;
}