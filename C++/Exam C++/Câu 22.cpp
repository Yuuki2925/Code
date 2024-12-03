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
            if(pao < 0){
                cout << " " << pao << "i";
            }
            else if(pao > 0){
                cout  << " + " << pao << "i";
            }
        }

        double modulesp(){
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
};

int main(){
    int n;
    do{
        cout << "Nhap so luong phan tu (Toi da 10): ";
        cin >> n;
    }
    while(n < 1 || n > 10);

    SP2 sp[10];

    for(int i = 0; i < n; i++){
        sp[i].nhap();
    }

    SP2 max = sp[0];
    SP2 min = sp[0];

    for(int i = 1; i < n; i++){
        if(sp[i] < min){
            min = sp[i];
        }
        else if(max < sp[i]){
            max = sp[i];
        }
    }

    cout << "So phuc lon nhat la: ";
    max.xuat();
    cout << endl;
    cout << "So phuc be nhat la: ";
    min.xuat();
    cout << endl;
    return 0;
}