#include <bits/stdc++.h>
using namespace std;

string chuan(string bm){
    string res = "";
    stringstream hh(bm);
    string token;
    while (hh >> token){
        res += toupper(token[0]);
    }
    return res;
}
int cnt = 0;
class Giangvien{
    private:
        string ma, ten, bm;
    public:
        Giangvien(){
            ma = ten = bm = "";
        }
        string getbm(){
            return bm;
        }
        friend istream& operator >> (istream &in, Giangvien &a);
        friend ostream& operator << (ostream &out, Giangvien a);
        friend bool operator < (Giangvien a, Giangvien b);
};

istream& operator >> (istream &in, Giangvien &a){
    ++cnt;
    string cxau = to_string(cnt);
    if(cxau.length() < 2){
        cxau = "0" + cxau;
    }
    a.ma = "GV" + cxau;
    in.ignore();
    cout << "Nhap ten: ";
    getline(in, a.ten);
    cout << "Nhap bo mon: ";
    getline(in, a.bm);
    return in;
}

ostream& operator << (ostream &out, Giangvien a){
    out << a.ma << " " << a.ten << " " << chuan(a.getbm()) << endl;
    return out;
}

bool operator < (Giangvien a, Giangvien b){
    if(a.ten != b.ten){
        return a.ten < b.ten;
    }
    else{
        return a.ma < b.ma;
    }
}

int main(){
    int n;
    cout << "Nhap so giang vien: ";
    cin >> n;
    Giangvien a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}