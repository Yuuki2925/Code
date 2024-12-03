#include <bits/stdc++.h>
using namespace std;

class Sinhvien{
    protected:
        string masv, ht, ns, gt;

    public:

        Sinhvien(){
            masv = ht = ns = gt = "";
        }

        Sinhvien(string masv, string ht, string ns, string gt){
            this->masv = masv;
            this->ht = ht;
            this->ns = ns;
            this->gt = gt;
        }

        void nhap(){
            cout << "Nhap ma sinh vien: ";
            cin >> masv;
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, ht);
            cout << "Nhap ngay sinh: ";
            cin >> ns;
            cout << "Nhap gioi tinh: ";
            cin >> gt;
        }

        void xuat(){
            cout << "Ma sinh vien: " << masv << endl
                 << "Ho va ten: " << ht << endl
                 << "Ngay sinh: " << ns << endl
                 << "Gioi tinh: " << gt << endl;
        }
};

class Hocphan{
    protected:
        string tenhp;
        float cc, kttx, diembtl, diemthi;

    public:

        Hocphan(){
            tenhp = "";
            cc = kttx = diembtl = diemthi = 0;
        }

        Hocphan(string tenhp, float cc, float kttx, float diembtl, float diemthi){
            this->tenhp = tenhp;
            this->cc = cc;
            this->kttx = kttx;
            this->diembtl = diembtl;
            this->diemthi = diemthi;
        }

        void nhap(){
            cin.ignore();
            cout << "Nhap ten hoc phan: ";
            getline(cin, tenhp);
            cout << "Nhap diem chuyen can: ";
            cin >> cc;
            cout << "Nhap diem kiem tra thuong xuyen: ";
            cin >> kttx;
            cout << "Nhap diem bai tap lon: ";
            cin >> diembtl;
            cout << "Nhap diem thi: ";
            cin >> diemthi;
        }

        void xuat(){
            cout << "Ten hoc phan: " << tenhp << endl
                 << "Diem chuyen can: " << cc << endl
                 << "Diem kiem tra thuong xuyen: " << kttx << endl
                 << "Diem bai tap lon: " << diembtl << endl
                 << "Diem thi: " << diemthi << endl;
        }
};

class Ketqua : public Sinhvien, public Hocphan{
    private:
        float dtb;
    
    public:

        Ketqua() : Sinhvien(), Hocphan() {
            dtb = 0;
        }

        Ketqua(string masv, string ht, string ns, string gt, string tenhp, float cc, float kttx, float diembtl, float diemthi): Sinhvien(masv, ht, ns, gt), Hocphan(tenhp, cc, kttx, diembtl, diemthi) {
            this->dtb = dtb;
        }

        float getDTB(){
            return dtb;
        }

        float tinhDTB(){
            return (cc + 2*kttx + 2*diembtl + 5*diemthi) / 10;
        }

        void nhap(){
            Sinhvien :: nhap();
            Hocphan :: nhap();
            dtb = tinhDTB();
        }

        void xuat(){
            Sinhvien :: xuat();
            cout << "Diem trung binh: " << dtb << endl << endl;
        }
};

int main(){
    vector<Ketqua> dsSinhvien;
    int chon;
    do{
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Hien danh sach sinh vien\n";
        cout << "3. In sinh vien co diem trung binh >= 8.0\n";
        cout << "4. Thoat\n";
        cout << "\nNhap lua chon: ";
        cin >> chon;
        cout << endl;
        switch(chon){
            case 1:
                int n;
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                for(int i = 0; i < n; i++){
                    cout << "Sinh vien thu " << i + 1 << endl;
                    Ketqua kq;
                    kq.nhap();
                    dsSinhvien.push_back(kq);
                }
                break;
            case 2:
                for(int i = 0; i < dsSinhvien.size(); i++){
                    dsSinhvien[i].xuat();
                    cout << endl;
                }
                break;
            case 3:
                for(int i = 0; i < dsSinhvien.size(); i++){
                    if(dsSinhvien[i].getDTB() >= 8){
                        dsSinhvien[i].xuat();
                    }
                }
                break;
            case 4:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }
    while (chon != 4);
    return 0;
}