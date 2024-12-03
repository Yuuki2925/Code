#include <bits/stdc++.h>
using namespace std;
class Doanhnghiep{
    private:
        string madn, tendn;
        int sv;
    public:
        Doanhnghiep(){
            madn = tendn = {};
            sv = 0;
        }
        Doanhnghiep(string madn, string tendn, int sv){
            this->madn = madn;
            this->tendn = tendn;
            this->sv = sv;
        }

        friend istream& operator >> (istream &in, Doanhnghiep &a);
        friend ostream& operator << (ostream &out, Doanhnghiep a);
        friend bool operator < (Doanhnghiep a, Doanhnghiep b);
};

istream& operator >> (istream &in, Doanhnghiep &a){
    cout << "Nhap ma doanh nghiep: ";
    in >> a.madn;
    in.ignore();
    cout << "Nhap ten doanh nghiep: ";
    getline(in, a.tendn);
    cout << "Nhap so sinh vien co the nhan: ";
    in >> a.sv;
    return in;
}

ostream& operator <<(ostream &out, Doanhnghiep a){
    out << a.madn << " " << a.tendn << " " << a.sv << endl;
    return out; 
}

bool operator < (Doanhnghiep a, Doanhnghiep b){
    return a.sv > b.sv;
}
int main(){
    int n;
    cin >> n;
    Doanhnghiep a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(Doanhnghiep x : a){
        cout << x;
    }
    return 0;
}