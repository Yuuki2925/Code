#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    while(b != 0){
        int x = a % b;
        a = b;
        b = x;
    }
    return a;
}
class PS1{
    protected:
        int ts, ms;
    public:
        void nhap(){
            cout << "Nhap tu so: ";
            cin >> ts;
            do{
                cout << "Nhap mau so: ";
                cin >> ms;
                if(ms == 0){
                    cout << "Vui long nhap mau so khac 0";
                }
            }
            while(ms == 0);
        }

        void xuat(){
            cout << ts << "/" << ms;
        }

        void toigian(){
            int ucln = gcd(abs(ts), abs(ms));
            ts /= ucln;
            ms /= ucln;
            if(ms < 0){
                ts = -ts;
                ms = -ms;
            }
        }
};

class PS2 : public PS1{
    public:
         PS2 operator = (PS2 a){
            ts = a.ts;
            ms = a.ms;
            return *this;
         }

         bool operator < (PS2 a){
            return ts * a.ms < a.ts * ms;
         }
};

int main(){
    PS2 ps[10];
    int n;
    do{
        cout << "Nhap so luong phan so (Toi da 10): ";
        cin >> n;
    }
    while(n < 1 || n > 10);

    for(int i = 0; i < n; i++){
        ps[i].nhap();
        ps[i].toigian();
    }

    PS2 max = ps[0];
    PS2 min = ps[0];
    for(int i = 1; i < n; i++){
        if(max < ps[i]){
            max = ps[i];
        }
        else if(ps[i] < min){
            min = ps[i];
        }
    }

    cout << "Phan so lon nhat la: ";
    max.xuat();
    cout << endl;
    cout << "Phan so be nhat la: ";
    min.xuat();
    cout << endl;
    return 0;
}