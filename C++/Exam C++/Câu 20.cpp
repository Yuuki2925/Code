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
            else if (pao > 0){
                cout << " + " << pao << "i";
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

        bool operator > (SP2 a){
            return modulesp() > a.modulesp();
        }
};

int main(){
    int n;
    do{
        cout << "Nhap so luong so phuc (Toi da 10): ";
        cin >> n;
    }
    while(n < 1 || n > 10);
    SP2 sp[10];

    for(int i = 0; i < n; i++){
        sp[i].nhap();
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(sp[j].modulesp() > sp[i].modulesp()){
                SP2 tmp = sp[i];
                sp[i] = sp[j];
                sp[j] = tmp;
            }
        }
    }

    cout << "Sap xep so phuc theo module giam dan la: " << endl;
    for(int i = 0; i < n; i++){
        sp[i].xuat();
        cout << endl;
    }
    return 0;
}