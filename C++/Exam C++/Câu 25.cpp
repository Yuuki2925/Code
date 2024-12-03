#include <bits/stdc++.h>
using namespace std;
class SP1{
    protected:
        int pthuc, pao;
    public:
        SP1(){
            pthuc = pao = 0;
        }

        SP1(int pt, int pa){
            pthuc = pt;
            pao = pa;
        }

        void nhap(){
            cout << "Nhap phan thuc: ";
            cin >> pthuc;
            cout << "Nhap phan ao: ";
            cin >> pao;
        }

        void xuat(){
            cout << pthuc;
            if(pao > 0){
                cout << " + " << pao << "i" << endl;
            }
            else{
                cout << " " << pao << "i" << endl;
            }
        }

        float modulesp(){
            return sqrt(pthuc * pthuc + pao * pao);
        }
};

class SP2 : public SP1{
    public:
        SP2 operator = (SP2 a){
            pthuc = a.pthuc;
            pao = a.pao;
            return *this;
        }

        bool operator < (SP2 a){
            return modulesp() < a.modulesp();
        }

        SP2 operator + (SP2 a){
            SP2 kq;
            kq.pthuc = pthuc + a.pthuc;
            kq.pao = pao + a.pao;
            return kq;
        }
};

int main(){
    int n;
    do{
        cout << "Nhap so luong so phuc (toi da 10 phan tu): ";
        cin >> n;
    }
    while(n < 1 || n > 10);
    SP2 a[10];

    for(int i = 0; i < n; i++){
        cout << "So phuc thu: " << i + 1 << endl;
        a[i].nhap();
    }

    SP2 min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].modulesp() < min.modulesp()) {
            min = a[i];
        }
    }


    SP2 tong;
    for(int i = 0; i < n; i++){
        tong = tong + a[i];
    }

    cout << "So phuc co module nho nhat la: ";
    min.xuat();
    cout << endl;

    cout << "Tong cua day so phuc vua nhap la: ";
    tong.xuat();
    cout << endl;
    return 0;
}