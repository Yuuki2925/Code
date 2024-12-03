#include <bits/stdc++.h>
using namespace std;
class Canbo{
    protected:
        string hoten, gioitinh, diachi;
        int namsinh;
    public:
        Canbo(){
            hoten = gioitinh = diachi = "";
            namsinh = 0;
        }

        Canbo(string hoten, string gioitinh, string diachi, int namsinh){
            this->hoten = hoten;
            this->gioitinh = gioitinh;
            this->diachi = diachi;
            this->namsinh = namsinh;
        }
        string getHoTen(){
            return hoten;
        }

        virtual void nhap(){
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoten);
            cout << "Nhap gioi tinh: ";
            cin >> gioitinh;
            cin.ignore();
            cout << "Nhap dia chi: ";
            getline(cin, diachi);
            cout << "Nhap nam sinh: ";
            cin >> namsinh;
        }

        virtual void xuat(){
            cout << "Ho va ten: " << hoten << endl
                 << "Gioi tinh: " << gioitinh << endl
                 << "Dia chi: " << diachi << endl
                 << "Nam sinh: " << namsinh << endl;
        }
};

class Congnhan : public Canbo{
    private:
        int bac;
    public:
        Congnhan(){
            bac = 0;
        }

        Congnhan(string hoten, string gioitinh, string diachi, int namsinh, int bac) : Canbo(hoten, gioitinh, diachi, namsinh){
            this->bac = bac;
        }

        void nhap(){
            Canbo :: nhap();
            cin.ignore();
            cout << "Nhap bac: ";
            cin >> bac;
        }

        void xuat(){
            Canbo :: xuat();
            cout << "Bac: " << bac << "/9" << endl;
        }
};

class Kysu : public Canbo{
    private:
        string nganhdt;
    public:
        Kysu(){
            nganhdt = "";
        }

        Kysu(string hoten, string gioitinh, string diachi, int namsinh, string nganhdt) : Canbo(hoten, gioitinh, diachi, namsinh){
            this->nganhdt = nganhdt;
        }

        void nhap(){
            Canbo :: nhap();
            cin.ignore();
            cout << "Nhap nganh dao tao: ";
            getline(cin, nganhdt);
        }

        void xuat(){
            Canbo :: xuat();
            cout << "Nganh dao tao: " << nganhdt << endl;
        }
};

class Nhanvien : public Canbo{
    private:
        string congviec;
    public:
        Nhanvien(){
            congviec = "";
        }

        Nhanvien(string hoten, string gioitinh, string diachi, int namsinh, string congviec) : Canbo(hoten, gioitinh, diachi, namsinh){
            this->congviec = congviec;
        }

        void nhap(){
            Canbo :: nhap();
            cin.ignore();
            cout << "Nhap cong viec: ";
            getline(cin, congviec);
        }

        void xuat(){
            Canbo :: xuat();
            cout << "Cong viec: " << congviec << endl;
        }
};

class QLCB{
    private:
        vector<Canbo*> dsCanbo;
    public:
        void nhapthongtin(){
            Canbo* cb;
            int n;
            cout << "Nhap so luong can bo: ";
            cin >> n;
            int loai;
            for(int i = 0; i < n; i++){
            cout << "Lua chon (1: Cong nhan, 2: Ky su, 3: Nhan vien): ";
            cin >> loai;
            if(loai == 1){
                cb = new Congnhan();
                dsCanbo.push_back(cb);
            }
            else if(loai == 2){
                cb = new Kysu();
                dsCanbo.push_back(cb);
            }
            else if(loai == 3){
                cb = new Nhanvien();
                dsCanbo.push_back(cb);
            }
            cb->nhap();
            }
        }

        void timkiemhoten(){
            string find;
            cin.ignore();
            cout << "Nhap ho ten can tim: ";
            getline(cin, find);
            bool found = false;
            for (int i = 0; i < dsCanbo.size(); i++) {
                if (dsCanbo[i]->getHoTen() == find) {
                    dsCanbo[i]->xuat();
                    found = true;
                }
            }
            if (!found) {
                cout << "Khong tim thay can bo co ten: " << find << endl;
            }
        }

        void hienthi(){
            for(int i = 0; i < dsCanbo.size(); i++){
                dsCanbo[i]->xuat();
            }
        }
};

int main() {
    QLCB qlcb;
    int luaChon;

    while (1) {
        cout << "\nCHUONG TRINH QUAN LY CAN BO\n";
        cout << "1. Nhap thong tin can bo moi\n";
        cout << "2. Tim kiem can bo theo ho ten\n";
        cout << "3. Hien thi danh sach can bo\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
        int n;
            qlcb.nhapthongtin();
            break;
        case 2:
            qlcb.timkiemhoten();
            break;
        case 3:
            qlcb.hienthi();
            break;
        case 4:
            return 0;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
    }

    return 0;
}

