#include <bits/stdc++.h>
using namespace std;

class TinhNgay {
    private:
        int ngay, thang, nam;

    public:
        // constructor khong doi
        TinhNgay() {
            ngay = thang = nam = 0;
        }

        // Constructor co doi
        TinhNgay(int ngay, int thang, int nam) {
            this->ngay = ngay;
            this->thang = thang;
            this->nam = nam;
        }

        // Nhap
        void nhap() {
            cout << "Nhap ngay: ";
            cin >> ngay;
            cout << "Nhap thang: ";
            cin >> thang;
            cout << "Nhap nam: ";
            cin >> nam;
        }

        // Nam Nhuan
        bool checkNamNhuan(int nam) {
            return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
        }

        // So ngay trong 1 thang
        int ngayTrongThang(int thang, int nam) {
            if (thang == 2) {
                return checkNamNhuan(nam) ? 29 : 28;
            }
            if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
                return 30;
            }
            return 31;
        }

        // Cong them ngay
        void congThemNgay(int soNgay) {
            ngay += soNgay;
            while (ngay > ngayTrongThang(thang, nam)) {
                ngay -= ngayTrongThang(thang, nam);
                thang++;
                if (thang > 12) {
                    thang = 1;
                    nam++;
                }
            }
        }

        void Ngaymoi() {
            cout << "Ngay moi: " << ngay << "/" << thang << "/" << nam << endl;
        }
};

int main() {
    int ngay, thang, nam, soNgay;

    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;

    cout << "Nhap so ngay muon cong them: ";
    cin >> soNgay;

    TinhNgay a(ngay, thang, nam);
    a.congThemNgay(soNgay);
    a.Ngaymoi();

    return 0;
}
