#include <bits/stdc++.h>
using namespace std;

class KhachHang {
private:
    string maKH, hoTen, ngayHD;
    float soLuong, donGia;

public:
    // Constructor không đối và có đối
    KhachHang() {
        maKH = hoTen = ngayHD = "";
        soLuong = donGia = 0;
    }

    KhachHang(string maKH, string hoTen, string ngayHD, float soLuong, float donGia) {
        this->maKH = maKH;
        this->hoTen = hoTen;
        this->ngayHD = ngayHD;
        this->soLuong = soLuong;
        this->donGia = donGia;
    }

    // Getter
    string getMaKh(){ 
        return maKH; 
    }
    string getHoTen(){ 
        return hoTen; 
    }
    string getNgayHD(){ 
        return ngayHD; 
    }
    float getSoLuong(){ 
        return soLuong; 
    }
    float getDonGia(){ 
        return donGia; 
    }

    // Hàm nhập, xuất
    void xuat() {
        cout << maKH << " " << hoTen << " " << ngayHD << " " << soLuong << " " << donGia << " ";
    }

    void nhap() {
        cout << "Nhap ma khach hang: ";
        cin.ignore(); // Xử lý trôi lệnh khi nhập số trước đó
        cin >> maKH;
        cin.ignore(); // Xử lý trôi lệnh sau khi nhập mã khách hàng
        cout << "Nhap ho ten: ";
        getline(cin, hoTen); // Sử dụng getline để nhập họ tên
        cout << "Nhap ngay ra hoa don: ";
        cin >> ngayHD;
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }
};

class KhachHangVietNam : public KhachHang {
private:
    string doituongKH;
    double dinhMuc;

public:
    // Constructor không đối và có đối
    KhachHangVietNam() {
        doituongKH = "";
        dinhMuc = 0;
    }

    KhachHangVietNam(string maKH, string hoTen, string ngayHD, float soLuong, float donGia, string doituongKH, double dinhMuc)
        : KhachHang(maKH, hoTen, ngayHD, soLuong, donGia) {
        this->doituongKH = doituongKH;
        this->dinhMuc = dinhMuc;
    }

    // Hàm nhập, xuất
    void nhap() {
        KhachHang::nhap();
        cout << "Nhap doi tuong khach hang (Sinh hoat / Kinh doanh / San xuat): ";
        cin.ignore(); // Xử lý trôi lệnh trước khi nhập đối tượng khách hàng
        getline(cin, doituongKH); // Sử dụng getline để nhập đối tượng khách hàng
        cout << "Nhap dinh muc: ";
        cin >> dinhMuc;
    }

    void xuat() {
        KhachHang::xuat();
        cout << doituongKH << " " << dinhMuc << endl;
    }

    // Hàm tính tiền cho khách hàng Việt Nam
    double thanhTienVN() {
        if (getSoLuong() <= dinhMuc) {
            return getSoLuong() * getDonGia();
        } else {
            return dinhMuc * getDonGia() + (getSoLuong() - dinhMuc) * getDonGia() * 2.5;
        }
    }
};

class KhachHangNuocNgoai : public KhachHang {
private:
    string quocTich;

public:
    // Constructor không đối và có đối
    KhachHangNuocNgoai() {
        quocTich = "";
    }

    KhachHangNuocNgoai(string maKH, string hoTen, string ngayHD, float soLuong, float donGia, string quocTich)
        : KhachHang(maKH, hoTen, ngayHD, soLuong, donGia) {
        this->quocTich = quocTich;
    }

    // Hàm nhập, xuất
    void nhap() {
        KhachHang::nhap();
        cout << "Nhap quoc tich: ";
        cin.ignore(); // Xử lý trôi lệnh trước khi nhập quốc tịch
        getline(cin, quocTich); // Sử dụng getline để nhập quốc tịch
    }

    void xuat() {
        KhachHang::xuat();
        cout << quocTich << endl;
    }

    // Hàm tính tiền cho khách hàng nước ngoài
    double thanhTienNN() {
        return getSoLuong() * getDonGia();
    }
};

int main() {
    int lc, n;
    vector<KhachHangVietNam> khachVN;
    vector<KhachHangNuocNgoai> khachNN;
    cout << "Nhap so luong khach hang: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap loai khach hang: " << endl;
        cout << "1: Khach hang Viet Nam" << endl;
        cout << "2: Khach hang nuoc ngoai\n" << endl;
        cout << "Lua chon: ";
        cin >> lc;
        if (lc == 1) {
            KhachHangVietNam a;
            a.nhap();
            khachVN.push_back(a);
        } else if (lc == 2) {
            KhachHangNuocNgoai b;
            b.nhap();
            khachNN.push_back(b);
        }
    }

    double tongSoluongVn = 0, tongSoluongNN = 0, tongTienNN = 0;

    for (auto &a : khachVN) {
        a.xuat();
        tongSoluongVn += a.getSoLuong();
    }

    for (auto &b : khachNN) {
        b.xuat();
        tongSoluongNN += b.getSoLuong();
        tongTienNN += b.thanhTienNN();
    }

    cout << "Tong so luong dien tieu thu cua khach VN: " << tongSoluongVn << endl;
    cout << "Tong so luong dien tieu thu cua khach NN: " << tongSoluongNN << endl;

    int khachHangNN = khachNN.size();
    if (khachHangNN > 0) {
        cout << "Trung binh thanh tien cua khach NN: " << tongTienNN / khachHangNN << endl;
    }
    
    return 0;
}
