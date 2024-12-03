#include <bits/stdc++.h>
using namespace std;
class Nguoi{
    protected:
        string hoten;
        int namsinh;
    public:
    //Constructor khong doi
        Nguoi(){
            hoten = "";
            namsinh = 0;
        }

    //Constructor co doi
        Nguoi(string hoten, int namsinh){
            this->hoten = hoten;
            this->namsinh = namsinh;
        }

    //Ham nhap, xuat
        void nhap(){
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoten);
            cout << "Nhap nam sinh: ";
            cin >> namsinh;
            cin.ignore();
        }

        void xuat(){
            cout << "Ho ten: " << hoten << ", "
                 << "Nam sinh: " << namsinh << ", ";
        }
};

class Giangvien : public Nguoi{
    private:
        string bmcongtac, bmgiangday;
    public:
        Giangvien(){
            bmcongtac = bmgiangday = "";
        }

        Giangvien(string hoten, int namsinh, string bmcongtac, string bmgiangday) : Nguoi(hoten, namsinh){
            this->bmcongtac = bmcongtac;
            this->bmgiangday = bmgiangday;
        }

        string getBmcongtac(){
            return bmcongtac;
        }

        void nhap(){
            Nguoi :: nhap();
            cout << "Nhap bo mon cong tac: ";
            getline(cin, bmcongtac);
            cout << "Nhap bo mon giang day: ";
            getline(cin, bmgiangday);
        }

        void xuat(){
            Nguoi :: xuat();
            cout << "Bo mon cong tac: " << bmcongtac << ", "
                 << "Bo mon giang day: " << bmgiangday << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong giang vien: ";
    cin >> n;
    vector<Giangvien> ds(n);

    for(int i = 0; i < n; i++){
        ds[i].nhap();
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].getBmcongtac() > ds[j].getBmcongtac()){
                Giangvien tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        ds[i].xuat();
    }
    return 0;
}