#include <bits/stdc++.h>
using namespace std;
class Hoso{
    private:
        string ma, hodem, ten;
    public:
        Hoso(){
            ma = hodem = ten = "";
        }

        Hoso(string ma, string hodem, string ten){
            this->ma = ma;
            this->hodem = hodem;
            this->ten = ten;
        }

        void nhap(){
            cout << "Nhap ma hoc sinh: ";
            cin >> ma;
            cout << "Nhap ho dem: ";
            cin >> hodem;
            cout << "Nhap ten: ";
            cin >> ten;
        }

        void in(){
            cout << ma << " " << hodem << " " << ten << " ";
        }
};

class Diem : public Hoso{
    private:
        float dlt, dth;
    public:
        Diem(){
            dlt = dth = 0;
        }

        Diem(string ma, string hodem, string ten, float dlt, float dth) : Hoso(ma, hodem, ten){
            this->dlt = dlt;
            this->dth = dth;
        }

        float getdlt(){
            return dlt;
        }

        float getdth(){
            return dth;
        }

        void nhap(){
            Hoso :: nhap();
            cout << "Nhap diem ly thuyet: ";
            cin >> dlt;
            cout << "Nhap diem thuc hanh: ";
            cin >> dth;
        }

        void in(){
            Hoso :: in();
            cout << dlt << " " << dth << endl;
        }
};

class Ketqua : public Diem{
    public:
        Ketqua(){}

        Ketqua(string ma, string hodem, string ten, float dlt, float dth)
        : Diem(ma, hodem, ten, dlt, dth) {}

        void in(){
            Diem :: in();
        }
};

int main(){
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    Ketqua a[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }
    cout << "\nSinh vien thi Do la: " << endl;
    for(int i = 0; i < n; i++){
        if(a[i].getdlt() >= 5 && a[i].getdth() >= 5){
            a[i].in();
        }
    }
    return 0;
}