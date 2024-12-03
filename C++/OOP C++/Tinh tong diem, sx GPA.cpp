#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SinhVien {
private:
    string maSV;
    string hoTen;
    float diemToan, diemLy, diemHoa;
    float tongDiem;

public:
    SinhVien();
    SinhVien(string ma, string ten, float toan, float ly, float hoa);
    SinhVien(const SinhVien &sv);
    ~SinhVien();
    void nhap();
    void tinhTongDiem();
    void hienThi();
    float getTongDiem();
};


SinhVien::SinhVien(){
    maSV = " ";
    hoTen = " ";
    diemToan = 0;
    diemLy = 0;
    diemHoa = 0;
    tongDiem = 0;
}


SinhVien::SinhVien(string ma, string ten, float toan, float ly, float hoa){
    maSV = ma;
    hoTen = ten;
    diemToan = toan;
    diemLy = ly;
    diemHoa = hoa;
}


SinhVien::SinhVien(const SinhVien &sv){
	maSV = sv.maSV;
	hoTen = sv.hoTen;
	diemToan = sv.diemToan;
    diemLy = sv.diemLy;
	diemHoa = sv.diemHoa;
	tongDiem = sv.tongDiem;
}

SinhVien::~SinhVien() {}


void SinhVien::nhap() {
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap diem Toan: ";
    cin >> diemToan;
    cout << "Nhap diem Ly: ";
    cin >> diemLy;
    cout << "Nhap diem Hoa: ";
    cin >> diemHoa;
    tinhTongDiem();
}


void SinhVien::tinhTongDiem() {
    tongDiem = diemToan + diemLy + diemHoa;
}


void SinhVien::hienThi() {
    cout << "Ma SV: " << maSV << ", Ho ten: " << hoTen << ", Toan: " << diemToan << ", Ly: " << diemLy 
         << ", Hoa: " << diemHoa << ", Tong diem: " << tongDiem << endl;
}


float SinhVien::getTongDiem() {
    return tongDiem;
}


bool compareByTongDiem(SinhVien &sv1, SinhVien &sv2) {
    return sv1.getTongDiem() > sv2.getTongDiem();
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<SinhVien> danhSachSV(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        danhSachSV[i].nhap();
    }
    
    sort(danhSachSV.begin(), danhSachSV.end(), compareByTongDiem);
    cout << "\nDanh sach sinh vien sau khi sap xep theo tong diem giam dan:\n";
    for (int i = 0; i < n; ++i) {
        danhSachSV[i].hienThi();
    }
    return 0;
}
