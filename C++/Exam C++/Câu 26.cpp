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
                cout << " + " << pao << "i";
            }
        }

        double modulesp(){
            return sqrt(pthuc * pthuc + pao * pao);
        }
};

class SP2 : public SP1{
    public:
        SP2(){}
        SP2(int pthuc, int pao) : SP1(pthuc, pao){}

        SP2 operator = (SP2 a){
            pthuc = a.pthuc;
            pao = a.pao;
            return *this;
        }

        bool operator > (SP2 a){
            return modulesp() > a.modulesp();
        }

        bool operator == (SP2 a){
            return pthuc == a.pthuc && pao == a.pao;
        }
};

int main(){
    int n;
    do{
        cout << "Nhap so luong so phuc (Toi da 10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    SP2 sp[10];
    for(int i = 0; i < n; i++){
        sp[i].nhap();
    }

    SP2 max = sp[0];
    for(int i = 0; i < n; i++){
        if(sp[i] > max){
            max = sp[i];
        }
    }
    cout << "Gia tri lon nhat la: ";
    max.xuat();
    cout << endl;\

    int cnt = 0;
    SP2 a(3,4);
    for(int i = 0; i < n; i++){
        if(sp[i] == a){
            cnt++;
        }
    }

    cout << "So phuc 3 + 4i co so lan xuat hien la: " << cnt << endl;

    return 0;
}