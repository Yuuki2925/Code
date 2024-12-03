#include <bits/stdc++.h>
using namespace std;
string chuanhoa(string bm){
	string res = "";
	string token;
	stringstream ss(bm);
	while(ss >> token){
		res += toupper(token[0]);
	}
	return res;
}
int cnt = 0;
class Giangvien{
	private:
		string maGv, hoTen, boMon;
	public:
		string getBoMon(){
			return boMon;
		}

		Giangvien(){
			maGv = hoTen = boMon = "";
		}

		Giangvien(string maGv, string hoTen, string boMon){
			this->maGv = maGv;
			this->hoTen = hoTen;
			this->boMon = boMon;
		}

		friend istream& operator >> (istream &in, Giangvien &a);
		friend ostream& operator << (ostream &out, Giangvien a);
};

istream& operator >> (istream &in, Giangvien &a){
	++cnt;
	string tmp = to_string(cnt);
	if(tmp.size() < 2){
		tmp = "0" + tmp;
	}
	a.maGv = "GV" + tmp;
	cout << "Nhap ho ten giang vien: ";
	in.ignore();
	getline(in, a.hoTen);
	cout << "Nhap bo mon: ";
	getline(in, a.boMon);
	return in;
}

ostream& operator << (ostream& out, Giangvien a){
	out << a.maGv << " " << a.hoTen << " " << chuanhoa(a.getBoMon()) << endl;
	return out;
}

int main(){
	int n;
	cout << "Nhap so luong giang vien: ";
	cin >> n;
	Giangvien a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int q;
	cout << "Nhap so lan tim kiem: ";
	cin >> q;
	while(q--){					//Lap q lan cho den khi q ve 0 thi ket thuc vong lap
		string s;
		cout << "Nhap bo mon muon tim kiem: ";
		cin.ignore();
		getline(cin, s);
		cout << "DANH SACH GIANG VIEN THEO BO MON: " << s << endl;
		for(int i = 0; i < n; i++){
			if(chuanhoa(s) == chuanhoa(a[i].getBoMon())){
				cout << a[i];
			}
		}
	}
	return 0;
}
