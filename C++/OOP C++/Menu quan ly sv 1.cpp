#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ThiSinh {
protected:
    string sobaodanh, hoten, diachi;
    int uutien;

public:
    ThiSinh(){
        sobaodanh = hoten = diachi = "";
        uutien = 0;
    }

    ThiSinh(string sobaodanh, string hoten, string diachi, int uutien){
        this->sobaodanh = sobaodanh;
        this->hoten = hoten;
        this->diachi = diachi;
        this->uutien = uutien;
    }

    string getSobaodanh() {
        return sobaodanh;
    }

    virtual void nhap() {
        cout << "Nhap so bao danh: ";
        cin >> sobaodanh;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap dia chi: ";
        getline(cin, diachi);
        cout << "Nhap muc do uu tien: ";
        cin >> uutien;
    }

    virtual void xuat(){
        cout << "So bao danh: " << sobaodanh << endl
             << "Ho va ten: " << hoten << endl
             << "Dia chi: " << diachi << endl
             << "Muc do uu tien: " << uutien << endl;
    }
};

// Thí sinh thi khối A
class ThiSinhKhoiA : public ThiSinh {
public:
    ThiSinhKhoiA() : ThiSinh() {}
    ThiSinhKhoiA(string sobaodanh, string hoten, string diachi, int uutien) : ThiSinh(sobaodanh, hoten, diachi, uutien) {}

    void nhap(){
        ThiSinh::nhap();
        cout << "Mon thi: Toan, Ly, Hoa\n";
    }

    void xuat(){
        ThiSinh::xuat();
        cout << "Mon thi: Toan, Ly, Hoa\n";
    }
};

// Thí sinh thi khối B
class ThiSinhKhoiB : public ThiSinh {
public:
    ThiSinhKhoiB() : ThiSinh() {}
    ThiSinhKhoiB(string sobaodanh, string hoten, string diachi, int uutien) : ThiSinh(sobaodanh, hoten, diachi, uutien) {}

    void nhap(){
        ThiSinh::nhap();
        cout << "Mon thi: Toan, Hoa, Sinh\n";
    }

    void xuat(){
        ThiSinh::xuat();
        cout << "Mon thi: Toan, Hoa, Sinh\n";
    }
};

// Thí sinh thi khối C
class ThiSinhKhoiC : public ThiSinh {
public:
    ThiSinhKhoiC() : ThiSinh() {}
    ThiSinhKhoiC(string sobaodanh, string hoten, string diachi, int uutien) : ThiSinh(sobaodanh, hoten, diachi, uutien) {}

    void nhap(){
        ThiSinh::nhap();
        cout << "Mon thi: Van, Su, Dia\n";
    }

    void xuat(){
        ThiSinh::xuat();
        cout << "Mon thi: Van, Su, Dia\n";
    }
};

class Tuyensinh{
    private:
        vector<ThiSinh*> dsThiSinh;
    public:

    // Hàm nhập thông tin thi sinh
        void Nhapthongtin(){
            int n;
            cout << "Nhap so luong thi sinh: ";
            cin >> n;

            for(int i = 0; i < n; i++){
                int loai;
                ThiSinh* ts;
                cout << "Nhap khoi (1: Khoi A, 2: Khoi B, 3: Khoi C) = ";
                cin >> loai;

                if(loai == 1){
                    ts = new ThiSinhKhoiA(); //ts trỏ vào lớp con ThiSinhKhoiA
                    dsThiSinh.push_back(ts);
                }
                else if(loai == 2){
                    ts = new ThiSinhKhoiB();
                    dsThiSinh.push_back(ts);
                }
                else if(loai == 3){
                    ts = new ThiSinhKhoiC();
                    dsThiSinh.push_back(ts);
                }

                ts->nhap();
                cout << endl;
            }
        }


    // Hàm xuất thông tin sinh viên
        void Xuatthongtin(){
            for(int i = 0; i < dsThiSinh.size(); i++){
                dsThiSinh[i]->xuat();
                cout << endl;
            }
        }

    // Hàm tìm kiếm thí sinh theo số báo danh
        void Timkiem(string sbd){
            for(int i = 0; i < dsThiSinh.size(); i++){
                if(dsThiSinh[i]->getSobaodanh() == sbd){
                    dsThiSinh[i]->xuat();
                }
            }
        }
};

int main() {
    Tuyensinh ts;
    int chon;
    do {
        cout << "\n=========MENU==========" << endl;
        cout << "1. Nhap thong tin thi sinh." << endl;
        cout << "2. In danh sach thi sinh." << endl;
        cout << "3. Tim kiem thi sinh theo so bao danh." << endl;
        cout << "4. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();
        switch (chon) {
            case 1:
                ts.Nhapthongtin();
                break;
            case 2:
                ts.Xuatthongtin();
                break;
            case 3: {
                string sbd;
                cout << "Nhap so bao danh can tim: ";
                getline(cin, sbd);
                ts.Timkiem(sbd);
                break;
            }
            case 4:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "\nLua chon khong hop le!" << endl;
        }
    } while (chon != 4);

    return 0;
}