//Sap xep bang cach nap chong toan tu
#include <bits/stdc++.h>
using namespace std;
class Sinhvien{
	private:
		string id, ten, ns;
		float gpa;
	public:
		friend istream& operator >> (istream &in, Sinhvien &a);
		friend ostream& operator << (ostream &out, Sinhvien a);
		friend bool operator < (Sinhvien a, Sinhvien b);
};

istream& operator >> (istream &in, Sinhvien &a){
	cout << "Nhap ID: ";
	in >> a.id;
	cout << "Nhap ten: ";
	in.ignore();
	getline(in, a.ten);
	cout << "Nhap ngay sinh: ";
	in >> a.ns;
	cout << "Nhap diem: ";
	in >> a.gpa;
	return in;
}

ostream& operator << (ostream &out, Sinhvien a){
	out << a.id << " " << a.ten << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
	return out;
}

bool operator < (Sinhvien a, Sinhvien b){
	return a.gpa > b.gpa;
}

int main(){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	Sinhvien a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
    cout << "\nDanh sach sinh vien giam dan la: " << endl;
	for(Sinhvien x : a){
		cout << x;
	}
	return 0;
}




