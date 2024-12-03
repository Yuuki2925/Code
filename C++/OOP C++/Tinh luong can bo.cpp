#include <bits/stdc++.h>
using namespace std;
class Canbo{
    private:
        string macb, madv, ht;
        int ns;
    public:
        Canbo(){
            macb = madv = ht = "";
            ns = 0;
        }

        Canbo(string macb, string madv, string ht, int ns){
            this->macb = macb;
            this->madv = madv;
            this->ht = ht;
            this->ns = ns;
        }

        void nhap(){
            cout << "Nhap ma can bo: ";
            cin >> macb;
            cout << "Nhap ma don vi: ";
            cin >> madv;
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, ht);
            cout << "Nhap nam sinh: ";
            cin >> ns;
        }

        void in(){
            cout << macb << " " << madv << " " << ht << " " << ns << " ";
        }
};

class Luong : public Canbo{
    private:
        double phucap, hsl, baohiem;
    public:
        Luong(){
            phucap = hsl = baohiem = 0;
        }

        Luong(string macb, string madv, string ht, int ns, double phucap, double hsl, double baohiem) : Canbo(macb, madv, ht, ns){
            this->phucap = phucap;
            this->hsl = hsl;
            this->baohiem = baohiem;
        }
        
        double Tinhluong(){
            return hsl * 290000 + phucap - baohiem;
        }

        void nhap(){
            Canbo :: nhap();
            cout << "Nhap phu cap: ";
            cin >> phucap;
            cout << "Nhap he so luong: ";
            cin >> hsl;
            cout << "Nhap bao hiem: ";
            cin >> baohiem;
        }

        void in(){
            Canbo :: in();
            cout << phucap << " " << hsl << " " << baohiem  << " " << Tinhluong() << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong can bo: ";
    cin >> n;
    Luong a[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }

    for(int i = 0; i < n; i++){
        a[i].in();
    }
    return 0;
}