#include <bits/stdc++.h>
using namespace std;

string chuan(string name){

    //Tách từ 
    stringstream ss(name);
    string res = "";
    string token;

    while(ss >> token){
        // Viết hoa chữ cái đầu tiên rồi cộng chữ cái đầu tiên vào res
        res += toupper(token[0]);
        //Duyệt từ chữ cái thứ 2 của từ đó cho đến hết từ đó
        for(int i = 1; i < token.length(); i++){
            // Chuyển từ chữ cái thứ 2 của từ đó sang dạng thường
            res += tolower(token[i]);
        }
        // Kết thúc từ in thêm 1 dấu cách để chuẩn hóa từ tiếp theo
        res += " ";
    }
    // Sau khi tách xong sẽ thừa dấu cách ở cuối nên xóa nó đi
    res.erase(res.length() - 1);
    return res;
}
int cnt = 0;
class Sinhvien{
    private:
        string ma, ten, lop, ns;
        float gpa;
    public:
        Sinhvien(){
            ma = ten = lop = ns = "";
            gpa = 0;
        }

        friend istream& operator >> (istream &in, Sinhvien &a);
        friend ostream& operator << (ostream &out, Sinhvien &a);
        friend bool operator < (Sinhvien a, Sinhvien b);
};

istream& operator >> (istream &in, Sinhvien &a){
    ++cnt;
    string tmp = to_string(cnt);
    tmp = string(3 - tmp.size(), '0') + tmp;
    a.ma = "B20DCNN" + tmp;
    in.ignore();
    cout << "Nhap ten sv: ";
    getline(in, a.ten);
    a.ten = chuan(a.ten);
    cout << "Nhap lop sv: ";
    in >> a.lop;
    cout << "Nhap GPA sv: ";
    in >> a.gpa;
    cout << "Nhap ngay sinh sv: ";
    in >> a.ns;
    if(a.ns[2] != '/'){
    a.ns = "0" + a.ns;
    }
    if(a.ns[5] != '/'){
        a.ns.insert(3, "0");
    }
        return in;
}

ostream& operator << (ostream &out, Sinhvien &a){
    out << a.ma << " " << a.ten << " " << a.lop << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
        return out;
}
//Ham sap xep GPA giam dan
bool operator < (Sinhvien a, Sinhvien b){
    return a.gpa > b.gpa;
}
int main(){
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    Sinhvien ds[n];
    for(int i = 0; i < n; i++){
        cin >> ds[i];
    }
    sort(ds, ds + n);
    for (int i = 0; i < n; i++) {
        cout << ds[i];
    }
    return 0;
}